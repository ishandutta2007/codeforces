#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
inline int	read()
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')  positive = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
#define link Link
#define next Next
#define elif else if

const int MOD = 998244353;
int N, M;
LL	gg;
LL	f[400005], g[400005];
LL	a[4000006], b[4000006], c[4000006], d[4000006], W[2][4000006];
int pos[4000006];

inline LL	power(LL x, int y)
{
	LL	ans = 1;
	for (; y; y >>= 1)
	{
		if (y & 1)	ans = ans * x % MOD;
		x = x * x % MOD;
	}
	return ans;
}

LL	e[4000006];

inline void	DFT(bool t, LL a[], int S)
{
	for (int i = 0; i < S; ++ i)
		if (i < pos[i])
			swap(a[i], a[pos[i]]);
	for (int i = 1; i < S; i <<= 1)
		for (int j = 0; j < S; j += 2 * i)
			for (int k = 0; k < i; ++ k)
			{
				LL u = a[j + k], v = a[i + j + k] * W[t][k * (S / i) / 2] % MOD;
				a[j + k] = u + v;
				if (a[j + k] >= MOD)	a[j + k] -= MOD;
				a[i + j + k] = u - v;
				if (a[i + j + k] < 0)	a[i + j + k] += MOD;
			}
}

inline void Mult(LL a[], LL b[], LL c[], int N)
{
	int S = 1;
	int K = 0;
	while (S < N)	S *= 2, K ++;
	S *= 2, K ++;
	for (int i = 0; i < S; ++ i)
	{
		int j = 0;
		for (int k = 0; k < K; ++ k)	if (i & (1 << k))	j |= (1 << K - k - 1);
		pos[i] = j;
	}
	LL	g = power(gg, (1 << 23) / S), reg = power(g, MOD - 2);
	W[0][0] = W[1][0] = 1;
	for (int i = 1; i < S; ++ i)
	{
		W[0][i] = W[0][i - 1] * g % MOD;
		W[1][i] = W[1][i - 1] * reg % MOD;
	}
	for (int i = N; i <= S; ++ i)	a[i] = b[i] = 0;
	DFT(0, a, S);
	DFT(0, b, S);
	for (int i = 0; i < S; ++ i)	c[i] = a[i] * b[i] % MOD;
	DFT(1, c, S);
	LL	rvs = power(S, MOD - 2);
	for (int i = 0; i < S; ++ i)	c[i] = c[i] * rvs % MOD;
	/*for (int i = 0; i < 2 * N; ++ i)	c[i] = 0;
	for (int i = 0; i < N; ++ i)
	for (int j = 0; j < N; ++ j)
		c[i + j] = (c[i + j] + a[i] * b[j]) % MOD;*/
}

inline bool	isroot(int g, int P)
{
	P --;
	if (power(g, P / 7) == 1)	return 0;
	if (power(g, P / 17) == 1)	return 0;
	if (power(g, P / 2) == 1)	return 0;
	return 1;
}

void	work(int l, int r)
{
	if (l == r)
	{
		if (l)	g[l] = (g[l] + f[0] * f[l] * 2) % MOD;
		else	f[l] = g[l] = 1;
		return;
	}
	int m = l + r >> 1;
	work(l, m);
	
	for (int i = 0; i <= r - l; ++ i)	a[i] = b[i] = 0;
	for (int i = l; i <= m; ++ i)	a[i - l] = g[i];
	for (int i = 0; i <= r - l; ++ i)	b[i] = c[i];
	Mult(a, b, d, r - l + 1);
	for (int i = m + 1; i <= r; ++ i)	f[i] = (f[i] + d[i - l]) % MOD;
	//if (m + 1 <= 24 && r <= 24)	printf("%d %d\n", m, f[24]);
	
	for (int i = 0; i <= r - l; ++ i)	a[i] = b[i] = 0;
	for (int i = l; i <= m; ++ i)	a[i - l] = f[i];
	for (int i = 0; i <= r - l && i <= m; ++ i)	b[i] = f[i];
	Mult(a, b, d, r - l + 1);
	for (int i = m + 1; i <= r; ++ i)	g[i] = (g[i] + 2 * d[i - l]) % MOD;
	
	for (int i = 0; i <= r - l; ++ i)	a[i] = b[i] = 0;
	for (int i = l; i <= m; ++ i)	a[i - l] = f[i];
	for (int i = l; i <= r - l && i <= m; ++ i)	b[i] = f[i];
	Mult(a, b, d, r - l + 1);
	for (int i = m + 1; i <= r; ++ i)	g[i] = (g[i] - d[i - l] + MOD) % MOD;
	
	work(m + 1, r);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	for (int i = 2; ; ++ i)
		if (isroot(i, MOD))
		{
			gg = i;
			break;
		}
	gg = power(gg, 7 * 17);
	N = read(), M = read();
	for (int i = 1; i <= N; ++ i)	c[read()] = 1;
	work(0, M);
	/*f[0] = g[0] = 1;
	for (int i = 1; i <= M; ++ i)
	{
		f[i] = 0;
		for (int j = 1; j <= i; ++ j)	if (c[j])
			f[i] = (f[i] + g[i - j]) % MOD;
		g[i] = 0;
		for (int j = 0; j <= i; ++ j)
			g[i] = (g[i] + f[j] * f[i - j]) % MOD;
	}*/
	for (int i = 1; i <= M; ++ i)	printf("%d\n", int(f[i]));
	//for (int i = 1; i <= M; ++ i)	printf("%d\n", int(g[i]));

	return 0;
}