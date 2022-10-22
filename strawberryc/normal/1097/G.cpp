#include <bits/stdc++.h>

// 0830

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
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 1e5 + 5, M = N << 1, E = 205, ZZQ = 1e9 + 7;

int n, k, ecnt, nxt[M], adj[N], go[M], S[E][E], f[N][E][2], sze[N], tmp[E][2],
res[E], ans;

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu)
{
	sze[u] = 1;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu)
		{
			dfs(v, u);
			for (int i = 0; i <= k; i++)
				tmp[i][0] = f[u][i][0], tmp[i][1] = f[u][i][1];
			for (int i = 0; i <= Min(k, sze[u] - 1); i++)
				for (int j = 0; j <= Min(k - i, sze[v] - 1); j++)
				{
					tmp[i + j][0] = (1ll * tmp[i + j][0]
						+ (!i) * (!j) + (!i) * f[v][j][0] * 2
						+ (!i) * f[v][j][1]) % ZZQ;
					tmp[i + j][1] = (1ll * tmp[i + j][1]
						+ f[u][i][0] * (!j) * 2 + f[u][i][1] * (!j)
						+ 4ll * f[u][i][0] * f[v][j][0]
						+ 2ll * f[u][i][0] * f[v][j][1]
						+ 2ll * f[u][i][1] * f[v][j][0]
						+ 1ll * f[u][i][1] * f[v][j][1]) % ZZQ;
					tmp[i + j + 1][0] = (1ll * tmp[i + j + 1][0]
						+ (!i) * (!j) + (!i) * f[v][j][0] * 2
						+ (!i) * f[v][j][1]) % ZZQ;
					tmp[i + j + 1][1] = (1ll * tmp[i + j + 1][1]
						+ f[u][i][0] * (!j) * 2 + f[u][i][1] * (!j)
						+ 4ll * f[u][i][0] * f[v][j][0]
						+ 2ll * f[u][i][0] * f[v][j][1]
						+ 2ll * f[u][i][1] * f[v][j][0]
						+ 1ll * f[u][i][1] * f[v][j][1]) % ZZQ;
				}
			sze[u] += sze[v];
			for (int i = 0; i <= Min(k, sze[u] - 1); i++)
				f[u][i][0] = tmp[i][0], f[u][i][1] = tmp[i][1];
		}
	for (int i = 0; i <= k; i++)
		res[i] = (1ll * res[i] + (!i) + f[u][i][0] + f[u][i][1]) % ZZQ;
}

int main()
{
	int x, y, fac = 1;
	n = read(); k = read();
	for (int i = 1; i < n; i++)
		x = read(), y = read(), add_edge(x, y);
	S[0][0] = 1;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= i; j++)
			S[i][j] = (1ll * j * S[i - 1][j] + S[i - 1][j - 1]) % ZZQ;
	dfs(1, 0);
	for (int i = 0; i <= k; i++)
	{
		ans = (1ll * S[k][i] * fac % ZZQ * res[i] + ans) % ZZQ;
		fac = 1ll * fac * (i + 1) % ZZQ;
	}
	return std::cout << ans << std::endl, 0;
}