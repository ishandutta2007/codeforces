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

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 1e5 + 5, M = N << 1;

int n, ecnt, nxt[M], adj[N], go[M], f[N][2], ans, d[N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
	d[u]++; d[v]++;
}

void dfs(int u, int fu)
{
	bool is = 1; int f1 = -1, f2 = -1, f3 = -1, f4 = -1;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu)
		{
			dfs(v, u); is = 0;
			f[u][0] = Max(f[u][0], Max(f[v][0], f[v][1]));
			f[u][1] = Max(f[u][1], f[v][0]);
			if (f[v][0] > f1) f2 = f1, f1 = f[v][0];
			else if (f[v][0] > f2) f2 = f[v][0];
			if (Max(f[v][0], f[v][1]) > f3) f4 = f3, f3 = Max(f[v][0], f[v][1]);
			else if (Max(f[v][0], f[v][1]) > f4) f4 = Max(f[v][0], f[v][1]);
		}
	if (is) f[u][1] = 1;
	else f[u][0] += d[u] - 2, f[u][1]++, ans = Max(ans, f[u][0] + 1);
	ans = Max(ans, f[u][1]);
	if (f1 != -1 && f2 != -1) ans = Max(ans, Max(f1 + f2 + 1,
		f3 + f4 + d[u] - 2));
}

int main()
{
	int x, y;
	read(n);
	for (int i = 1; i < n; i++) read(x), read(y), add_edge(x, y);
	dfs(1, 0);
	return std::cout << ans << std::endl, 0;
}