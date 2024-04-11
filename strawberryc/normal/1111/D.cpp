#include <cmath>
#include <cstdio>
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

const int N = 1e5 + 5, M = 52, ZZQ = 1e9 + 7;

int n, m, q, fac[N], inv[N], f[N], g[N], tmp[N], pmt[N], cnt[N], h[M][M];
char s[N];

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

int o(char c)
{
	if (c >= 'a' && c <= 'z') return c - 'a';
	return c - 'A' + 26;
}

void divi(int x, int dis1)
{
	for (int i = 0; i <= n; i++)
	{
		g[i] = f[i];
		if (i > n - dis1) tmp[i] = 0;
	}	
	for (int i = n; i >= dis1; i--)
	{
		tmp[i - dis1] = 1ll * x * g[i] % ZZQ;
		g[i - dis1] -= g[i];
		if (g[i - dis1] < 0) g[i - dis1] += ZZQ;
	}
	for (int i = 0; i <= n; i++) pmt[i] = tmp[i];
}

void ivid(int y, int dis2)
{
	for (int i = 0; i <= n; i++)
	{
		tmp[i] = pmt[i];
		if (i > n - dis2) g[i] = 0;
	}
	for (int i = n; i >= dis2; i--)
	{
		g[i - dis2] = 1ll * y * tmp[i] % ZZQ;
		tmp[i - dis2] -= tmp[i];
		if (tmp[i - dis2] < 0) tmp[i - dis2] += ZZQ;
	}
}

int main()
{
	int x, y;
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) cnt[o(s[i])]++;
	fac[0] = inv[0] = inv[1] = 1;
	for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % ZZQ;
	for (int i = 2; i <= n; i++)
		inv[i] = 1ll * (ZZQ - ZZQ / i) * inv[ZZQ % i] % ZZQ;
	for (int i = 2; i <= n; i++)
		inv[i] = 1ll * inv[i] * inv[i - 1] % ZZQ;
	m = n >> 1;
	q = read();
	f[0] = 1;
	for (int i = 0; i < 52; i++) if (cnt[i])
	{
		for (int j = cnt[i]; j <= n; j++)
			tmp[j] = 1ll * f[j - cnt[i]] * inv[cnt[i]] % ZZQ;
		for (int j = 0; j <= n; j++) f[j] = 1ll * f[j] * inv[cnt[i]] % ZZQ;
		for (int j = cnt[i]; j <= n; j++)
			f[j] = (f[j] + tmp[j]) % ZZQ;
	}
	for (int i = 0; i < 52; i++) if (cnt[i])
	{
		divi(fac[cnt[i]], cnt[i]);
		for (int j = i + 1; j < 52; j++) if (cnt[j])
		{
			ivid(fac[cnt[j]], cnt[j]);
			h[i][j] = h[j][i] = m - cnt[i] - cnt[j] < 0 ? 0 :
				g[m - cnt[i] - cnt[j]];
		}
	}
	while (q--)
	{
		x = o(s[read()]); y = o(s[read()]);
		if (x == y)
		{
			printf("%d\n", 1ll * f[m] * fac[m] % ZZQ * fac[m] % ZZQ);
			continue;
		}
		else printf("%d\n", 2ll * h[x][y] * inv[cnt[x]] % ZZQ
			* inv[cnt[y]] % ZZQ * fac[m] % ZZQ * fac[m] % ZZQ);
	}
	return 0;
}