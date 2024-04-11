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

typedef long long ll;

const int N = 2e5 + 5, M = N << 1;

int n, ecnt, nxt[M], adj[N], go[M], sze[N], dep[N], c0, c1;
ll sum, ans;

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu)
{
	sze[u] = 1;
	if (dep[u] & 1) c1++; else c0++;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu)
			dep[v] = dep[u] + 1, dfs(v, u), sze[u] += sze[v];
}

int main()
{
	int x, y;
	n = read();
	for (int i = 1; i < n; i++)
		x = read(), y = read(), add_edge(x, y);
	dfs(1, 0);
	sum = 1ll * c0 * c1;
	for (int i = 2; i <= n; i++)
		ans += 1ll * (sze[i]) * (n - sze[i]);
	std::cout << (ans + sum >> 1) << std::endl;
	return 0;
}