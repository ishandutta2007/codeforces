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

typedef long long ll;

const int N = 2e5 + 5, M = N << 1;

int n, ecnt, nxt[M], adj[N], go[M], val[M], sze[N];
ll sna, ans;

void add_edge(int u, int v, int w)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; val[ecnt] = w;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u; val[ecnt] = w;
}

void dfs(int u, int fu, ll d)
{
	sze[u] = 1; int cnt = 1; sna += d;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu) dfs(v, u, d + val[e]), sze[u] += sze[v],
			ans += 1ll * val[e] * std::min(sze[v], (n << 1) - sze[v]),
				cnt += sze[v] & 1;
	sna -= 1ll * d * (cnt - (sze[u] & 1));
}

void work()
{
	int x, y, z;
	read(n);
	ecnt = 0;
	for (int i = 1; i <= (n << 1); i++) adj[i] = 0;
	for (int i = 1; i < (n << 1); i++)
		read(x), read(y), read(z), add_edge(x, y, z);
	sna = ans = 0;
	dfs(1, 0, 0);
	printf("%lld %lld\n", sna, ans);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}