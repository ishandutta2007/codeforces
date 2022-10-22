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

const int N = 85, INF = 0x3f3f3f3f;

int n, k, a[N][N], tot = 1, arr[N], ans = INF, f[N][N], d[N][N];
bool vis[N];

struct elem
{
	int v, d;
} eg[N][N][N];

inline bool comp(elem a, elem b)
{
	return a.d < b.d; 
}

int calcd(int u, int v)
{
	for (int i = 1; i <= n - 1 - (u != v); i++)
		if (!vis[eg[u][v][i].v]) return eg[u][v][i].d;
	return INF;
}

void check()
{
	for (int i = 1; i <= tot; i++)
		for (int j = 1; j <= tot; j++)
			d[i][j] = calcd(arr[i], arr[j]);
	for (int i = 0; i <= k; i++)
		for (int j = 1; j <= tot; j++)
			f[i][j] = INF;
	f[0][1] = 0;
	for (int i = 1; i <= k; i++)
		for (int u = 1; u <= tot; u++)
			for (int v = 1; v <= tot; v++)
				f[i][u] = std::min(f[i][u], f[i - 1][v] + d[v][u]);
	ans = std::min(ans, f[k][1]);
}

void dfs(int dep)
{
	if (dep > n) return check();
	if (tot < k) arr[++tot] = dep, vis[dep] = 1, dfs(dep + 1), vis[dep] = 0, tot--;
	dfs(dep + 1);
}

int main()
{
	vis[1] = 1; arr[1] = 1;
	read(n); read(k); k >>= 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			read(a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int tot = 0;
			for (int k = 1; k <= n; k++) if (i != k && j != k)
				eg[i][j][++tot] = (elem) {k, a[i][k] + a[k][j]};
			std::sort(eg[i][j] + 1, eg[i][j] + tot + 1, comp);
		}
	dfs(2);
	return std::cout << ans << std::endl, 0;
}