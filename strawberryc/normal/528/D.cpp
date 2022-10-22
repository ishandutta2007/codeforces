#include <bits/stdc++.h>

// 0830

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

template <class T>
inline void Swap(T &a, T &b) {T t = a; a = b; b = t;}

const int N = 6e5 + 5, ZZQ = 998244353;
const char lis[] = {'A', 'C', 'G', 'T'};

int n, m, k, ff = 1, tot, rev[N], a[N], b[N], sum[N], yg[N], res[N], ans;
char s[N], t[N];

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

void FFT(int n, int *a, int op)
{
	for (int i = 0; i < n; i++) if (i < rev[i]) Swap(a[i], a[rev[i]]);
	yg[n] = qpow(3, (ZZQ - 1) / n * ((n + op) % n));
	for (int i = n >> 1; i; i >>= 1)
		yg[i] = 1ll * yg[i << 1] * yg[i << 1] % ZZQ;
	for (int k = 1; k < n; k <<= 1)
	{
		int x = yg[k << 1];
		for (int i = 0; i < n; i += k << 1)
		{
			int w = 1;
			for (int j = 0; j < k; j++)
			{
				int u = a[i + j], v = 1ll * w * a[i + j + k] % ZZQ;
				a[i + j] = (u + v) % ZZQ;
				a[i + j + k] = (u - v + ZZQ) % ZZQ;
				w = 1ll * w * x % ZZQ;
			}
		}
	}
}

int main()
{
	std::cin >> n >> m >> k;
	scanf("%s%s", s + 1, t + 1);
	while (ff < n + m - 1) ff <<= 1, tot++;
	for (int i = 0; i < ff; i++)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << tot - 1);
	int gg = qpow(ff, ZZQ - 2);
	for (int T = 0; T < 4; T++)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + (s[i] == lis[T]);
		for (int i = 1; i <= n; i++)
			a[i - 1] = sum[Min(n, i + k)] > sum[Max(1, i - k) - 1];
		for (int i = 1; i <= m; i++)
			b[m - i] = t[i] == lis[T];
		FFT(ff, a, 1); FFT(ff, b, 1);
		for (int i = 0; i < ff; i++) a[i] = 1ll * a[i] * b[i] % ZZQ;
		FFT(ff, a, -1);
		for (int i = m; i <= n; i++)
			res[i] += 1ll * a[i - 1] * gg % ZZQ;
	}
	for (int i = m; i <= n; i++) if (res[i] == m) ans++;
	std::cout << ans << std::endl;
	return 0;
}