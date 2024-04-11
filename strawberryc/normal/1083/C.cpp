#include <bits/stdc++.h>
#define p2 p << 1
#define p3 p << 1 | 1

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

const int N = 2e5 + 5, M = N << 2, E = 20;

int n, p[N], q[N], ecnt, nxt[N], adj[N], go[N], m, tot, dep[N] = {0, 1},
dfn[N], RMQ[N][E], Log[N] = {-1}, sze[N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
}

void dfs(int u)
{
	dfn[u] = ++tot; sze[u] = 1;
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		RMQ[tot + 1][0] = u, dep[v] = dep[u] + 1, dfs(v), sze[u] += sze[v];
}

int lca(int u, int v)
{
	if (u == v) return u;
	if (dfn[u] > dfn[v]) std::swap(u, v);
	int l = dfn[u] + 1, r = dfn[v], k = Log[r - l + 1];
	return dep[RMQ[l][k]] < dep[RMQ[r - (1 << k) + 1][k]]
		? RMQ[l][k] : RMQ[r - (1 << k) + 1][k];
}

bool subt(int u, int v) {return dfn[u] <= dfn[v] && dfn[v] < dfn[u] + sze[u];}

bool in(int u, int v, int w)
{
	return (subt(w, u) ^ subt(w, v)) || w == lca(u, v);
}

struct path
{
	int u, v;
	
	friend inline path operator + (path a, path b)
	{
		if (!a.u) return b; if (!b.v) return a;
		if (a.u == -1 || b.v == -1) return (path) {-1, -1};
		if (in(a.u, a.v, b.u) && in(a.u, a.v, b.v)) return a;
		if (in(b.u, b.v, a.u) && in(b.u, b.v, a.v)) return b;
		if (in(a.u, b.v, a.v) && in(a.u, b.v, b.u)) return (path) {a.u, b.v};
		if (in(a.u, b.u, a.v) && in(a.u, b.u, b.v)) return (path) {a.u, b.u};
		if (in(a.v, b.v, a.u) && in(a.v, b.v, b.u)) return (path) {a.v, b.v};
		if (in(a.v, b.u, a.u) && in(a.v, b.u, b.v)) return (path) {a.v, b.u};
		return (path) {-1, -1};
	}
} T[M];

void build(int l, int r, int p)
{
	if (l == r) return (void) (T[p] = (path) {q[l], q[r]});
	int mid = l + r >> 1;
	build(l, mid, p2); build(mid + 1, r, p3);
	T[p] = T[p2] + T[p3];
}

void change(int l, int r, int pos, int v, int p)
{
	if (l == r) return (void) (T[p] = (path) {v, v});
	int mid = l + r >> 1;
	if (pos <= mid) change(l, mid, pos, v, p2);
	else change(mid + 1, r, pos, v, p3);
	T[p] = T[p2] + T[p3];
}

int ask(int l, int r, path x, int p)
{
	if (l == r) return (x + T[p]).u == -1 ? l - 1 : l;
	int mid = l + r >> 1;
	if ((x + T[p2]).u == -1) return ask(l, mid, x, p2);
	else return ask(mid + 1, r, x + T[p2], p3);
}

int main()
{
	int op, x, y;
	read(n);
	for (int i = 1; i <= n; i++) read(p[i]), q[++p[i]] = i;
	for (int i = 2; i <= n; i++) read(x), add_edge(x, i);
	dfs(1);
	for (int i = 1; i <= n; i++) Log[i] = Log[i >> 1] + 1;
	for (int j = 1; j <= 17; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			RMQ[i][j] = dep[RMQ[i][j - 1]] < dep[RMQ[i + (1 << j - 1)][j - 1]]
				? RMQ[i][j - 1] : RMQ[i + (1 << j - 1)][j - 1];
	build(1, n, 1);
	read(m);
	while (m--)
	{
		read(op);
		if (op == 1)
		{
			read(x); read(y);
			if (x != y) std::swap(p[x], p[y]),
				change(1, n, p[x], x, 1), change(1, n, p[y], y, 1),
					std::swap(q[p[x]], q[p[y]]);
		}
		else printf("%d\n", ask(1, n, (path) {0, 0}, 1));
	}
	return 0;
}