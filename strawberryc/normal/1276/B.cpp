#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

typedef long long ll;

const int N = 2e5 + 5, M = 1e6 + 5;

int n, m, a, b, ecnt, nxt[M], adj[N], go[M], ToT, dfn[N], low[N], sze[N], rst;
bool isb[N];
ll ans;

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u)
{
	dfn[u] = low[u] = ++ToT; isb[u] = u == b; sze[u] = 1;
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		if (!dfn[v])
		{
			dfs(v); isb[u] |= isb[v];
			sze[u] += sze[v];
			if (u == a && isb[v]) rst = n - sze[v] - 1;
			low[u] = std::min(low[u], low[v]);
			if (u == b && dfn[u] <= low[v]) ans += sze[v];
		}
		else low[u] = std::min(low[u], dfn[v]);
}

void work()
{
	int x, y;
	read(n); read(m); read(a); read(b);
	ecnt = 0;
	for (int i = 1; i <= n; i++) adj[i] = dfn[i] = 0;
	while (m--) read(x), read(y), add_edge(x, y);
	ToT = 0; ans = 0; dfs(a);
	printf("%lld\n", ans * rst);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}