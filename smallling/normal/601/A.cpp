#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n,m,u,v,f[440][440],g[440][440];

int main()
{
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&u,&v),f[u][v]=f[v][u]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i^j&&f[i][j]==0x3f3f3f3f)g[i][j]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][k]+g[k][j],g[i][j]),
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
	int ans=max(f[1][n],g[1][n]);
	if(ans>1000000)return puts("-1"),0;
	printf("%d\n",ans);
}