#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int e[605][605],dis[605][605],p[605][605],ans[605][605];
const int inf=1e9+114514;
int main(int argc, char** argv) {
	int n,m;
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=e[i][j]=(i!=j)*inf;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		dis[u][v]=dis[v][u]=e[u][v]=e[v][u]=min(e[u][v],w);
	}
	int q;
	cin >> q;
	for(int i=1;i<=q;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		p[u][v]=p[v][u]=max(p[u][v],w);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
//	cout << dis[1][3] << "\n";
	for(int v=1;v<=n;v++)
	{
		for(int x=1;x<=n;x++)
		{
			int mx=0;
			for(int u=1;u<=n;u++)
				mx=max(mx,p[u][v]-dis[u][x]);
			for(int y=1;y<=n;y++)
				if(e[x][y]+dis[y][v]<=mx) ans[x][y]=1; 
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)cnt+=ans[i][j];
	cout << cnt/2;
	return 0;
}