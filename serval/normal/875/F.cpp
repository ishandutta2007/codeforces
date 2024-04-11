#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=200005;
int n,m,i;
int u[maxn],v[maxn],w[maxn];
int p[maxn];
int f[maxn];
bool ring[maxn];
int ans;
bool cmp(int x,int y)
{
	return w[x]>w[y];
}
int getf(int u)
{
	if (f[u]==0)
		return u;
	return f[u]=getf(f[u]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		p[i]=i;
	}
	sort(p+1,p+m+1,cmp);
	for (i=1;i<=m;i++)
	{
		u[p[i]]=getf(u[p[i]]);
		v[p[i]]=getf(v[p[i]]);
		if (u[p[i]]!=v[p[i]])
		{
			if (ring[u[p[i]]]&&ring[v[p[i]]])
				continue;
			ans+=w[p[i]];
			f[u[p[i]]]=v[p[i]];
			ring[v[p[i]]]|=ring[u[p[i]]];
		}
		else
			if (!ring[u[p[i]]])
			{
				ans+=w[p[i]];
				ring[u[p[i]]]=1;
			}
	}
	printf("%d\n",ans);
	return 0;
}