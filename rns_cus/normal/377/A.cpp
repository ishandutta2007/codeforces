#include<bits/stdc++.h>
using namespace std;

#define N 2020

char s[N][N];

int vis[N][N], a[1000100], b[1000100], curx, cury, dtime;

const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};

int n, m, q;

void dfs(int x, int y){
	vis[x][y] = 1;
	for(int k = 0; k < 4; k ++){
		int xx = x + dx[k], yy = y + dy[k];
		if(vis[xx][yy] == 1) continue;
		if(s[xx][yy] == '.') dfs(xx, yy);
	}
	a[dtime] = x, b[dtime] = y; dtime ++;
}

int main(){
	//freopen("in.txt", "r", stdin);
	scanf("%d %d %d", &n, &m, &q);

	for(int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);

	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++) if(s[i][j] == '.'){
			curx = i, cury = j; break;
		}
		if(curx) break;
	}

	dfs(curx, cury);

//	cout << dtime << endl;

	for(int i = 0; i < q; i ++) s[a[i]][b[i]] = 'X';

	for(int i = 1; i <= n; i ++) puts(s[i] + 1);
}