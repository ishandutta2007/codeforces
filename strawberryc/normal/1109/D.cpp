#include <bits/stdc++.h>

// 20030830

const int N = 1e6 + 5, ZZQ = 1e9 + 7;

int n, m, fac[N], inv[N], ans, pm[N], pn[N];

int C(int n, int m)
{
	if (n < m) return 0;
	return 1ll * fac[n] * inv[m] % ZZQ * inv[n - m] % ZZQ;
}

int main()
{
	scanf("%d%d%*d%*d", &n, &m);
	fac[0] = inv[0] = inv[1] = pm[0] = pn[0] = 1;
	for (int i = 1; i <= n; i++) pm[i] = 1ll * pm[i - 1] * m % ZZQ;
	for (int i = 1; i <= n; i++) pn[i] = 1ll * pn[i - 1] * n % ZZQ;
	for (int i = 1; i <= n || i <= m; i++)
		fac[i] = 1ll * fac[i - 1] * i % ZZQ;
	for (int i = 2; i <= n || i <= m; i++)
		inv[i] = 1ll * (ZZQ - ZZQ / i) * inv[ZZQ % i] % ZZQ;
	for (int i = 2; i <= n || i <= m; i++)
		inv[i] = 1ll * inv[i] * inv[i - 1] % ZZQ;
	ans = 1ll * fac[n - 2] * C(m - 1, n - 2) % ZZQ;
	for (int i = 0; i < n - 2; i++)
		ans = (1ll * C(n - 2, i) * fac[i] % ZZQ * C(m - 1, i) % ZZQ
			* pm[n - 2 - i] % ZZQ * (i + 2) % ZZQ
			* pn[n - i - 3] + ans) % ZZQ;
	std::cout << ans << std::endl;
	return 0;
}