#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
#define Edge(u) for (int e = adj[u], v; e; e = nxt[e]) if ((v = go[e]) != fu)

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 1e5 + 5, M = N << 1;

int n, ecnt, nxt[M], adj[N], go[M], dep[N];
double ans;

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu)
{
	dep[u] = dep[fu] + 1;
	ans += 1.0 / dep[u];
	Edge(u) dfs(v, u);
}

int main()
{
	int i, x, y;
	n = read();
	For (i, 1, n - 1) x = read(), y = read(), add_edge(x, y);
	printf("%.14lf\n", (dfs(1, 0), ans));
	return 0;
}