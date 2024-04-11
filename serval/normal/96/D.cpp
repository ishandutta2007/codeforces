#include <cstdio>
using namespace std;
const int maxn=1005;
const int maxe=2005;
int n,m,x,y,i,u,v,w;
int h[maxn],to[maxe],nx[maxe],et;
long long wt[maxe];
long long dist[maxn][maxn];
long long t[maxn],c[maxn];
long long ret[maxn];
int q[2000005],ql,qr;
bool inq[maxn];
void addedge(int u,int v,int w)
{
	et++;
	to[et]=v;
	wt[et]=w;
	nx[et]=h[u];
	h[u]=et;
}
void spfa(int u)
{
	for (int i=1;i<=n;i++)
		if (i!=u)
			dist[u][i]=-1;
	inq[u]=1;
	q[1]=u;
	ql=qr=1;
	while (ql<=qr)
	{
		for (int i=h[q[ql]];i;i=nx[i])
			if (dist[u][q[ql]]+wt[i]<dist[u][to[i]]||dist[u][to[i]]==-1)
			{
				dist[u][to[i]]=dist[u][q[ql]]+wt[i];
				if (!inq[to[i]])
				{
					inq[to[i]]=1;
					qr++;
					q[qr]=to[i];
				}
			}
		inq[q[ql]]=0;
		ql++;
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	for (i=1;i<=n;i++)
		spfa(i);
	for (i=1;i<=n;i++)
	{
		scanf("%lld%lld",&t[i],&c[i]);
		ret[i]=-1;
	}
	inq[x]=1;
	q[1]=x;
	ql=qr=1;
	ret[x]=0;
	while (ql<=qr)
	{
		for (i=1;i<=n;i++)
			if (dist[q[ql]][i]<=t[q[ql]]&&dist[q[ql]][i]!=-1)
				if (ret[q[ql]]+c[q[ql]]<ret[i]||ret[i]==-1)
				{
					ret[i]=ret[q[ql]]+c[q[ql]];
					if (!inq[i])
					{
						inq[i]=1;
						qr++;
						q[qr]=i;
					}
				}
		inq[q[ql]]=0;
		ql++;
	}
	printf("%lld\n",ret[y]);
	return 0;
}