#include <bits/stdc++.h>

const int N = 1e6 + 5;

int n, p[N], ecnt = 1, nxt[N], adj[N], go[N], val[N];
bool vis[N], is[N], mark[N];
std::vector<int> a[N];

void add_edge(int u, int v, int w)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; val[ecnt] = w;
}

int pos(int x) {return x > n ? x - n : x;}

int main()
{
	int x;
	std::cin >> n;
	if (!(n & 1))
	{
		puts("First"); fflush(stdout);
		for (int i = 1; i <= n; i++) printf("%d ", i);
		for (int i = 1; i <= n; i++) printf("%d ", i);
		puts(""); fflush(stdout);
		scanf("%d", &x); return 0;
	}
	puts("Second"); fflush(stdout);
	for (int i = 1; i <= (n << 1); i++) scanf("%d", &p[i]);
	for (int i = 1; i <= (n << 1); i++) a[p[i]].push_back(i);
	for (int i = 1; i <= n; i++)
		add_edge(pos(a[i][0]), pos(a[i][1]), a[i][1]),
		add_edge(pos(a[i][1]), pos(a[i][0]), a[i][0]);
	for (int u = 1; u <= n; u++) if (!vis[u])
		for (int v = u; !vis[v];)
		{
			int w;
			for (int e = adj[v]; e; e = nxt[e])
				if (!mark[e]) {mark[e] = mark[e ^ 1] = 1; w = go[e];
					is[val[e]] = 1; break;}
			vis[v] = 1; v = w;
		}
	int sum = 0;
	for (int i = 1; i <= (n << 1); i++) if (is[i])
		sum = (sum + i) % (n << 1);
	for (int i = 1; i <= (n << 1); i++)
		if ((sum > 0) ^ is[i]) printf("%d ", i);
	return puts(""), fflush(stdout), scanf("%d", &x), 0;
}