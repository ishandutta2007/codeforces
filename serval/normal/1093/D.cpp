#include <cstdio>
using namespace std;
const int N=300005;
const long long mod=998244353;
int t;
int n,m,u;
int x[N],y[N];
int f[N],w[N],sz[N],ev[N];
long long p[N];
int ans;
int getf(int u)
{
	if (!f[u])
		return u;
	int ret=getf(f[u]);
	w[u]^=w[f[u]];
	f[u]=ret;
	return ret;
}
int main()
{
	scanf("%d",&t);
	p[0]=1;
	for (int i=1;i<N;i++)
		p[i]=p[i-1]*2ll%mod;
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
		{
			f[i]=w[i]=0;
			sz[i]=1;
			ev[i]=1;
		}
		for (int i=1;i<=m;i++)
			scanf("%d%d",&x[i],&y[i]);
		ans=1;
		for (int i=1;i<=m;i++)
		{
			if (getf(x[i])==getf(y[i]))
			{
				if (w[x[i]]^w[y[i]]^1)
					ans=0;
			}
			else
			{
				u=getf(x[i]);
				f[u]=getf(y[i]);
				w[u]=w[x[i]]^w[y[i]]^1;
				sz[getf(y[i])]+=sz[u];
				ev[getf(y[i])]+=w[u]?sz[u]-ev[u]:ev[u];
			}
		}
		for (int i=1;i<=n;i++)
			if (!f[i])
				ans=1ll*ans*(p[ev[i]]+p[sz[i]-ev[i]])%mod;
		printf("%d\n",ans);
	}
	return 0;
}