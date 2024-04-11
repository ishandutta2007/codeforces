#include <bits/stdc++.h>

const int N = 1e6 + 5, djq = 998244353;

int n, fac[N], inv[N], sl[N], sr[N], sL[N], sR[N], f[N], g[N], ans;
char s[N];

int C(int n, int m)
{
	return 1ll * fac[n] * inv[m] % djq * inv[n - m] % djq;
}

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	fac[0] = inv[0] = inv[1] = 1;
	for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % djq;
	for (int i = 2; i <= n; i++) inv[i] = 1ll * (djq - djq / i) * inv[djq % i] % djq;
	for (int i = 2; i <= n; i++) inv[i] = 1ll * inv[i] * inv[i - 1] % djq;
	for (int i = 1; i <= n; i++) sl[i] = sl[i - 1] + (s[i] == '('),
		sL[i] = sL[i - 1] + (s[i] == '?');
	for (int i = n; i >= 1; i--) sr[i] = sr[i + 1] + (s[i] == ')'),
		sR[i] = sR[i + 1] + (s[i] == '?');
	f[0] = g[0] = 1;
	for (int i = 1; i <= sL[n]; i++) f[i] = (f[i - 1] + C(sL[n], i)) % djq;
	for (int i = 1; i < sL[n]; i++) g[i] = (g[i - 1] + C(sL[n] - 1, i)) % djq;
	for (int i = 1; i <= n; i++) if (s[i] != ')')
	{
		int d = sr[i + 1] - sl[i - 1] - 1 + sR[i + 1], l = sL[i - 1] + sR[i + 1];
		if (d > l) d = l;
		if (d >= 0) ans = (ans + (s[i] == '?' ? g[d] : f[d])) % djq;
	}
	return std::cout << ans << std::endl, 0;
}