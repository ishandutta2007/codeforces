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

typedef __int128 ull;

const int N = 3e5 + 5, M = N << 1, E = 20, L = N * E;

int n, q, a[N], ecnt, nxt[M], adj[N], go[M], rt[N], ToT, fa[N][E], dep[N];
ull val[N];

struct node
{
	int lc, rc; ull num;
} T[L];

void ins(int y, int &x, int l, int r, int p, ull v)
{
	T[x = ++ToT] = T[y]; T[x].num ^= v; if (l == r) return;
	int mid = l + r >> 1;
	if (p <= mid) ins(T[y].lc, T[x].lc, l, mid, p, v);
	else ins(T[y].rc, T[x].rc, mid + 1, r, p, v);
}

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu)
{
	dep[u] = dep[fa[u][0] = fu] + 1;
	for (int i = 0; i < 18; i++) fa[u][i + 1] = fa[fa[u][i]][i];
	ins(rt[fu], rt[u], 1, n, a[u], val[a[u]]);
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu) dfs(v, u);
}

int lca(int u, int v)
{
	if (dep[u] < dep[v]) std::swap(u, v);
	for (int i = 18; i >= 0; i--)
		if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	if (u == v) return u;
	for (int i = 18; i >= 0; i--)
		if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}

int jiejuediao(int x, int y, int z, int u, int l, int r, int s, int e)
{
	if (e < l || s > r) return -1;
	if (s <= l && r <= e && !(T[x].num ^ T[y].num ^ T[z].num ^ T[u].num)) return -1;
	if (l == r) return l;
	int mid = l + r >> 1, tmp = jiejuediao(T[x].lc, T[y].lc, T[z].lc, T[u].lc,
		l, mid, s, e);
	if (tmp != -1) return tmp;
	return jiejuediao(T[x].rc, T[y].rc, T[z].rc, T[u].rc, mid + 1, r, s, e);
}

int main()
{
	int x, y, l, r;
	srand(20050131);
	read(n); read(q);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++)
		for (int T = 110; T > 0; T--)
			val[i] = val[i] << 1 | (rand() & 1);
	for (int i = 1; i < n; i++) read(x), read(y), add_edge(x, y);
	dfs(1, 0);
	while (q--)
	{
		read(x); read(y); read(l); read(r);
		int z = lca(x, y);
		printf("%d\n", jiejuediao(rt[x], rt[y], rt[z], rt[fa[z][0]], 1, n, l, r));
	}
	return 0;
}