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

typedef long long ll;

const int N = 2e5 + 5, M = N << 1;

int n, c[N], ecnt, nxt[M], adj[N], go[M], tot, l[N], r[N], fa[N], m, res[N];
ll ans;

struct edge
{
	int x, y, z, id;
} a[N];

inline bool comp(edge a, edge b)
{
	return a.z < b.z;
}

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu)
{
	int cnt = 0;
	for (int e = adj[u], v; e; e = nxt[e])
	{
		if ((v = go[e]) == fu) continue;
		dfs(v, u); cnt++;
		if (cnt == 1) l[u] = l[v];
		r[u] = r[v];
	}
	if (!cnt) l[u] = r[u] = ++tot;
	a[++m] = (edge) {l[u], r[u] + 1, c[u], u};
}

int cx(int x)
{
	if (fa[x] != x) fa[x] = cx(fa[x]);
	return fa[x];
}

bool zm(int x, int y)
{
	int ix = cx(x), iy = cx(y);
	if (ix != iy) return fa[iy] = ix, 1;
	return 0;
}

int main()
{
	int x, y;
	n = read();
	for (int i = 1; i <= n; i++) c[i] = read();
	for (int i = 1; i < n; i++)
		x = read(), y = read(), add_edge(x, y);
	dfs(1, 0);
	std::sort(a + 1, a + m + 1, comp);
	for (int i = 1; i <= tot + 1; i++) fa[i] = i;
	tot = 0;
	for (int i = 1; i <= m; i++)
	{
		if (i == 1 || a[i].z != a[i - 1].z)
			for (int j = i; j <= m && a[i].z == a[j].z; j++)
				if (cx(a[j].x) != cx(a[j].y)) res[++tot] = a[j].id;
		if (zm(a[i].x, a[i].y)) ans += a[i].z;
	}
	std::cout << ans << " " << tot << std::endl;
	std::sort(res + 1, res + tot + 1);
	for (int i = 1; i <= tot; i++) printf("%d ", res[i]);
	return puts(""), 0;
}