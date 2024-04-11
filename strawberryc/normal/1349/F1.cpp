#include <bits/stdc++.h>

const int N = 5005, djq = 998244353;

int n, f[N][N], fac[N];

int main()
{
	std::cin >> n;
	f[1][0] = fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * (n - i + 1) % djq;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
		{
			f[i + 1][j] = (1ll * (j + 1) * f[i][j] + f[i + 1][j]) % djq;
			f[i + 1][j + 1] = (1ll * (i - j) * f[i][j] + f[i + 1][j + 1]) % djq;
		}
	for (int k = 1; k <= n; k++)
	{
		int ans = 0;
		for (int i = k; i <= n; i++)
			ans = (1ll * f[i][k - 1] * fac[n - i] + ans) % djq;
		printf("%d ", ans);
	}
	return puts(""), 0;
}