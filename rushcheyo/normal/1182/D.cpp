#include <bits/stdc++.h>
using namespace std;
const int BASE[2] = {99259, 99277}, MOD[2] = {1000000007, 1000000009};
int n, fh[2][100001], gh[2][100001];
vector<int> e[100001], son[100001];
bool f[100001], g[100001];
vector<bool> pre[100001], suf[100001];
void dfs1(int u, int fa)
{
	for (int v : e[u])
		if (v != fa)
		{
			son[u].push_back(v);
			dfs1(v, u);
		}
	if (!son[u].empty())
	{
		pre[u].resize(son[u].size());
		suf[u].resize(son[u].size());
		pre[u][0] = f[son[u][0]];
		for (int i = 1; i < (int)son[u].size(); ++i)
			pre[u][i] = pre[u][i - 1] && f[son[u][i]] && e[son[u][i]].size() == e[son[u][i - 1]].size() && fh[0][son[u][i]] == fh[0][son[u][i - 1]] && fh[1][son[u][i]] == fh[1][son[u][i - 1]];
		if (pre[u].back())
		{
			f[u] = true;
			for (int x = 0; x < 2; ++x)
				fh[x][u] = (1ll * fh[x][son[u][0]] * BASE[x] + e[son[u][0]].size()) % MOD[x];
		}
		suf[u][son[u].size() - 1] = f[son[u].back()];
		for (int i = (int)son[u].size() - 2; i >= 0; --i)
			suf[u][i] = suf[u][i + 1] && f[son[u][i]] && e[son[u][i]].size() == e[son[u][i + 1]].size() && fh[0][son[u][i]] == fh[0][son[u][i + 1]] && fh[1][son[u][i]] == fh[1][son[u][i + 1]];
	}
	else
		f[u] = true;
}
void dfs2(int u)
{
	for (int i = 0; i < (int)son[u].size(); ++i)
	{
		if (son[u].size() == 1)
		{
			g[son[u][i]] = g[u];
			if (g[son[u][i]])
				for (int x = 0; x < 2; ++x)
					gh[x][son[u][i]] = (1ll * gh[x][u] * BASE[x] + e[u].size()) % MOD[x];
		}
		else
		{
			g[son[u][i]] = g[u] && (i == 0 ? true : pre[u][i - 1]) && (i + 1 == (int)son[u].size() ? true : suf[u][i + 1]);
			if (g[son[u][i]])
			{
				if (i == 0 || i + 1 == (int)son[u].size())
				{
					for (int x = 0; x < 2; ++x)
						gh[x][son[u][i]] = (1ll * fh[x][son[u][!i]] * BASE[x] + e[son[u][!i]].size()) % MOD[x];
				}
				else
				{
					int lh[2] = {}, rh[2] = {};
					for (int x = 0; x < 2; ++x)
					{
						lh[x] = (1ll * fh[x][son[u][i - 1]] * BASE[x] + e[son[u][i - 1]].size()) % MOD[x];
						rh[x] = (1ll * fh[x][son[u][i + 1]] * BASE[x] + e[son[u][i + 1]].size()) % MOD[x];
					}
					if (lh[0] == rh[0] && lh[1] == rh[1])
					{
						for (int x = 0; x < 2; ++x)
							gh[x][son[u][i]] = lh[x];
					}
					else g[son[u][i]] = false;
				}
				if (g[son[u][i]])
				{
					if (u == 1 || (gh[0][son[u][i]] == gh[0][u] && gh[1][son[u][i]] == gh[1][u]))
					{
						for (int x = 0; x < 2; ++x)
							gh[x][son[u][i]] = (1ll * gh[x][son[u][i]] * BASE[x] + e[u].size()) % MOD[x];
					}
					else
						g[son[u][i]] = false;
				}
			}
		}
		dfs2(son[u][i]);
	}
	if ((son[u].empty() && g[u]) || (u == 1 && f[u]) || (f[u] && g[u] && fh[0][u] == gh[0][u] && fh[1][u] == gh[1][u]))
		printf("%d\n", u), exit(0);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; ++i)
	{
		scanf("%d%d", &u, &v);
		e[u].push_back(v), e[v].push_back(u);
	}
	dfs1(1, 0);
	g[1] = true;
	dfs2(1);
	puts("-1");
	return 0;
}