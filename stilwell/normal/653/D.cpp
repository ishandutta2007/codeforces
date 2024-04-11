#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int x;

#define inf 1000000000
struct Dinic_maximum_flow
{
	#define Graph_vertex 1005
	#define Graph_edge 100005
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
		for(sum=d[S]=0;bfs();)
		{
			if(sum>=x)return sum;
			sum+=find(S,inf);
		}
		return sum;
	}
	
	#undef Graph_vertex
	#undef Graph_edge
	#undef flow_value
}G;

int n,m,i,j,k;
int u[10005],v[10005],c[10005];
double l,r,mid;
long long C;

int main()
{
	scanf("%d%d%d",&n,&m,&x);
	for(i=1;i<=m;++i)scanf("%d%d%d",&u[i],&v[i],&c[i]);
	l=0.000000001;r=1000000;
	for(i=1;i<=100;++i)
	{
		mid=(l+r)/2;
		G.clear(n);
		for(j=1;j<=m;++j)
		{
			C=(long long)(((long long)c[j])/mid);
			if(x<C)C=x;
			G.add(u[j],v[j],C);
		}
		if(G.dinic(1,n)>=x)l=mid;
		else r=mid;
	}
	printf("%.10lf\n",mid*x);
}