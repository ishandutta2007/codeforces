#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
const int N=3e5+5;
const int E=N<<1;
int n;
int w[N];
int h[N],nx[E],to[E],et;
int mx;
int fir[N],sec[N];
long long ans;
void ae(int u,int v)
{
	et++;
	to[et]=v;
	nx[et]=h[u];
	h[u]=et;
}
void dp(int u,int f=0)
{
	for (int i=h[u];i;i=nx[i])
		if (to[i]!=f)
		{
			dp(to[i],u);
			if (fir[to[i]]>fir[u])
			{
				sec[u]=fir[u];
				fir[u]=fir[to[i]];
			}
			else
				if (fir[to[i]]>sec[u])
					sec[u]=fir[to[i]];
		}
	if (fir[u]<w[u])
	{
		ans+=w[u]-fir[u];
		fir[u]=w[u];
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		if (w[i]>w[mx])
			mx=i;
	}
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		ae(u,v);
		ae(v,u);
	}
	dp(mx);
	if (sec[mx]<w[mx])
		ans+=w[mx]-sec[mx];
	printf("%lld\n",ans);
	return 0;
}