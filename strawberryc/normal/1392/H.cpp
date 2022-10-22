#include <bits/stdc++.h>

const int N = 4e6 + 5, EI = 998244353;

int n, m, fac[N], inv[N], invf[N], E, ans;

int C(int n, int m)
{
	return 1ll * fac[n] * invf[m] % EI * invf[n - m] % EI;
}

int iC(int n, int m)
{
	return 1ll * invf[n] * fac[m] % EI * fac[n - m] % EI;
}

int main()
{
	std::cin >> n >> m;
	fac[0] = inv[1] = invf[0] = 1;
	for (int i = 1; i <= n + m; i++) fac[i] = 1ll * fac[i - 1] * i % EI;
	for (int i = 2; i <= n + m; i++)
		inv[i] = 1ll * (EI - EI / i) * inv[EI % i] % EI;
	for (int i = 1; i <= n + m; i++)
		invf[i] = 1ll * inv[i] * invf[i - 1] % EI;
	for (int i = 0; i <= n; i++)
		E = (1ll * C(n, i) * iC(n + m, i) + E) % EI;
	for (int i = 1; i <= n; i++)
	{
		int res = 1ll * C(n, i) * (m + i) % EI * inv[i] % EI;
		if (i & 1) ans = (ans + res) % EI;
		else ans = (ans - res + EI) % EI;
	}
	return std::cout << 1ll * ans * E % EI << std::endl, 0;
}