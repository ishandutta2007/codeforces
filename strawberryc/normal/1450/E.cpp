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
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 205, M = 4005, INF = 0x3f3f3f3f;

int n, m, ecnt, nxt[M], adj[N], go[M], val[M], f[N][N], res[N], o[N], OO = -1;
bool vis[N], col[N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u)
{
	vis[u] = 1;
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		if (!vis[v]) col[v] = col[u] ^ 1, dfs(v);
		else if (col[v] == col[u]) {puts("NO"); exit(0);}
}

int main()
{
	memset(f, INF, sizeof(f));
	int x, y, z;
	read(n); read(m);
	for (int i = 1; i <= n; i++) f[i][i] = 0;
	while (m--)
	{
		read(x); read(y); read(z); add_edge(x, y);
		if (!z) f[x][y] = f[y][x] = 1;
		else f[x][y] = 1, f[y][x] = -1;
	}
	dfs(1);
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (1ll * f[i][k] + f[k][j] + f[j][i] < 0)
					return (void) puts("NO"), 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = Min(f[i][j], f[i][k] + f[k][j]);
	}
	for (int i = 1; i <= n; i++)
	{
		int mn = 0, mx = 0;
		for (int j = 1; j <= n; j++)
			mn = Min(mn, f[i][j]), mx = Max(mx, f[i][j]);
		OO = Max(OO, mx - mn); res[i] = mx - mn; o[i] = mn;
	}
	printf("YES\n%d\n", OO);
	for (int i = 1; i <= n; i++) if (res[i] == OO)
	{
		for (int j = 1; j <= n; j++) printf("%d ", f[i][j] - o[i]);
		puts(""); return 0;
	}
	return 0;
}