#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

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
inline void Swap(T &a, T &b) {T t = a; a = b; b = t;}

const int N = 1e5 + 5, M = N << 1, LogN = 20, E = 305, ZZQ = 1e9 + 7;

int n, q, ecnt, nxt[M], adj[N], go[M], T, dfn[N], sze[N], fa[N][LogN], dep[N],
xdfn[N], xsze[N], k, m, r, a[N], A[N], cnt[N], f[N][E];

void change(int x, int v)
{
	for (; x <= n; x += x & -x)
		A[x] += v;
}

int ask(int x)
{
	int res = 0;
	for (; x; x -= x & -x)
		res += A[x];
	return res;
}

void change(int l, int r, int v)
{
	change(l, v); change(r + 1, -v);
}

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu)
{
	dfn[u] = ++T; sze[u] = 1;
	dep[u] = dep[fa[u][0] = fu] + 1;
	for (int i = 0; i < 16; i++)
		fa[u][i + 1] = fa[fa[u][i]][i];
	for (int e = adj[u], v; e; e = nxt[e])
	{
		if ((v = go[e]) == fu) continue;
		dfs(v, u);
		sze[u] += sze[v];
	}
}

int lca(int u, int v)
{
	if (dep[u] < dep[v]) Swap(u, v);
	for (int i = 16; i >= 0; i--)
	{
		if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
		if (u == v) return u;
	}
	for (int i = 16; i >= 0; i--)
		if (fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}

int jm(int u, int dis)
{
	for (int i = 16; i >= 0; i--)
		if ((dis >> i) & 1) u = fa[u][i];
	return u;
}

int which(int l, int r, int inl, int inr, int id)
{
	if (id < inl) return id - l;
	return id - l - (inr - inl + 1);
}

int get_sze(int u, int rt)
{
	if (dfn[rt] < dfn[u] || dfn[rt] >= dfn[u] + sze[u])
		return sze[u];
	if (u == rt) return n;
	return n - sze[jm(rt, dep[rt] - dep[u] - 1)];
}

int get_dfn(int u, int rt)
{
	if (u == rt) return 1;
	if (dfn[rt] <= dfn[u] && dfn[u] < dfn[rt] + sze[rt])
		return n - sze[rt] + dfn[u] - dfn[rt] + 1;
	int x = lca(u, rt), y;
	if (u == x) return dep[rt] - dep[u] + 1;
	int delta = dep[rt] - dep[x] + 1 + n - sze[x];
	y = jm(rt, dep[rt] - dep[x] - 1);
	return delta + which(dfn[x], dfn[x] + sze[x] - 1,
		dfn[y], dfn[y] + sze[y] - 1, dfn[u]);
}

inline bool comp(int a, int b)
{
	return xdfn[a] < xdfn[b];
}

int main()
{
	int x, y;
	n = read(); q = read();
	for (int i = 1; i < n; i++) x = read(), y = read(),
		add_edge(x, y);
	dfs(1, 0);
	f[0][0] = 1;
	while (q--)
	{
		k = read(); m = read(); r = read();
		for (int i = 1; i <= k; i++)
		{
			a[i] = read();
			xdfn[a[i]] = get_dfn(a[i], r);
			xsze[a[i]] = get_sze(a[i], r);
			change(xdfn[a[i]] + 1, xdfn[a[i]] + xsze[a[i]] - 1, 1);
			for (int j = 0; j <= m; j++) f[i][j] = 0;
		}
		std::sort(a + 1, a + k + 1, comp);
		for (int i = 1; i <= k; i++) cnt[i] = ask(xdfn[a[i]]);
		for (int i = 1; i <= k; i++)
			change(xdfn[a[i]] + 1, xdfn[a[i]] + xsze[a[i]] - 1, -1);
		for (int i = 0; i < k; i++) for (int j = 0; j <= m; j++)
		{
			if (!f[i][j]) continue;
			if (j < m) f[i + 1][j + 1] = (f[i + 1][j + 1] + f[i][j]) % ZZQ;
			f[i + 1][j] = (1ll * f[i][j] * (j - cnt[i + 1]) + f[i + 1][j]) % ZZQ;
		}
		int ans = 0;
		for (int i = 0; i <= m; i++) ans = (ans + f[k][i]) % ZZQ;
		printf("%d\n", ans);
	}
	return 0;
}