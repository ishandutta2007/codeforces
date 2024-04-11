#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define p2 p << 1
#define p3 p << 1 | 1

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

const int N = 5e5 + 5, M = N << 2;
const ll INF = 1e18;

int n, q, sze[N], p = 1;
ll dis[N], mindis[M], add[M], ans[N];

std::vector<int> tree[N], val[N];

void add_edge(int u, int v, int w)
{
	tree[u].push_back(v); val[u].push_back(w);
}

struct query
{
	int u, l, r, id;
} a[N];

inline bool comp(query a, query b)
{
	return a.u < b.u;
}

void dfs(int u)
{
	sze[u] = 1;
	int sz = tree[u].size(), tt = 0;
	for (int i = 0; i < sz; i++)
	{
		tt++;
		int v = tree[u][i];
		dis[v] = dis[u] + val[u][i];
		dfs(v);
		sze[u] += sze[v];
	}
	if (tt) dis[u] = INF;
}

void build(int l, int r, int p)
{
	if (l == r) return (void) (mindis[p] = dis[l]);
	int mid = l + r >> 1;
	build(l, mid, p2); build(mid + 1, r, p3);
	mindis[p] = Min(mindis[p2], mindis[p3]);
}

void down(int p)
{
	add[p2] += add[p]; add[p3] += add[p];
	add[p] = 0;
}

void upt(int p)
{
	mindis[p] = Min(mindis[p2] + add[p2], mindis[p3] + add[p3]);
}

void change(int l, int r, int s, int e, int v, int p)
{
	if (l == s && r == e) return (void) (add[p] += v);
	int mid = l + r >> 1; down(p);
	if (e <= mid) change(l, mid, s, e, v, p2);
	else if (s > mid) change(mid + 1, r, s, e, v, p3);
	else change(l, mid, s, mid, v, p2),
		change(mid + 1, r, mid + 1, e, v, p3);
	upt(p);
}

ll ask(int l, int r, int s, int e, int p)
{
	if (l == s && r == e) return mindis[p] + add[p];
	int mid = l + r >> 1; down(p); ll res;
	if (e <= mid) res = ask(l, mid, s, e, p2);
	else if (s > mid) res = ask(mid + 1, r, s, e, p3);
	else res = Min(ask(l, mid, s, mid, p2), ask(mid + 1, r, mid + 1, e, p3));
	return upt(p), res;
}

void dfs_solve(int u)
{
	while (p <= q && a[p].u <= u)
		ans[a[p].id] = ask(1, n, a[p].l, a[p].r, 1), p++;
	int sz = tree[u].size();
	for (int i = 0; i < sz; i++)
	{
		int v = tree[u][i], w = val[u][i];
		change(1, n, v, v + sze[v] - 1, -w, 1);
		if (1 < v) change(1, n, 1, v - 1, w, 1);
		if (v + sze[v] <= n) change(1, n, v + sze[v], n, w, 1);
		dfs_solve(v);
		change(1, n, v, v + sze[v] - 1, w, 1);
		if (1 < v) change(1, n, 1, v - 1, -w, 1);
		if (v + sze[v] <= n) change(1, n, v + sze[v], n, -w, 1);
	}
}

int main()
{
	int x, y, z;
	n = read(); q = read();
	for (int i = 2; i <= n; i++)
		x = read(), y = read(), add_edge(x, i, y);
	for (int i = 1; i <= q; i++)
		x = read(), y = read(), z = read(), a[i] = (query) {x, y, z, i};
	std::sort(a + 1, a + q + 1, comp);
	dfs(1);
	build(1, n, 1);
	dfs_solve(1);
	for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
	return 0;
}