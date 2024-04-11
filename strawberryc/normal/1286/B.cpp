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

const int N = 2005;

int n, ecnt, nxt[N], adj[N], go[N], sze[N], c[N], rt, a[N];
bool flag;

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
}

void calcsze(int u)
{
	sze[u] = 1;
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		calcsze(v), sze[u] += sze[v];
	if (c[u] >= sze[u]) flag = 1;
}

void dfs(int u, std::vector<int> val)
{
	a[u] = val[c[u]];
	int tx = 0;
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
	{
		std::vector<int> nxt;
		for (int i = 0; i < sze[v]; i++)
		{
			if (tx == c[u]) tx++; nxt.push_back(val[tx]);
			tx++;
		}
		dfs(v, nxt);
	}
}

int main()
{
	int x;
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(x); read(c[i]);
		if (x) add_edge(x, i);
		else rt = i;
	}
	calcsze(rt);
	if (flag) return puts("NO"), 0;
	std::vector<int> init;
	for (int i = 1; i <= n; i++) init.push_back(i);
	dfs(rt, init);
	puts("YES");
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	return puts(""), 0;
}