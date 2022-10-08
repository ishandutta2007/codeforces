#include <bits/stdc++.h>

using namespace std;
const int maxn=500;

bool board[maxn][maxn];
int cont[maxn][maxn][4];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int h, w; cin>>h>>w;
	int ysFilled=0, minX=w, maxX=0;
	int xsFilled=0;
	int total=0;
	for (int y=0; y<h; y++) {
		string line; cin>>line;
		for (int i=0; i<w; i++) {
			board[i][y]=line[i]=='*';
			if (board[i][y])
				total++;
		}
	}
	//from: left, up, down, right
	for (int x=0; x<w; x++) {
		for (int y=0; y<h; y++) {
			if (x==0) cont[x][y][0]=1;
			else cont[x][y][0]=cont[x-1][y][0]+1;

			if (y==0) cont[x][y][1]=1;
			else cont[x][y][1]=cont[x][y-1][1]+1;

			if (!board[x][y])
				cont[x][y][0]=cont[x][y][1]=0;
		}
	}
	for (int x=w-1; x>=0; x--) {
		for (int y=h-1; y>=0; y--) {
			if (x==w-1) cont[x][y][2]=1;
			else cont[x][y][2]=cont[x+1][y][2]+1;

			if (y==h-1) cont[x][y][3]=1;
			else cont[x][y][3]=cont[x][y+1][3]+1;

			if (!board[x][y])
				cont[x][y][2]=cont[x][y][3]=0;
		}
	}
	bool possible=false;
	for (int x=0; x<w; x++) {
		for (int y=0; y<h; y++) {
			int cur=1;
			bool works=true;
			//cout<<board[x][y]<<endl;
			if (!board[x][y]) continue;
			for (int d=0; d<4; d++) {
				//cout<<x<<" "<<y<<" "<<d<<" "<<cont[x][y][d]<<endl;
				cur+=cont[x][y][d]-1;
				if (cont[x][y][d]<=1) works=false;
			}
			//cout<<cur<<" "<<total<<" "<<"works: "<<works<<endl;
			if (!works) continue;
			if (cur!=total) continue;
			possible=true;
		}
	}
	cout<<(possible?"YES\n":"NO\n");


	return 0;
}