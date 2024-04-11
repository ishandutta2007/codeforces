#include <bits/stdc++.h>
using namespace std;

const int N = 121;
const int M = 5211;
const int Inf = 0x3f3f3f3f;

struct Edge
{
	int u, v, f, w;
}e[M];
int ecnt = 0;
int first[N], nxt[M];
void add(int u, int v, int f, int w)
{
	//cout << u << ' ' << v << ' ' << f << ' ' << w << '\n';
	e[ecnt] = Edge{u, v, f, w};
	nxt[ecnt] = first[u]; first[u] = ecnt ++;
	e[ecnt] = Edge{v, u, 0, -w};
	nxt[ecnt] = first[v]; first[v] = ecnt ++;
}

int f[N];
bool vis[N];
queue <int> q;
int from[N];
bool SPFA(int s, int t)
{
	memset(f, 0x3f, sizeof(f));
	memset(vis, 0, sizeof(vis));
	q.push(s);
	vis[s] = true;
	f[s] = 0;
	while(!q.empty())
	{
		int c = q.front();
		q.pop();
		vis[c] = false;
		for(int i = first[c]; i != -1; i = nxt[i])
			if(e[i].f && f[c] + e[i].w < f[e[i].v])
			{
				f[e[i].v] = f[c] + e[i].w;
				from[e[i].v] = i;
				if(!vis[e[i].v])
				{
					vis[e[i].v] = true;
					q.push(e[i].v);
				}
			}
	}
	return f[t] != Inf;
}

int mcmf(int s, int t)
{
	int ans = 0;
	while(SPFA(s, t))
	{
		int flow = Inf;
		from[s] = -1;
		for(int i = from[t]; i != -1; i = from[e[i].u])
			flow = min(flow, e[i].f);
		ans += flow * f[t];
		for(int i = from[t]; i != -1; i = from[e[i].u])
		{
			e[i].f -= flow;
			e[i ^ 1].f += flow;
		}
	}
	return ans;
}

int sum[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int ans = 0;
	memset(first, -1, sizeof(first));
	memset(nxt, -1, sizeof(nxt));
	for(int i = 0; i < m; i ++)
	{
		int u, v, c, f;
		cin >> u >> v >> c >> f;
		if(f <= c)
		{
			add(u, v, c - f, 1);
			add(u, v, Inf, 2);
			add(v, u, f, 1);
		}
		else
		{
			ans += f - c;
			add(u, v, Inf, 2);
			add(v, u, f - c, 0);
			add(v, u, c, 1);
		}
		sum[u] -= f;
		sum[v] += f;
	}
	add(1, n, Inf, 0);
	add(n, 1, Inf, 0);
	for(int i = 1; i <= n; i ++)
		if(sum[i] < 0)
			add(i, n + 1, -sum[i], 0);
		else
			add(0, i, sum[i], 0);

	cout << ans + mcmf(0, n + 1) << '\n';
	return 0;
}