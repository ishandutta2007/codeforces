#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,u,v,c;
int son[200005],next[400005],ed[400005],cost[400005],tot;
int q[200005],ll,rr;
unsigned int sum[200005];
bool use[200005],ans[200005];

int main()
{
	scanf("%d%d",&n,&m);
	tot=1;
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d",&u,&v,&c);
		sum[u]+=c;sum[v]+=c;
		++tot;next[tot]=son[u];son[u]=tot;ed[tot]=v;cost[tot]=c;
		++tot;next[tot]=son[v];son[v]=tot;ed[tot]=u;cost[tot]=c;
	}
	q[rr=1]=1;sum[n]*=2;
	while(ll<rr)
	{
		u=q[++ll];
		for(i=son[u];i;i=next[i])
		if(!use[i/2])
		{
			sum[ed[i]]-=cost[i]*2;
			if(!sum[ed[i]])q[++rr]=ed[i];
			use[i/2]=true;
			ans[i/2]=i%2;
		}
	}
	for(i=1;i<=m;++i)printf("%d\n",ans[i]);
}