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

const int N = 60, djq = 998244353, i2 = 499122177;

int n, m, orz = 1, cnt1, p[N], cnt0, cnt[N], ans[N], C[N][N];
ll b[N], a[N];

void ins(ll x)
{
	for (int i = m - 1; i >= 0; i--)
	{
		if (!((x >> i) & 1)) continue;
		if (b[i] == -1) return (void) (b[i] = x);
		else x ^= b[i];
	}
	orz = (orz << 1) % djq;
}

void dfs(int dep, int tar, ll T)
{
	if (dep == tar + 1) return (void) (ans[__builtin_popcountll(T)]++);
	dfs(dep + 1, tar, T); dfs(dep + 1, tar, T ^ a[dep]);
}

int main()
{
	ll x;
	read(n); read(m);
	for (int i = 0; i < m; i++) b[i] = -1;
	for (int i = 1; i <= n; i++) read(x), ins(x);
	for (int i = 0; i < m; i++) if (b[i] != -1)
		for (int j = i + 1; j < m; j++)
			if (b[j] != -1 && ((b[j] >> i) & 1)) b[j] ^= b[i];
	for (int i = 0; i < m; i++) if (b[i] != -1) a[++cnt1] = b[i];
	if (cnt1 <= 26) dfs(1, cnt1, 0);
	else
	{
		for (int i = 0; i < m; i++) if (b[i] == -1)
		{
			a[++cnt0] = 1ll << i;
			for (int j = i + 1; j < m; j++) if (b[j] != -1 && ((b[j] >> i) & 1))
				a[cnt0] |= 1ll << j;
		}
		dfs(1, cnt0, 0);
		for (int i = 0; i <= m; i++) cnt[i] = ans[i], ans[i] = 0, C[i][0] = 1;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= i; j++)
				C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % djq;
		int I = 1;
		for (int i = 1; i <= cnt0; i++) I = 1ll * I * i2 % djq;
		for (int i = 0; i <= m; i++)
			for (int j = 0; j <= m; j++)
			{
				int pl = 0;
				for (int k = 0; k <= j && k <= i; k++)
				{
					int delta = 1ll * C[j][k] * C[m - j][i - k] % djq;
					if (k & 1) pl = (pl - delta + djq) % djq;
					else pl = (pl + delta) % djq;
				}
				ans[i] = (1ll * I * pl % djq * cnt[j] + ans[i]) % djq;
			}
	}
	for (int i = 0; i <= m; i++) printf("%d ", 1ll * ans[i] * orz % djq);
	return puts(""), 0;
}