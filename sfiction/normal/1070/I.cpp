#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

const int maxn=1500;
const int maxe=5000;

int first[maxn], nxt[maxe], vv[maxe];
int cap[maxe], flow[maxe], pre[maxn];

bool vis[maxn];
int dis[maxn];
int maxflow(int s, int t)
{
	int ans=0;
	queue<int> q;
	while (true)
	{
		memset(vis, 0, sizeof(vis));
		memset(dis, -1, sizeof(dis));
		while (!q.empty()) q.pop();

		q.push(s);
		vis[s]=1;
		while (!q.empty())
		{
			int u=q.front();
			q.pop();
			vis[u]=0;
			if (u==t)
				break;
			
			for (int e=first[u];e;e=nxt[e])
			{
				if (cap[e]>flow[e])
				{
					int v = vv[e];
					if (dis[v]<0||dis[v]>dis[u]+1)
					{
						dis[v] = dis[u]+1;
						pre[v] = e;
						if (!vis[v])
						{
							vis[v]=1;
							q.push(v);
						}
					}
				}
			}
		}
		if (dis[t]<0)
			return ans;

		int minflow = 1e9;
		int n = t;
		while (n!=s)
		{
			int e = pre[n];
			minflow = min(minflow, cap[e]-flow[e]);
			n = vv[e^1];
		}
		ans+=minflow;

		n=t;
		while(n!=s)
		{
			int e = pre[n];
			flow[e] += minflow;
			flow[e^1] -= minflow;
			n = vv[e^1];
		}
	}
	return ans;
}

void addEdge(int u, int v, int c, int& e)
{
	nxt[e]=first[u], vv[e]=v, cap[e]=c, flow[e]=0, first[u]=e++;
	nxt[e]=first[v], vv[e]=u, cap[e]=0, flow[e]=0, first[v]=e++;
}

int d[maxn];
int bel[maxn];
int main()
{
	int n,m,k;
	int tt;

	scanf("%d",&tt);

	while (tt--)
	{
		scanf("%d%d%d",&n,&m,&k);
		memset(first, 0, sizeof(first));
		memset(bel, 0, sizeof(bel));
		memset(d, 0, sizeof(d));
		int e=2;

		for (int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			d[u]++,d[v]++;
			addEdge(u+2, i+n+2, 1, e);
			addEdge(v+2, i+n+2, 1, e);
			addEdge(i+n+2, 2, 1, e);
		}
		int total = 0;
		for (int i=1;i<=n;i++)if(d[i]>k)
		{
			int need = (d[i]-k)*2;
			total += need;
			addEdge(1, i+2, need, e);
		}
		int maxf = maxflow(1, 2);
		if (maxf<total)
		{
			for (int i=1;i<m;i++)
				printf("0 ");
			puts("0");
		}
		else
		{
			int color = 0;
			for (int i=1;i<=n;i++)
			{
				int edge = 0;
				int u=i+2;
				for (e=first[u];e;e=nxt[e])if(flow[e]>0)
				{
					int v=vv[e];
					v -= n+2;

					if (edge)
						bel[edge] = bel[v] = ++color, edge = 0;
					else
						edge = v;
				}
			}
			for (int i=1;i<=m;i++)if(!bel[i])
				bel[i] = ++color;
			for (int i=1;i<m;i++)
				printf("%d ", bel[i]);
			printf("%d\n", bel[m]);
		}
	}
}