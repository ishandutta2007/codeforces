#include<bits/stdc++.h>

using namespace std;

#define NN 100
int n,m;
int flag;
int u,v;
int vis[NN][NN];
char str[NN][NN];

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

void dfs(int x, int y, int p) {
	if (flag) return;
	for (int i=0; i<4; i++) {
		int xx=x+dx[i], yy=y+dy[i];
		if (xx<0 || yy<0 || xx>n-1 || yy>m-1) continue;
		if (abs(p-i)==2) continue;
		if (str[xx][yy]!=str[x][y]) continue;
		if (vis[xx][yy] ) {flag = 1; break;}
		vis[xx][yy]=1;
		dfs(xx,yy,i);
		if (flag) return;
	}
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	cin>>n>>m;
	for (int i=0; i<n; i++) scanf(" %s", str [i]);
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) 
			if (!vis[i][j]) {
				flag=0;
				vis[i][j] = 1;
				dfs(i,j,-10); 
				if (flag) break;
			}
		if (flag) break;
	}
	if (flag) puts("Yes");
	else puts("No");
	return 0;
}