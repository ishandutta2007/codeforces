#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,m,K,i,j,k,u,v,c,ans;
int u1[300005],v1[300005],c1[300005],u2[300005],c2[300005];
long long dist[200001];
int son[200001],next[1000001],ed[1000001],cost[1000001],tot;
int queue[1000001],t1,t2,queue_len;
bool visit[200001],intree[100005];

inline void add(int u,int v,int c){++tot;next[tot]=son[u];son[u]=tot;ed[tot]=v;cost[tot]=c;}
inline void SPFA(int S)
{
	int l,queue_tmp,t1=0,t2=1,tmp;
	memset(dist,0x3f,sizeof(dist));
	queue_len=1;queue[1]=S;dist[S]=0;visit[S]^=1;
	while(queue_len!=0)
	{
		--queue_len;
		if(++t1==1000001)t1=1;
		visit[queue_tmp=queue[t1]]^=1;
		for(l=son[queue_tmp];l;l=next[l])
		if(dist[queue_tmp]+cost[l]<dist[ed[l]])
		{
			dist[tmp=ed[l]]=dist[queue_tmp]+cost[l];
			if(!visit[tmp])
			{
				if(dist[tmp]>dist[queue[t1+1]])
				{
					if(++t2==1000001)t2=1;
					++queue_len;
					queue[t2]=ed[l];
					visit[tmp]^=1;
				}
				else
				{
					++queue_len;
					queue[t1]=tmp;
					visit[tmp]^=1;
					if(--t1==0)t1=1000000;
				}
			}
		}
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&K);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d",&u1[i],&v1[i],&c1[i]);
		add(u1[i],v1[i],c1[i]);
		add(v1[i],u1[i],c1[i]);
	}
	for(i=1;i<=K;++i)
	{
		scanf("%d%d",&u2[i],&c2[i]);
		add(1,u2[i],c2[i]);
	}
	SPFA(1);
	for(i=1;i<=m;++i)
	{
		u=u1[i];v=v1[i];c=c1[i];
		if(dist[u]+c==dist[v])intree[v]=true;
		if(dist[v]+c==dist[u])intree[u]=true;
	}
	ans=K;
	for(i=2;i<=n;++i)if(!intree[i])--ans;
	printf("%d\n",ans);
}