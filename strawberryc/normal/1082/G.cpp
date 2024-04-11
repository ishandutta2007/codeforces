#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
#define Edge(u) for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
#define NF(u) for (int &e = cur[u], v = go[e]; e; e = nxt[e], v = go[e])

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

typedef long long ll;

const int N = 2100, M = 1e5 + 5;
const ll INF = 1e18;

int n, m, ecnt = 1, nxt[M], adj[N], go[M], S, T, len, que[N],
lev[N], cur[N];
ll cap[M];

void add_edge(int u, int v, ll w)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; cap[ecnt] = w;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u; cap[ecnt] = 0;
}

bool bfs()
{
	int i;
	For (i, S, T) cur[i] = adj[i], lev[i] = -1;
	lev[que[len = 1] = S] = 0;
	For (i, 1, len)
	{
		int u = que[i];
		Edge(u) if (cap[e] && lev[v] == -1)
		{
			lev[que[++len] = v] = lev[u] + 1;
			if (v == T) return 1;
		}
	}
	return 0;
}

ll dinic(int u, ll flow)
{
	if (u == T) return flow;
	ll res = 0, delta;
	NF(u) if (cap[e] && lev[u] < lev[v])
	{
		delta = dinic(v, Min(cap[e], flow - res));
		if (delta)
		{
			cap[e] -= delta; cap[e ^ 1] += delta;
			res += delta; if (res == flow) break;
		}
	}
	if (res != flow) lev[u] = -1;
	return res;
}

int main()
{
	int i, x, y, z;
	ll ans = 0;
	n = read(); m = read();
	S = 1; T = n + m + 2;
	For (i, 1, n) x = read(), add_edge(1 + m + i, T, x);
	For (i, 1, m) x = read(), y = read(), z = read(),
		add_edge(S, 1 + i, z), add_edge(1 + i, 1 + m + x, INF),
		add_edge(1 + i, 1 + m + y, INF), ans += z;
	while (bfs()) ans -= dinic(S, INF);
	std::cout << ans << std::endl;
	return 0;
}