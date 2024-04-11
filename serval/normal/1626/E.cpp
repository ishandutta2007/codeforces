#include <cstdio>
#include <algorithm>
using namespace std;
const int N=3e5+5;
const int E=N<<1;
int n;
int c[N];
int h[N],nx[E],to[E],et;
int cnt[N],db[N],sc[N],tot[N];
int ans[N];
void ae(int u,int v)
{
	et++;
	to[et]=v;
	nx[et]=h[u];
	h[u]=et;
}
void dfs1(int u,int f=0)
{
	for (int i=h[u];i;i=nx[i])
		if (to[i]!=f)
		{
			dfs1(to[i],u);
			if (cnt[to[i]])
				tot[u]++;
			sc[u]+=c[to[i]];
			cnt[u]+=cnt[to[i]];
			db[u]|=db[to[i]];
		}
	cnt[u]+=c[u];
	db[u]|=(cnt[u]>=2&&c[u]==1)||(tot[u]>=2&&sc[u]);
}
void dfs2(int u,int f=0,int fdb=0,int fsc=0)
{
	int ftot=cnt[1]-cnt[u];
	fdb|=(ftot+c[u]>=2&&c[u]==1);
	ans[u]=db[u]||fdb||(sc[u]+fsc);
	int sdb=0;
	for (int i=h[u];i;i=nx[i])
		if (to[i]!=f)
			sdb+=db[to[i]];
	for (int i=h[u];i;i=nx[i])
		if (to[i]!=f)
			dfs2(to[i],u,fdb||(tot[u]-(cnt[to[i]]>0)+ftot>=2&&(sc[u]+fsc))||(cnt[1]-cnt[to[i]]>=2&&c[u]==1)||(sdb-db[to[i]]),c[u]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		ae(u,v);
		ae(v,u);
	}
	dfs1(1);
	dfs2(1);
	for (int i=1;i<=n;i++)
		printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}