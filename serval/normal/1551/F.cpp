#include <cstdio>
#include <algorithm>
using namespace std;
const int N=105;
const int E=205;
const int mod=1e9+7;
int T;
int n,k;
int u[N],v[N];
int h[N],to[E],nx[E],et;
int d[N][N],g[N][N][N];
int r[N][N],par[N];
int ans;
int fac[N],inv[N];
int fpw(int b,int e)
{
	if (e==0)
		return 1;
	int ret=fpw(b,e>>1);
	ret=1ll*ret*ret%mod;
	if (e&1)
		ret=1ll*ret*b%mod;
	return ret;
}
void ae(int u,int v)
{
	et++;
	to[et]=v;
	nx[et]=h[u];
	h[u]=et;
}
void dfs(int u,int f=0)
{
	par[u]=f;
	r[u][0]++;
	for (int i=h[u];i;i=nx[i])
		if (to[i]!=f)
		{
			dfs(to[i],u);
			for (int j=0;j<=n;j++)
				r[u][j+1]+=r[to[i]][j];
		}
}
void dfs2(int u,int f=0,int l=0)
{
	d[u][l]++;
	for (int i=1;i<=n;i++)
	{
		g[u][i][0]=1;
		for (int j=1;j<=n;j++)
			g[u][i][j]=0;
	}
	for (int i=h[u];i;i=nx[i])
		if (to[i]!=f)
		{
			dfs2(to[i],u,l+1);
			for (int j=1;j<=n;j++)
				for (int x=k;x;x--)
					g[u][j][x]=(g[u][j][x]+1ll*g[u][j][x-1]*d[to[i]][j])%mod;
			for (int j=1;j<=n;j++)
				d[u][j]+=d[to[i]][j];
		}
	for (int j=l;j<=n;j++)
	{
		int cur=0;
		for (int x=u,y=j-l-1;par[x]&&y>=0;x=par[x],y--)
		{
			cur+=r[par[x]][y];
			if (y>0)
				cur-=r[x][y-1];
		}
		for (int x=k;x;x--)
			g[u][j][x]=(g[u][j][x]+1ll*g[u][j][x-1]*cur)%mod;
	}
	for (int j=1;j<=n;j++)
		ans=(ans+g[u][j][k])%mod;
}
int C(int n,int m)
{
	if (n<m)
		return 0;
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
void solve()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		h[i]=0;
	et=0;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		ae(u[i],v[i]);
		ae(v[i],u[i]);
	}
	if (k==2)
	{
		printf("%d\n",n*(n-1)/2);
		return;
	}
	ans=0;
	for (int j=0;j<=n;j++)
		for (int k=0;k<=n;k++)
			d[j][k]=r[j][k]=0;
	dfs(1);
	dfs2(1);
	printf("%d\n",ans);
}
int main()
{
	fac[0]=1;
	for (int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mod;
	inv[N-1]=fpw(fac[N-1],mod-2);
	for (int i=N-1;i;i--)
		inv[i-1]=1ll*inv[i]*i%mod;
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}