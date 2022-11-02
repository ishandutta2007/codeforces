#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define inf 1000000000
struct Dinic_maximum_flow
{
	#define Graph_vertex 400005
	#define Graph_edge 3000005
	#define flow_value int
	
	int son[Graph_vertex],next[Graph_edge],ed[Graph_edge],d[Graph_vertex],q[Graph_vertex],ll,rr;
	flow_value flow[Graph_edge],sum,tmp;
	int n,S,T,tot,i,u,v;
	bool vis[Graph_vertex];
	
	inline void clear(int N){for(n=N,tot=1,i=0;i<=n;++i)son[i]=0;}
	inline void add(int u,int v,flow_value c)
	{
		next[++tot]=son[u];son[u]=tot;ed[tot]=v;flow[tot]=c;
		next[++tot]=son[v];son[v]=tot;ed[tot]=u;flow[tot]=0;
	}
	flow_value find(int now,flow_value Flow)
	{
		if(now==T||!Flow)return Flow;
		flow_value tmp,w=0;
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
	flow_value dinic(int s,int t)
	{
		S=s;T=t;
		for(sum=d[S]=0;bfs();)sum+=find(S,inf);
		return sum;
	}
	
	#undef Graph_vertex
	#undef Graph_edge
	#undef flow_value
}G;

int n,m,i,j,k;
int x[200005],y[200005],cntx[200005],cnty[200005],idx[200005],idy[200005];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",&x[i],&y[i]);
	for(i=1;i<=n;++i)++cntx[x[i]],++cnty[y[i]];
	for(i=1;i<=200000;++i)if(cntx[i])idx[i]=++m;
	for(i=1;i<=200000;++i)if(cnty[i])idy[i]=++m;
	G.clear(m+1);
	for(i=1;i<=n;++i)G.add(idx[x[i]],idy[y[i]],1);
	for(i=1;i<=200000;++i)if(cntx[i]>1)G.add(0,idx[i],cntx[i]/2);
	for(i=1;i<=200000;++i)if(cnty[i]>1)G.add(idy[i],m+1,cnty[i]/2);
	G.dinic(0,m+1);
	for(i=1;i<=200000;++i)if(cntx[i]&1)G.add(0,idx[i],1);
	for(i=1;i<=200000;++i)if(cnty[i]&1)G.add(idy[i],m+1,1);
	G.dinic(0,m+1);
	for(i=1;i<=n;++i)if(G.flow[1+i*2])printf("b");else printf("r");
	printf("\n");
}