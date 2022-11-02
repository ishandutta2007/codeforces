#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define Inf 1000000000000ll
#define inf 1000000000
struct Dinic_maximum_flow
{
	int son[10005],next[300005],ed[300005],d[10005],q[10005],ll,rr;
	long long flow[300005],sum,tmp;
	int n,S,T,tot,i,u,v;
	bool vis[10005];
	
	inline void clear(int N){for(n=N,tot=1,i=0;i<=n;++i)son[i]=0;}
	inline void add(int u,int v,long long c)
	{
		next[++tot]=son[u];son[u]=tot;ed[tot]=v;flow[tot]=c;
		next[++tot]=son[v];son[v]=tot;ed[tot]=u;flow[tot]=0;
	}
	long long find(int now,long long Flow)
	{
		if(now==T||!Flow)return Flow;
		long long tmp,w=0;
		for(int i=son[now];i&&w<Flow;i=next[i])
		if(flow[i]&&d[now]+1==d[ed[i]])
		{
			tmp=find(ed[i],min(Flow-w,flow[i]));
			flow[i]-=tmp;flow[i^1]+=tmp;w+=tmp;
		}
		if(!w)d[now]=inf;
		return w;
	}
	bool bfs()
	{
		for(i=0;i<=n;++i)vis[i]=false;
		q[rr=1]=S;vis[S]=true;
		for(ll=0;ll<rr&&!vis[T];)
		{
			u=q[++ll];
			for(i=son[u];i;i=next[i])
			if(flow[i]&&!vis[ed[i]])
			{
				v=ed[i];
				q[++rr]=v;
				d[v]=d[u]+1;
				vis[v]=true;
			}
		}
		return vis[T];
	}
	long long dinic(int s,int t)
	{
		S=s;T=t;
		for(sum=d[S]=0;bfs();)sum+=find(S,Inf+Inf);
		return sum;
	}
}G;

int n,i,j,k;
long long ans;

int main()
{
	scanf("%d",&n);
	G.clear(n+n+1);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&k);
		for(;k;--k)
		{
			scanf("%d",&j);
			G.add(i,n+j,Inf);
		}
	}
	for(i=1;i<=n;++i)
	{
		scanf("%d",&k);
		ans+=inf-k;
		G.add(0,i,inf-k);
	}
	for(i=1;i<=n;++i)G.add(i+n,n+n+1,inf);
	ans-=G.dinic(0,n+n+1);
	printf("%I64d\n",-ans);
}