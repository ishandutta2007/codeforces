#include <bits/stdc++.h>
#define mp std::make_pair

typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;

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

const int N = 45, M = 3e5 + 5, EI = 1e9 + 7;

int n, p[N], ToT, son[M][N], Root, f[M], C[N][N], g[N], h[N][N], fac[N];
vpii nums[M];
bool vis[N];

int dfs(int cur, vpii now)
{
	int u; nums[u = ++ToT] = now; vpii nxt = now;
	int lst = now.empty() ? 0 : now[now.size() - 1].first;
	for (int i = lst; i <= n - cur; i++) if (i)
	{
		if (i == lst) nxt[nxt.size() - 1].second++;
		else nxt.push_back(mp(i, 1));
		son[u][i] = dfs(cur + i, nxt);
		nxt = now;
	}
	return u;
}

void dfs_trans(int u, int dep, int v, int in, int out,
int now, vpii &trans)
{
	if (dep == nums[u].size())
	{
		if (u == v) return;
		trans.push_back(mp(1ll * now * h[out][in] % EI, v));
		return;
	}
	int x = nums[u][dep].second, y = nums[u][dep].first;
	for (int i = 0; i <= x; i++)
		dfs_trans(u, dep + 1, v, in, out, 1ll * now * C[x][i] % EI, trans),
			v = son[v][y], in += y, out -= y, now = EI - now;
}

int dp(int u)
{
	if (f[u] != -1) return f[u];
	if (u == Root) return f[u] = 1;
	vpii trans; int sze = 0, cnt = 0; f[u] = 0;
	for (int i = 0; i < nums[u].size(); i++)
		sze += nums[u][i].first * nums[u][i].second,
			cnt += nums[u][i].second;
	dfs_trans(u, 0, Root, 0, sze, cnt & 1 ? 1 : EI - 1, trans);
	for (int i = 0; i < trans.size(); i++)
		f[u] = (1ll * trans[i].first * dp(trans[i].second) + f[u]) % EI;
	return f[u];
}

int main()
{
	read(n); Root = dfs(0, vpii(0));
	for (int i = 1; i <= n; i++) read(p[i]);
	std::vector<int> cir;
	for (int i = 1; i <= n; i++) if (!vis[i])
	{
		int c = 0;
		for (int j = i; !vis[j]; j = p[j]) c++, vis[j] = 1;
		cir.push_back(c);
	}
	int u = 1;
	std::sort(cir.begin(), cir.end());
	for (int i = 0; i < cir.size(); i++) u = son[u][cir[i]];
	for (int i = 0; i <= n; i++) C[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % EI;
	memset(f, -1, sizeof(f)); fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % EI;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			g[i] = (1ll * fac[j] * fac[n - j - 1] % EI * C[i][j] + g[i]) % EI;
		h[0][i] = 1;
		for (int j = 1; j <= n; j++)
			h[j][i] = 1ll * h[j - 1][i] * g[i] % EI;
	}
	return std::cout << dp(u) << std::endl, 0;
}