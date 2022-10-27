#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 1000000007;
const int NICO = 20002;
const int MAKI = 20002;

int head[NICO];
long long dis[NICO];
int vis[NICO];
int mark[NICO];
int n, m, s, t, size = 1;
int u, v;
long long l, w;

struct Edge
{
	int from, to;
	ll cost;
	int next;
} e[MAKI];

void init()
{
	size = 0;
	for(int i=0;i<n;i++)
	{
		head[i] = -1;
	}
}

void addEdge(int u, int v, ll w)
{
	e[size].to = v;
	e[size].from=u;
	e[size].cost=w;
	e[size].next=head[u];
	head[u]=size++;
}

ll spfa(int s)
{
	for(int i=0;i<n;i++) dis[i]=INF, vis[i]=0;
	vis[s] = 1;
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		vis[cur] = 0;
		for(int i = head[cur]; i!=-1; i = e[i].next)
		{
			int id = e[i].to;
			if(dis[id] > dis[cur] + e[i].cost)
			{
				dis[id] = dis[cur] + e[i].cost;
				if(!vis[id])
				{
					q.push(id);
					vis[id] = 1;
				}
			}
		}
	} 
	return dis[t];
}

int main()
{
	cin >> n >> m >> l >> s >> t;
	init();
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %I64d", &u, &v, &w);
		if(w == 0) 
		{
			w = 1;
			mark[i] = 1;
		}
		addEdge(u, v, w);
		addEdge(v, u, w);
	}
	ll res = spfa(s);

	if(res > l || res == INF)
	{
		printf("NO\n");	
		return 0;
	}
	
	ll add = l - res;
	for(int i=0;i<m;i++)
	{
		if(mark[i])
		{
			e[2*i].cost += add;
			e[2*i+1].cost += add;

			res = spfa(s);

			add = l - res;
			if(add == 0)
			{
				break;
			}
		}
	}
	if(add != 0)
	{
		printf("NO\n");		
	} else {
		printf("YES\n");
		for(int i=0; i<m; i++)
		{
			printf("%d %d %I64d\n", e[2*i].from, e[2*i].to, e[2*i].cost);
		}
	}
}