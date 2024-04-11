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

const int N = 2e5 + 5, M = N << 1;

int n, k, ecnt, nxt[M], adj[N], go[M], dep[N], fa[N], d[N], sze[N], a[N];
ll ans;

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu)
{
	fa[u] = fu; dep[u] = dep[fu] + 1; sze[u] = 1;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu) dfs(v, u), d[u]++, sze[u] += sze[v];
}

int main()
{
	int x, y;
	read(n); read(k);
	for (int i = 1; i < n; i++) read(x), read(y), add_edge(x, y);
	dfs(1, 0);
	for (int i = 1; i <= n; i++) a[i] = dep[i] - sze[i];
	std::sort(a + 1, a + n + 1);
	for (int i = n - k + 1; i <= n; i++) ans += a[i];
	return std::cout << ans << std::endl, 0;
}