#include <bits/stdc++.h>



#define NN 2222

#define inf 100000000

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



char grid[NN][NN];

int vst[NN][NN], step[NN][NN];

int runs=0;



pii change(char s){

	if(s=='>') return pii(0, 1);

	if(s=='<') return pii(0, -1);

	if(s=='^') return pii(-1, 0);

	if(s=='v') return pii(1, 0);

}



int dfs(int x, int y){

	if(vst[x][y]==runs) return -inf;

	if(step[x][y]) return step[x][y];

	if(grid[x][y]=='#') return 0;

	vst[x][y]=runs;

	pii dir=change(grid[x][y]);

	int xx=dir.first, yy=dir.second;

	

	return step[x][y]=1+dfs(x+xx, y+yy);

}



void DFS(int x, int y){

	if(grid[x][y]=='#') return ;

	vst[x][y]=1;

	pii dir=change(grid[x][y]);

	int xx=dir.first, yy=dir.second;

	DFS(xx+x, yy+y);

}



int dfs1(int x, int y){

	if(grid[x][y]=='#') return 0;

	if(vst[x][y]) return -inf;

	pii dir=change(grid[x][y]);

	int xx=dir.first, yy=dir.second;

	return 1+dfs1(xx+x, yy+y);

}



int main() {

	int n, m,i,j;

	cin>>n>>m;

	

	for(i=0; i<n; i++) scanf("%s", grid[i]);

	

	int mx=0;

	int posx=-1, posy=-1;

	

	for(i=0; i<n; i++){

		for(j=0; j<m; j++){

			if(grid[i][j]=='#') continue;

			runs++;

			int tmp=dfs(i, j);

			if(tmp<0) return puts("-1"), 0;

			if(tmp>mx) mx=tmp, posx=i, posy=j;

		}

	}

	

	memset(vst, 0, sizeof(vst));

	runs=1;

	if(posx==-1) return puts("0"), 0;

	DFS(posx, posy);

	

	int flag=1;

	for(i=0; i<n; i++){

		for(j=0; j<m; j++){

			if(grid[i][j]=='#') continue;

			if(vst[i][j]) continue;

			int t=dfs1(i, j);

			if(t==mx) flag=0;

		}

	}

	cout<<mx*2-flag<<endl;

	return 0;

}