#include <bits/stdc++.h>

typedef long long ll;

const int N = 16, C = (1 << 14) + 5;

int n, Cm, len[C], pl[C], tr[C];
char s[N][N];
ll ans[C], f[N][N], dp[C], cnt[N], pw[N];

void solve(int pro)
{
	memset(f, 0, sizeof(f)); memset(cnt, 0, sizeof(cnt));
	for (int u = 1; u <= n; u++) if (!((pro >> u - 1) & 1)) f[1][u] = 1;
	for (int T = 2; T <= n; T++)
		for (int u = 1; u <= n; u++) if (!((pro >> u - 1) & 1))
			for (int v = 1; v <= n; v++) if (!((pro >> v - 1) & 1) && s[u][v] == '1')
				f[T][v] += f[T - 1][u];
	for (int i = 1; i <= n; i++)
		for (int u = 1; u <= n; u++) cnt[i] += f[i][u];
	bool rev = 0;
	for (int u = 1; u <= n; u++) if ((pro >> u - 1) & 1) rev ^= 1;
	pw[0] = 1;
	for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * cnt[1];
	for (int S = 1; S < (1 << n - 1); S++)
	{
		if (pl[S] == len[S] + 1) dp[S] = cnt[len[S] + 1];
		else if (!tr[S]) dp[S] = cnt[pl[S]] * pw[len[S] - pl[S] + 1];
		else dp[S] = dp[tr[S]] * cnt[pl[S]] * pw[len[S] - pl[S] - len[tr[S]]];
		ans[S] += (rev ? -dp[S] : dp[S]) * pw[n - 1 - len[S]];
	}
	ans[0] += rev ? -pw[n] : pw[n];
}

int main()
{
	std::cin >> n;
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	Cm = 1 << n;
	for (int S = 1; S < Cm; S++)
	{
		for (int i = 1; i <= n; i++) if ((S >> i - 1) & 1) len[S] = i;
		pl[S] = len[S] + 1;
		for (int i = len[S]; i >= 1; i--)
			if (!((S >> i - 1) & 1)) {pl[S] = len[S] - i + 1; break;}
		if (pl[S] <= len[S]) tr[S] = S & (1 << len[S] - pl[S]) - 1;
	}
	for (int S = 0; S < Cm; S++) solve(S);
	Cm = 1 << n - 1;
	for (int k = 1; k < Cm; k <<= 1)
		for (int i = 0; i < Cm; i += k << 1)
			for (int j = 0; j < k; j++)
				ans[i + j] -= ans[i + j + k];
	for (int S = 0; S < Cm; S++) printf("%lld ", ans[S]);
	return puts(""), 0;
}