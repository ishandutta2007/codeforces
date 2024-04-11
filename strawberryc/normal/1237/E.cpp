#include <bits/stdc++.h>

template <class T>
inline void Swap(T &a, T &b) {T t = a; a = b; b = t;}

const int N = 3e6 + 5, rqy = 998244353;

int n, m, ups, rst, rev[N], yg[N], f[N], g[N], t1[N], t2[N], t3[N];

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

void FFT(int n, int *a, int op)
{
	for (int i = 0; i < n; i++) if (i < rev[i]) Swap(a[i], a[rev[i]]);
	yg[n] = qpow(3, (rqy - 1) / n * ((n + op) % n));
	for (int i = n >> 1; i; i >>= 1)
		yg[i] = 1ll * yg[i << 1] * yg[i << 1] % rqy;
	for (int k = 1; k < n; k <<= 1)
	{
		int x = yg[k << 1];
		for (int i = 0; i < n; i += k << 1)
		{
			int w = 1;
			for (int j = 0; j < k; j++)
			{
				int u = a[i + j], v = 1ll * w * a[i + j + k] % rqy;
				a[i + j] = (u + v) % rqy;
				a[i + j + k] = (u - v + rqy) % rqy;
				w = 1ll * w * x % rqy;
			}
		}
	}
	if (op == -1)
	{
		int gg = qpow(n, rqy - 2);
		for (int i = 0; i < n; i++) a[i] = 1ll * a[i] * gg % rqy;
	}
}

int main()
{
	std::cin >> n; m = ups = 1;
	while (ups * 2 + 1 <= n) m++, ups = ups * 2 + 1;
	rst = n - ups;
	f[0] = g[1] = 1;
	for (int T = 2; T <= m; T++)
	{
		int len = 1 << T;
		for (int i = 0; i < len; i++)
			rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << T - 1);
		for (int i = 0; i < (1 << T - 1); i++)
			if (i & 1) t2[i] = g[i], t1[i] = 0;
			else t1[i] = f[i], t2[i] = 0;
		for (int i = 0; i < (1 << T - 1); i++) t3[i] = g[i];
		FFT(len, t1, 1); FFT(len, t2, 1); FFT(len, t3, 1);
		for (int i = 0; i < len; i++)
			g[i] = 1ll * t1[i] * t3[i] % rqy, f[i] = 1ll * t2[i] * t3[i] % rqy;
		FFT(len, f, -1); FFT(len, g, -1);
	}
	return std::cout << (f[rst] + g[rst]) % rqy << std::endl, 0;
}