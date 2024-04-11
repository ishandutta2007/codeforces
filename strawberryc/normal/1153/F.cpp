#include <bits/stdc++.h>

const int N = 2005, M = N << 1, ZZQ = 998244353;

int n, k, l, f[M][N], g[M][N], ans;

int qpow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = 1ll * res * a % ZZQ;
		a = 1ll * a * a % ZZQ;
		b >>= 1;
	}
	return res;
}

inline int add(int &a, const int &b)
{
	a += b;
	if (a >= ZZQ) a -= ZZQ;
}

int main()
{
	std::cin >> n >> k >> l;
	f[0][0] = 1;
	for (int i = 1; i <= (n << 1); i++)
		for (int j = 0; j <= n; j++)
		{
			if (j)
			{
				add(f[i][j], f[i - 1][j - 1]);
				add(g[i][j], g[i - 1][j - 1]);
				if (j - 1 >= k) add(g[i][j], f[i - 1][j - 1]);
			}
			if (j < n)
			{
				add(f[i][j], 1ll * f[i - 1][j + 1] * (j + 1) % ZZQ);
				add(g[i][j], 1ll * g[i - 1][j + 1] * (j + 1) % ZZQ);
				if (j + 1 >= k) add(g[i][j], 1ll * f[i - 1][j + 1] * (j + 1) % ZZQ);
			}
		}
	std::cout << 1ll * qpow(f[n << 1][0], ZZQ - 2) * g[n << 1][0]
		% ZZQ * qpow(n << 1 | 1, ZZQ - 2) % ZZQ * l % ZZQ << std::endl;
	return 0;
}