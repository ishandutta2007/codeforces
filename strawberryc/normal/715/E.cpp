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

const int N = 255, rqy = 998244353;

int n, p[N], q[N], cir, m, c, a, b, f[N][N], fac[N], C[N][N], ans[N],
g[N][N], con[N][N], nxt[N], pr, top[N];
bool in[N], vis[N];

int main()
{
	read(n); m = n;
	for (int i = 1; i <= n; i++) read(p[i]);
	for (int i = 1; i <= n; i++) read(q[i]);
	for (int i = 1; i <= n; i++)
		if (p[i] && q[i]) in[nxt[p[i]] = q[i]] = 1, m--;
		else if (!p[i] && !q[i]) pr++;
	for (int u = 1; u <= n; u++) if (!in[u])
		for (int v = u; v; v = nxt[v]) vis[v] = 1, top[v] = u;
	for (int u = 1; u <= n; u++) if (!vis[u])
	{
		cir++;
		for (int v = u; !vis[v]; v = nxt[v]) vis[v] = 1;
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++)
		if (p[i] && !q[i])
		{
			int x = top[p[i]];
			if (vis[x]) c++, b--; else a++, vis[x] = 1;
		}
		else if (q[i] && !p[i])
		{
			int x = top[q[i]];
			if (vis[x]) c++, a--; else b++, vis[x] = 1;
		}
	fac[0] = 1;
	for (int i = 0; i <= n; i++) C[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % rqy;
	for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % rqy;
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			f[i][j] = (1ll * (i - 1) * f[i - 1][j] + f[i - 1][j - 1]) % rqy;
	for (int i = 0; i <= c; i++)
		for (int j = 0; j <= i + a && j <= i + b; j++)
		{
			g[i][j] = 1ll * C[i + a][j] * C[i + b][j] % rqy * fac[j] % rqy;
			for (int k = 1; k <= i && k <= j; k++)
				g[i][j] = (g[i][j] - 1ll * C[i][k] * fac[k] % rqy
					* g[i - k][j - k] % rqy + rqy) % rqy;
		}
	for (int i = 0; i <= c; i++) for (int j = 0; j <= i; j++)
		for (int k = 0; k <= c - i + a && k <= c - i + b; k++)
			con[i + k][j] = (1ll * C[c][i] * f[i][j] % rqy *
				g[c - i][k] + con[i + k][j]) % rqy;
	for (int i = 0; i <= m; i++) for (int j = 0; j <= i; j++)
		for (int k = 0; k <= m - i; k++)
		{
			int delta = 1ll * con[i][j] * f[m - i][k] % rqy;
			if (i & 1) ans[cir + j + k] = (ans[cir + j + k] - delta + rqy) % rqy;
			else ans[cir + j + k] = (ans[cir + j + k] + delta) % rqy;
		}
	for (int i = n; i >= 1; i--) printf("%d ", 1ll * ans[i] * fac[pr] % rqy);
	return puts(""), 0;
}