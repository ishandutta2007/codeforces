#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define maxn 200005
#define inf 1061109567
struct edge
{
	int from,to,cap,flow;
};
int n,m,gg,a[maxn],v[maxn],ans;
vector<edge> edges;
vector<int> g[maxn];
bool vis[maxn];
int d[maxn];
int cur[maxn];
bool bfs(int s,int t)
{
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(s);
	d[s]=0;
	vis[s]=1;
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		for (int i=0;i<g[x].size();i++)
		{
			edge&e=edges[g[x][i]];
			if (!vis[e.to] && e.cap>e.flow)
			{
				vis[e.to]=1;
				d[e.to]=d[x]+1;
				q.push(e.to);
			}
		}
	}
	return vis[t];
}
int dfs(int x,int t,int a)
{
	if (x==t||a==0)
		return a;
	int flow=0,f;
	for (int&i=cur[x];i<g[x].size();i++)
	{
		edge&e=edges[g[x][i]];
		if (d[x]+1==d[e.to]&&(f=dfs(e.to,t,min(a,e.cap-e.flow)))>0)
		{
			e.flow+=f;
			edges[g[x][i]^1].flow-=f;
			flow+=f;
			a-=f;
			if (a==0)
				break;
		}
	}
	return flow;
}
int maxflow(int s,int t)
{
	int flow=0;
	while (bfs(s,t))
	{
		memset(cur,0,sizeof(cur));
		flow+=dfs(s,t,inf);
	}
	return flow;
}
void addedge(int from,int to,int cap)
{
	edges.push_back((edge){from,to,cap,0});
	edges.push_back((edge){to,from,0,0});
	int m=edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
int main()
{
    scanf("%d%d%d",&n,&m,&gg);
	edges.resize(0);
	memset(vis,0,sizeof(vis));
	memset(d,0,sizeof(d));
	memset(cur,0,sizeof(cur));
	int i,j,x,y,z,p;
	for (i=1;i<=maxn;i++)
		g[i].resize(0);
	for (i=1;i<=n;i++)
	    scanf("%d",&a[i]);
	for (i=1;i<=n;i++)
	{
	    scanf("%d",&v[i]);
	    if (a[i])
	        addedge(1,i+1,v[i]);
	    else
	        addedge(i+1,n+m+2,v[i]);
	}
	for (i=1;i<=m;i++)
	{
	    scanf("%d%d",&x,&p);
	    ans+=p;
	    scanf("%d",&y);
	    for (j=1;j<=y;j++)
	    {
	        scanf("%d",&z);
	        if (x)
	            addedge(i+n+1,z+1,inf);
	        else
	            addedge(z+1,i+n+1,inf);
	    }
	    scanf("%d",&y);
	    if (x)
	        addedge(1,i+n+1,p+y*gg);
	    else
	        addedge(i+n+1,n+m+2,p+y*gg);
	}
	printf("%d\n",ans-maxflow(1,n+m+2));
	return 0;
}