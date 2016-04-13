#include <iostream>
#define BOUNDED(x,y) x >= 0 && x < 8 && y >= 0 && y < 8 
#include <stdlib.h>

using namespace std;

int chessboard[8][8];

void printboard() {
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (chessboard[i][j]==0 || chessboard[i][j]==-1)
			{
				cout<<"0 ";
			}
			else
				cout<<"1 ";
		}
		cout<<endl;
	}
}

void placeCoinAt(int i,int j) {
	int k,l;
	chessboard[i][j]=1;
	for(k=0;k<8;k++) if(k!=i) chessboard[k][j] = -1;
	for(l=0;l<8;l++) if(l!=j) chessboard[i][l] = -1;
	for(k=i+1,l=j+1;BOUNDED(k,l);k++,l++) chessboard[k][l] = -1;
	for(k=i+1,l=j-1;BOUNDED(k,l);k++,l--) chessboard[k][l] = -1;
	for(k=i-1,l=j-1;BOUNDED(k,l);k--,l--) chessboard[k][l] = -1;
	for(k=i-1,l=j+1;BOUNDED(k,l);k--,l++) chessboard[k][l] = -1;
}

void removeCoinAt(int i,int j) {
	int k,l;
	chessboard[i][j]=0;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if(chessboard[i][j]==-1)
				chessboard[i][j]=0;
		}
	}
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if(chessboard[i][j]==1)
				placeCoinAt(i,j);
		}
	}
}

void placeCoin(int ncoins) {
	int i,j,k,l;
	int placed[8][8];
	for (int i1 = 0; i1 < 8; ++i1)
		for (int j1 = 0; j1 < 8; ++j1)
			placed[i1][j1]=0;

	if(ncoins) {
		for (i = 0; i < 8; ++i)
		{
			for (j = 0; j < 8; ++j)
			{
				if (chessboard[i][j]==0 && !placed[i][j])
				{
					placeCoinAt(i,j);
					placed[i][j]=1;
					placeCoin(--ncoins);
					ncoins++;
					removeCoinAt(i,j);
				}
			}
		}
	}	
	else {
		printboard();
		exit(0);
	}
}

int main(int argc, char const *argv[])
{
	placeCoin(8);
	return 0;
}