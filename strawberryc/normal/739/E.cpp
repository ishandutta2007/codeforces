#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
#define Edge(u) for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
#define MCMF(e) for (e = pre[T]; e; e = pre[st[e]])

template <class T>
T Min(T a, T b) {return a < b ? a : b;}

const int N = 2010, M = 2e4 + 717;
const double INF = 1e20, eps = 1e-10;

int n, a, b, S, T, ecnt = 1, nxt[M], adj[N], st[M], go[M], cap[M], pre[N];
double p[N], u[N], cost[M], dis[N], ans;
bool vis[N];
std::queue<int> Q;

void add_edge(int u, int v, int w, double x)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; st[ecnt] = u;
	go[ecnt] = v; cap[ecnt] = w; cost[ecnt] = x;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; st[ecnt] = v;
	go[ecnt] = u; cap[ecnt] = 0; cost[ecnt] = -x;
}

bool spfa()
{
	int i;
	Q.push(S);
	For (i, S, T) dis[i] = -INF;
	dis[S] = 0;
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();
		vis[u] = 0;
		Edge(u)
			if (cap[e] && dis[u] + cost[e] > dis[v] + eps)
			{
				dis[v] = dis[u] + cost[pre[v] = e];
				if (!vis[v]) vis[v] = 1, Q.push(v);
			}
	}
	return dis[T] > -1e10;
}

void jiejuediao()
{
	int e, fl = 0x3f3f3f3f;
	MCMF(e) fl = Min(fl, cap[e]);
	MCMF(e) cap[e] -= fl, cap[e ^ 1] += fl;
	ans += dis[T] * fl;
}

double MinCostMaxFlow()
{
	ans = 0;
	while (spfa()) jiejuediao();
	return ans;
}

int main()
{
	int i;
	std::cin >> n >> a >> b;
	For (i, 1, n) scanf("%lf", &p[i]);
	For (i, 1, n) scanf("%lf", &u[i]);
	S = 1; T = 4 + n;
	add_edge(S, 2, a, 0); add_edge(S, 3, b, 0);
	For (i, 1, n)
	{
		add_edge(2, 3 + i, 1, p[i]);
		add_edge(3, 3 + i, 1, u[i]);
		add_edge(3 + i, T, 1, 0);
		add_edge(3 + i, T, 1, -p[i] * u[i]);
	}
	printf("%.10lf\n", MinCostMaxFlow());
	return 0;
}