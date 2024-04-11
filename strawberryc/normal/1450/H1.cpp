#include <bits/stdc++.h>

const int N = 2e5 + 5, EI = 998244353;

int n, m, fac[N], inv[N], ans, cnt, cnt0, cnt1, cnt_0, cnt_1;
char s[N];

int C(int n, int m)
{
	return 1ll * fac[n] * inv[m] % EI * inv[n - m] % EI;
}

int main()
{
	std::cin >> n >> m;
	fac[0] = inv[0] = inv[1] = 1;
	for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % EI;
	for (int i = 2; i <= n; i++) inv[i] = 1ll * (EI - EI / i) * inv[EI % i] % EI;
	for (int i = 2; i <= n; i++) inv[i] = 1ll * inv[i] * inv[i - 1] % EI;
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == '?') cnt++;
		if ((i & 1) && s[i] == 'w') cnt0++;
		if ((i & 1) && s[i] != 'b') cnt_0++;
		if (!(i & 1) && s[i] == 'b') cnt1++;
		if (!(i & 1) && s[i] != 'w') cnt_1++;
	}
	for (int i = 0; i <= n; i++) if ((2 * i - n) % 4 == 0)
	{
		if (cnt0 + cnt1 > i || i > cnt_0 + cnt_1) continue;
		ans = (1ll * abs(2 * i - n) / 4 * C(cnt_0 + cnt_1
			- cnt0 - cnt1, i - cnt0 - cnt1) + ans) % EI;
	}
	for (int i = 1; i < cnt; i++) ans = 499122177ll * ans % EI;
	return std::cout << ans << std::endl, 0;
}