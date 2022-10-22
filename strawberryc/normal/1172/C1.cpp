#include <bits/stdc++.h>

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 2e5 + 5, M = 3005, ZZQ = 998244353;

int n, m, a[N], b[N], s0, s1, f[M][M], ft, tft, tfmt, i0, i1;

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

int main()
{
	n = read(); m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++)
	{
		b[i] = read();
		if (a[i]) s1 += b[i];
		else s0 += b[i];
	}
	f[0][0] = 1;
	for (int i = 0; i < m; i++)
		for (int j = 0; j <= i; j++)
		{
			int it = qpow(s0 - j + s1 + i - j, ZZQ - 2);
			f[i + 1][j] = (1ll * (s1 + i - j) * it % ZZQ *
				f[i][j] + f[i + 1][j]) % ZZQ;
			f[i + 1][j + 1] = (1ll * (s0 - j) * it % ZZQ *
				f[i][j] + f[i + 1][j + 1]) % ZZQ;
		}
	for (int i = 0; i <= m; i++)
	{
		ft = (ft + f[m][i]) % ZZQ;
		tft = (1ll * i * f[m][i] + tft) % ZZQ;
		tfmt = (1ll * (m - i) * f[m][i] + tfmt) % ZZQ;
	}
	i0 = qpow(s0, ZZQ - 2); i1 = qpow(s1, ZZQ - 2);
	for (int i = 1; i <= n; i++)
		if (a[i]) printf("%d\n", (1ll * b[i] * ft + 1ll * b[i]
			* i1 % ZZQ * tfmt) % ZZQ);
		else printf("%d\n", (1ll * b[i] * ft - 1ll * b[i]
			* i0 % ZZQ * tft % ZZQ + ZZQ) % ZZQ);
	return 0;
}