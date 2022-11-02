#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,u,v,S,T;
int son[1000005],next[1000005],ed[1000005],init[1000005];
int dist[1000005],q[2000005],l,r;
bool finished[1000005];

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		next[i]=son[v];son[v]=i;ed[i]=u;++init[u];
	}
	scanf("%d%d",&S,&T);
	for(i=1;i<=n;++i)dist[i]=n+1;
	dist[T]=0;l=r=n;q[++r]=T;
	while(l<r)
	{
		u=q[++l];
		if(finished[u])continue;
		finished[u]=true;
		for(i=son[u];i;i=next[i])
		{
			v=ed[i];--init[v];
			if(!init[v])
			{
				if(dist[u]<dist[v])q[l--]=v,dist[v]=dist[u];
			}
			else
			{
				if(dist[u]+1<dist[v])q[++r]=v,dist[v]=dist[u]+1;
			}
		}
	}
	if(dist[S]<n)printf("%d\n",dist[S]);
	else printf("-1\n");
}