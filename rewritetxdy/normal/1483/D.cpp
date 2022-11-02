#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 606;

int n,m,q,c[N][N],f[N][N],w[N][N],vis[N][N],cnt;



int main()
{
	scanf("%d%d",&n,&m);
	int x,y,vv;
	for(int i=1;i <= n;i++) for(int j=1;j <= n;j++) f[i][j] = 1000000010;
	for(int i=1;i <= n;i++) f[i][i] = 0;
	for(int i=1;i <= m;i++) 
		scanf("%d%d%d",&x,&y,&vv) , w[x][y] = w[y][x] = f[x][y] = f[y][x] = vv;// , fa[x][y] = y , fa[y][x] = x;
//	for(int i=1;i <= n;i++) for(int j=n;j >= 1;j--) if(!fa[i][j]) fa[i][j] = fa[i][j+1];
	for(int k=1;k <= n;k++) for(int i=1;i <= n;i++) for(int j=1;j <= n;j++)
		if(f[i][k]+f[k][j] < f[i][j]) f[i][j] = f[i][k]+f[k][j];
	scanf("%d",&q);
	for(int i=1;i <= q;i++)
		scanf("%d%d%d",&x,&y,&vv) , c[x][y] = c[y][x] = vv;
	for(int u=1;u <= n;u++) for(int y=1;y <= n;y++){
		int maxn = -2e9;
		for(int v=1;v <= n;v++) if(c[u][v]) maxn = max(maxn,c[u][v]-f[y][v]);
		for(int x=1;x <= n;x++) if(w[x][y] && f[u][x]+w[x][y] <= maxn) vis[x][y] = 1;
	}
	for(int i=1;i <= n;i++) for(int j=i+1;j <= n;j++) if(vis[i][j]) cnt++;
	printf("%d\n",cnt);
	return 0;
}