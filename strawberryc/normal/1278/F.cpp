#include <bits/stdc++.h>

const int N = 5005, rqy = 998244353;

int n, m, k, S[N][N], fac[N], inv[N], ans, p, now = 1;

int qpow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = 1ll * res * a % rqy;
		a = 1ll * a * a % rqy;
		b >>= 1;
	}
	return res;
}

int main()
{
	std::cin >> n >> m >> k;
	S[0][0] = fac[0] = inv[1] = 1;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= i; j++)
			S[i][j] = (1ll * j * S[i - 1][j] + S[i - 1][j - 1]) % rqy;
	for (int i = 1; i <= k; i++) fac[i] = 1ll * i * fac[i - 1] % rqy;
	for (int i = 2; i <= k; i++) inv[i] = 1ll * (rqy - rqy / i) * inv[rqy % i] % rqy;
	p = qpow(m, rqy - 2);
	for (int i = 0; i <= k; i++)
	{
		if (i) now = 1ll * now * (n - i + 1) % rqy * inv[i] % rqy * p % rqy;
		ans = (1ll * now * S[k][i] % rqy * fac[i] + ans) % rqy;
	}
	return std::cout << ans << std::endl, 0;
}