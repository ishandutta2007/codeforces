#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 1e6 + 5, M = 5005;

int n, m, ZZQ, l[N], maxl, fac[M], A[M], g[M][M], sum[N];

std::vector<int> f[N];

int main()
{
	n = read(); m = read(); ZZQ = read();
	for (int i = 1; i <= n; i++)
		maxl = Max(maxl, l[i] = read());
	g[0][0] = A[0] = fac[0] = 1;
	for (int i = 1; i <= maxl; i++)
	{
		fac[i] = 1ll * fac[i - 1] * i % ZZQ;
		A[i] = 1ll * A[i - 1] * (m - i + 1) % ZZQ;
	}
	for (int i = 1; i <= maxl; i++)
		for (int j = 1; j <= i; j++)
			g[i][j] = (1ll * (j - 1) * g[i - 1][j] + g[i - 1][j - 1]) % ZZQ;
	f[1].push_back(0);
	for (int i = 1; i <= l[1]; i++)
	{
		f[1].push_back(1);
		sum[1] = (1ll * g[l[1]][i] * A[i] % ZZQ * f[1][i] + sum[1]) % ZZQ;
	}
	for (int i = 2; i <= n; i++)
	{
		f[i].push_back(0);
		for (int j = 1; j <= l[i]; j++)
		{
			int res = sum[i - 1];
			if (j <= l[i - 1]) res = (res - 1ll * f[i - 1][j] *
				fac[j] % ZZQ * g[l[i - 1]][j] % ZZQ + ZZQ) % ZZQ;
			f[i].push_back(res);
			sum[i] = (1ll * g[l[i]][j] * A[j] % ZZQ * f[i][j] + sum[i]) % ZZQ;
		}
	}
	std::cout << sum[n] << std::endl;
	return 0;
}