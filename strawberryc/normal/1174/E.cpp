#include <bits/stdc++.h>

const int N = 1e6 + 5, M = N << 1, ZZQ = 1e9 + 7;

int n, d[N], ans, mxf, fac[M], inv[M], f[N], tot, pri[N];
bool mark[N];

void sieve()
{
	mark[0] = mark[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!mark[i]) pri[++tot] = i, d[i] = 1;
		for (int j = 1; j <= tot; j++)
		{
			if (1ll * i * pri[j] > n) break;
			mark[i * pri[j]] = 1;
			d[i * pri[j]] = d[i] + 1;
			if (i % pri[j] == 0) break;
		}
	}
	for (int i = 1; i <= n; i++) if (d[i] > mxf) mxf = d[i];
	fac[0] = inv[0] = inv[1] = 1;
	for (int i = 1; i <= (n << 1); i++)
		fac[i] = 1ll * fac[i - 1] * i % ZZQ;
	for (int i = 2; i <= (n << 1); i++)
		inv[i] = 1ll * (ZZQ - ZZQ / i) * inv[ZZQ % i] % ZZQ;
	for (int i = 2; i <= (n << 1); i++)
		inv[i] = 1ll * inv[i] * inv[i - 1] % ZZQ;
}

int C(int n, int m)
{
	return 1ll * fac[n] * inv[m] % ZZQ * inv[n - m] % ZZQ;
}

int main()
{
	std::cin >> n;
	sieve();
	f[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j += i) if (!mark[j / i])
		{
			int c1 = n / i - n / j, c2 = n - n / i;
			f[j] = (1ll * fac[c1] * C(c1 + c2 - 1, c2) % ZZQ
				* f[i] + f[j]) % ZZQ;
		}
		if (d[i] == mxf)
		{
			int c1 = n / i, c2 = n - n / i;
			ans = (1ll * fac[c1 - 1] * C(c1 + c2 - 1, c2) % ZZQ
				* f[i] + ans) % ZZQ;
		}
	}
	return std::cout << ans << std::endl, 0;
}