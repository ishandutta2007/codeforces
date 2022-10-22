#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
#define Tree(u) for (int e = adj[u], v; e; e = nxt[e]) if ((v = go[e]) != fu)

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

const int N = 1e5 + 5, M = N << 1, L = 1e7 + 5, INF = 0x3f3f3f3f;

int n, r, a[N], ecnt, nxt[M], adj[N], go[M], m, lst, dfn[N], low[N],
dep[N], pos[N], QwQ, rt[N], ToT, sze[N];

struct tree
{
	int dep, u;
} tr[N];

struct node
{
	int lc, rc, val;
} T[L];

void ins(int y, int &x, int l, int r, int p, int val)
{
	T[x = ++ToT] = T[y]; T[x].val = Min(T[x].val, val);
	if (l == r) return;
	int mid = l + r >> 1;
	if (p <= mid) ins(T[y].lc, T[x].lc, l, mid, p, val);
	else ins(T[y].rc, T[x].rc, mid + 1, r, p, val);
}

int query(int l, int r, int s, int e, int p)
{
	if (l == s && r == e) return T[p].val;
	int mid = l + r >> 1;
	if (e <= mid) return query(l, mid, s, e, T[p].lc);
	else if (s >= mid + 1) return query(mid + 1, r, s, e, T[p].rc);
	else return Min(query(l, mid, s, mid, T[p].lc),
		query(mid + 1, r, mid + 1, e, T[p].rc));
}

inline bool comp(tree a, tree b)
{
	return a.dep < b.dep;
}

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu)
{
	dfn[u] = ++QwQ;
	dep[u] = dep[fu] + 1;
	tr[u] = (tree) {dep[u], u};
	sze[u] = 1;
	Tree(u) dfs(v, u), sze[u] += sze[v];
}

int main()
{
	T[0].val = INF;
	int i, x, y;
	n = read(); r = read();
	For (i, 1, n) a[i] = read();
	For (i, 1, n - 1) x = read(), y = read(), add_edge(x, y);
	dfs(r, 0);
	std::sort(tr + 1, tr + n + 1, comp);
	For (i, 1, n) ins(rt[i - 1], rt[i], 1, n, dfn[tr[i].u], a[tr[i].u]),
		pos[tr[i].dep] = i;
	m = read();
	while (m--)
	{
		x = (read() + lst) % n + 1; y = (read() + lst) % n;
		printf("%d\n", lst = query(1, n, dfn[x], dfn[x] + sze[x] - 1,
			rt[pos[Min(dep[x] + y, tr[n].dep)]]));
	}
	return 0;
}