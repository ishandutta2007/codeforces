#include <bits/stdc++.h>

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 75, M = 405, C = 132000, INF = 0x3f3f3f3f;

int n, m, a, b, ecnt, nxt[M], adj[N], go[M], val[M], dis[C][N], fa[N],
U[M], V[M], W[M], sze[N], tot, id[N], Cm;
bool vis[C][N];

struct elem
{
	int u, dis;
	
	friend inline bool operator < (elem a, elem b)
	{
		return a.dis > b.dis;
	}
};

std::priority_queue<elem> pq;

void add_edge(int u, int v, int w)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; val[ecnt] = w;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u; val[ecnt] = w;
}

int cx(int x)
{
	if (fa[x] != x) fa[x] = cx(fa[x]);
	return fa[x];
}

void zm(int x, int y)
{
	int ix = cx(x), iy = cx(y);
	if (ix != iy) fa[iy] = ix, sze[ix] += sze[iy];
}

int main()
{
	n = read(); m = read(); a = read(); b = read();
	for (int i = 1; i <= n; i++) fa[i] = i, sze[i] = 1;
	for (int i = 1; i <= m; i++)
	{
		U[i] = read(); V[i] = read(); W[i] = read();
		if (W[i] == a) zm(U[i], V[i]), add_edge(U[i], V[i], W[i]);
	}
	for (int i = 1; i <= m; i++)
		if (W[i] == b && cx(U[i]) != cx(V[i]))
			add_edge(U[i], V[i], W[i]);
	for (int i = 1; i <= n; i++)
		if (fa[i] == i && sze[i] >= 4)
			id[i] = ++tot;
	memset(dis, INF, sizeof(dis));
	Cm = 1 << tot;
	int st = sze[cx(1)] < 4 ? 0 : 1 << id[cx(1)] - 1;
	pq.push((elem) {st * n, dis[st][1] = 0});
	while (!pq.empty())
	{
		elem xt = pq.top(); pq.pop();
		int S = xt.u / n, u = xt.u % n + 1;
		for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		{
			if (id[cx(v)] && ((S >> id[cx(v)] - 1) & 1)
				&& id[cx(u)] != id[cx(v)]) continue;
			int T = id[cx(v)] ? S | (1 << id[cx(v)] - 1) : S;
			if (dis[S][u] + val[e] < dis[T][v])
				pq.push((elem) {T * n + v - 1, dis[T][v] = dis[S][u] + val[e]});
		}
	}
	for (int u = 1; u <= n; u++)
	{
		int ans = INF;
		for (int S = 0; S < Cm; S++)
			if (dis[S][u] < ans) ans = dis[S][u];
		printf("%d ", ans);
	}
	return puts(""), 0;
}
//