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

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 2e5 + 5, E = 20, M = N << 1;
const ll INF = 1e18;

int n, q, ecnt, nxt[M], adj[N], go[M], dfn[N], ToT, fa[N][E], dep[N], vn, vir[M], rt,
top, par[N], stk[N], ecnt2, nxt2[M], adj2[N], go2[M], k, a[N], s[N], m, b[N], id[N];
bool vis[N], mark[N];

struct elem
{
	ll t; int d;
	
	friend inline bool operator < (elem a, elem b)
	{
		return a.t < b.t;
	}
} f[N], g[N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void add_edge2(int u, int v)
{
	nxt2[++ecnt2] = adj2[u]; adj2[u] = ecnt2; go2[ecnt2] = v;
	nxt2[++ecnt2] = adj2[v]; adj2[v] = ecnt2; go2[ecnt2] = u;
}

void dfs(int u, int fu)
{
	dfn[u] = ++ToT; dep[u] = dep[fa[u][0] = fu] + 1;
	for (int i = 0; i < 18; i++) fa[u][i + 1] = fa[fa[u][i]][i];
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu) dfs(v, u);
}

inline bool comp(int a, int b) {return dfn[a] < dfn[b];}

int lca(int u, int v)
{
	if (dep[u] < dep[v]) std::swap(u, v);
	for (int i = 18; i >= 0; i--)
		if (dep[fa[u][i]] >= dep[v])
			u = fa[u][i];
	if (u == v) return u;
	for (int i = 18; i >= 0; i--)
		if (fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}

void build()
{
	std::sort(vir + 1, vir + vn + 1, comp);
	vn = std::unique(vir + 1, vir + vn + 1) - vir - 1;
	top = 0;
	for (int i = 1, tn = vn; i <= tn; i++)
	{
		int u = vir[i];
		if (!top) {par[stk[++top] = u] = 0; continue;}
		int w = lca(u, stk[top]);
		while (dep[stk[top]] > dep[w])
		{
			if (dep[stk[top - 1]] < dep[w]) par[stk[top]] = w;
			top--;
		}
		if (stk[top] != w) par[w] = stk[top], stk[++top] = w, vir[++vn] = w;
		par[u] = w; stk[++top] = u;
	}
	ecnt2 = 0;
	for (int i = 1; i <= vn; i++) adj2[vir[i]] = 0;
	for (int i = 1; i <= vn; i++)
		if (par[vir[i]]) add_edge2(par[vir[i]], vir[i]);
		else rt = vir[i];
}

elem trav(elem f, int w)
{
	int x = s[(f.t - 1) % k + 1];
	if (f.d >= w) return (elem) {f.t, f.d - w};
	else return (elem) {f.t + 1ll * ((w - f.d + x - 1) / x) * k, (f.d - w % x + x) % x};
}

void dfs1(int u, int fu)
{
	f[u] = (elem) {id[u] ? id[u] : INF, 0};
	for (int e = adj2[u], v; e; e = nxt2[e])
		if ((v = go2[e]) != fu)
			dfs1(v, u), f[u] = Min(f[u], trav(f[v], abs(dep[v] - dep[u])));
}

void dfs2(int u, int fu)
{
	elem f1 = (elem) {INF, 0}, f2 = (elem) {INF, 0};
	for (int e = adj2[u], v; e; e = nxt2[e])
		if ((v = go2[e]) != fu)
		{
			elem fi = trav(f[v], abs(dep[v] - dep[u]));
			if (fi < f1) f2 = f1, f1 = fi;
			else if (fi < f2) f2 = fi;
		}
	if (fu)
	{
		elem fi = trav(g[u], abs(dep[u] - dep[fu]));
		if (fi < f1) f2 = f1, f1 = fi;
		else if (fi < f2) f2 = fi;
	}
	for (int e = adj2[u], v; e; e = nxt2[e])
	{
		if ((v = go2[e]) == fu) continue;
		if (id[u]) g[v] = (elem) {id[u], 0};
		else g[v] = trav(f[v], abs(dep[v] - dep[u])).t == f1.t ? f2 : f1;
		dfs2(v, u);
	}
}

int main()
{
	int x, y;
	read(n);
	for (int i = 1; i < n; i++) read(x), read(y), add_edge(x, y);
	dfs(1, 0); read(q);
	while (q--)
	{
		read(k); read(m); vn = 0;
		for (int i = 1; i <= k; i++) read(a[i]), read(s[i]), vir[++vn] = a[i];
		for (int i = 1; i <= m; i++) read(b[i]), vir[++vn] = b[i];
		build();
		for (int i = 1; i <= vn; i++) id[vir[i]] = 0;
		for (int i = 1; i <= k; i++) id[a[i]] = i;
		dfs1(rt, 0); g[rt] = (elem) {INF, 0}; dfs2(rt, 0);
		for (int i = 1; i <= m; i++) x = b[i], printf("%d ",
			(Min(trav(g[x], abs(dep[par[x]] - dep[x])), f[x]).t - 1) % k + 1);
		puts("");
	}
	return 0;
}