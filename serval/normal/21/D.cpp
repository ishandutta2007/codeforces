#include <cstdio>
#include <cstring>
using namespace std;
int n,m,um;
int i,j,k,u,v,w;
int d[16][16];
int ans;
int deg[16],udeg[16];
int f[32768];
int main()
{
	scanf("%d%d",&n,&m);
	um=m;
	memset(d,0x3f,sizeof(d));
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		ans+=w;
		if (u!=v)
		{
			deg[u]++;
			deg[v]++;
		}
		if (u==1&&v==1)
			um--;
		udeg[u]++;
		udeg[v]++;
		if (w<d[u][v])
			d[u][v]=w;
		if (w<d[v][u])
			d[v][u]=w;	
	}
	for (k=1;k<=n;k++)
		for (i=1;i<=n;i++)
			if (i!=k)
				for (j=1;j<=n;j++)
					if (i!=j&&j!=k)
						if (d[i][k]+d[k][j]<d[i][j])
							d[i][j]=d[i][k]+d[k][j];
	for (i=1;i<=n;i++)
		for (j=1;j<i;j++)
			if (d[i][j]==0x3f3f3f3f&&udeg[i]>0&&udeg[j]>0)
			{
				printf("-1\n");
				return 0;
			}
	if (deg[1]==0&&um!=0)
	{
		printf("-1\n");
		return 0;
	}
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for (i=0;i<1<<n;i++)
		for (j=1;j<n;j++)
			if ((i&(1<<j-1))==0)
				for (k=j+1;k<=n;k++)
					if (j!=k&&(i&(1<<k-1))==0)
						if (f[i]+d[j][k]<f[i|(1<<j-1)|(1<<k-1)])
							f[i|(1<<j-1)|(1<<k-1)]=f[i]+d[j][k];
	u=0;
	for (i=1;i<=n;i++)
		u|=(deg[i]&1)<<i-1;
	printf("%d\n",ans+f[u]);
	return 0;
}