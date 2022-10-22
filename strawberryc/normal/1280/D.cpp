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

typedef long long ll;

const int N = 3005, M = N << 1;

int n, m, a[N], ecnt, nxt[M], adj[N], go[M], f[N][N], sze[N], tf[N];
ll s[N][N], ts[N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu)
{
	f[u][sze[u] = 1] = 0; s[u][1] = a[u];
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu)
		{
			dfs(v, u);
			for (int i = 1; i <= sze[u] + sze[v]; i++) tf[i] = -1;
			for (int i = 1; i <= sze[u]; i++)
				for (int j = 1; j <= sze[v]; j++)
				{
					int k = f[u][i] + f[v][j] + (s[v][j] > 0), w = f[u][i] + f[v][j];
					if (k > tf[i + j] || (k == tf[i + j] && s[u][i] > ts[i + j]))
						tf[i + j] = k, ts[i + j] = s[u][i];
					if (w > tf[i + j - 1] || (w == tf[i + j - 1]
						&& s[u][i] + s[v][j] > ts[i + j - 1]))
							tf[i + j - 1] = w, ts[i + j - 1] = s[u][i] + s[v][j];
				}
			sze[u] += sze[v];
			for (int i = 1; i <= sze[u]; i++) f[u][i] = tf[i], s[u][i] = ts[i];
		}
}

void work()
{
	int x, y;
	read(n); read(m); ecnt = 0;
	for (int i = 1; i <= n; i++) adj[i] = 0, read(a[i]), a[i] = -a[i];
	for (int i = 1; i <= n; i++) read(x), a[i] += x;
	for (int i = 1; i < n; i++) read(x), read(y), add_edge(x, y);
	dfs(1, 0);
	printf("%d\n", f[1][m] + (s[1][m] > 0));
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}