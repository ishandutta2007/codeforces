#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
#define Rof(i, a, b) for (i = a; i >= b; i--)
#define Step(i, a, b, x) for (i = a; i <= b; i += x)
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
inline void Swap(T &a, T &b) {a ^= b; b ^= a; a ^= b;}

typedef long long ll;

const int N = 2e5 + 5, M = N << 1, LogN = 20, ZZQ = 1e9 + 7;

int n, a[N], ecnt, nxt[M], adj[N], go[M], phi[N], tot, pri[N],
f[N], dfn[N], T, dep[N], fa[N][LogN], virn, vir[N], tn, tvir[N],
top, stk[N], sum[N], virfa[N], to[N], res[N], ans;
bool mark[N];

int qpow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = 1ll * res * a % ZZQ;
		a = 1ll * a * a % ZZQ;
		b >>= 1;
	}
	return res;
}

void sieve()
{
	int i, j;
	mark[0] = mark[phi[1] = f[1] = 1] = 1;
	For (i, 1, n)
	{
		if (!mark[i]) phi[pri[++tot] = i] = i - 1,
			f[i] = 1ll * i * qpow(i - 1, ZZQ - 2) % ZZQ;
		For (j, 1, tot)
		{
			if (1ll * i * pri[j] > n) break;
			mark[i * pri[j]] = 1;
			if (i % pri[j] == 0)
			{
				f[i * pri[j]] = f[i];
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			}
			else
			{
				phi[i * pri[j]] = phi[i] * (pri[j] - 1);
				f[i * pri[j]] = 1ll * f[i] * pri[j] % ZZQ *
					qpow(pri[j] - 1, ZZQ - 2) % ZZQ;
			}
		}
	}
}

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu)
{
	int i;
	dfn[u] = ++T;
	dep[u] = dep[fa[u][0] = fu] + 1;
	For (i, 0, 16) fa[u][i + 1] = fa[fa[u][i]][i];
	Tree(u) dfs(v, u);
}

int lca(int u, int v)
{
	if (dep[u] < dep[v]) Swap(u, v);
	int i;
	Rof (i, 17, 0)
	{
		if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
		if (u == v) return u;
	}
	Rof (i, 17, 0) if (fa[u][i] != fa[v][i])
		u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}

inline bool comp(int a, int b)
{
	return dfn[a] < dfn[b];
}

void build_virtree()
{
	int i;
	std::sort(vir + 1, vir + virn + 1, comp);
	tn = virn;
	For (i, 1, virn) tvir[i] = vir[i], sum[vir[i]] = phi[a[vir[i]]];
	top = 0;
	For (i, 1, tn)
	{
		int u = vir[i];
		if (!top) {virfa[stk[++top] = u] = 0; continue;}
		int w = lca(stk[top], u);
		while (dep[w] < dep[stk[top]])
		{
			if (dep[w] > dep[stk[top - 1]]) virfa[stk[top]] = w;
			top--;
		}
		if (w != stk[top]) virfa[w] = stk[top],
			stk[++top] = w, vir[++virn] = w, sum[w] = 0;
		virfa[stk[++top] = u] = w;
	}
	std::sort(vir + 1, vir + virn + 1, comp);
}

void DP(int x)
{
	int i;
	Rof (i, virn, 2) sum[virfa[vir[i]]] =
		(sum[virfa[vir[i]]] + sum[vir[i]]) % ZZQ;
	Rof (i, virn, 2) res[x] = (2ll * sum[vir[i]] * (sum[vir[1]] -
		sum[vir[i]] + ZZQ) % ZZQ * (dep[vir[i]] - dep[virfa[vir[i]]])
		+ res[x]) % ZZQ;
}

int main()
{
	int i, j, x, y;
	n = read();
	sieve();
	For (i, 1, n) to[a[i] = read()] = i;
	For (i, 1, n - 1) x = read(), y = read(), add_edge(x, y);
	dfs(1, 0);
	For (i, 1, n)
	{
		virn = 0;
		Step (j, i, n, i) vir[++virn] = to[j];
		build_virtree();
		DP(i);
	}
	Rof (i, n, 1) Step(j, (i << 1), n, i)
		res[i] = (res[i] - res[j] + ZZQ) % ZZQ;
	For (i, 1, n) ans = (1ll * res[i] * f[i] + ans) % ZZQ;
	std::cout << 1ll * ans * qpow(1ll * n * (n - 1) % ZZQ, ZZQ - 2) % ZZQ
		<< std::endl;
	return 0;
}