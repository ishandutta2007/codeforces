#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
#define Step(i, a, b, x) for (i = a; i <= b; i += x)
#define Pow(k, n) for (k = 1; k < n; k <<= 1)

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
inline void Swap(T &a, T &b) {a ^= b; b ^= a; a ^= b;}

const int N = 14e5 + 5, ZZQ = 998244353;

int n, m, cnt[N], rev[N], ff = 4, tot = 2, gg = 748683265, omega[N],
sqrtc[N], invc[N], tmp[N], invsq[N], pmt[N];

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
	int i, j, k = n >> 1;
	For (i, 0, n - 1) if (i < rev[i]) Swap(a[i], a[rev[i]]);
	omega[n] = qpow(3, (ZZQ - 1) / n * (op == 1 ? 1 : n - 1));
	while (k)
		omega[k] = 1ll * omega[k << 1] * omega[k << 1] % ZZQ, k >>= 1;
	Pow(k, n)
	{
		int x = omega[k << 1];
		Step (i, 0, n - 1, k << 1)
		{
			int w = 1;
			For (j, 0, k - 1)
			{
				int u = a[i + j], v = 1ll * w * a[i + j + k] % ZZQ;
				a[i + j] = (u + v) % ZZQ;
				a[i + j + k] = (u - v + ZZQ) % ZZQ;
				w = 1ll * w * x % ZZQ;
			}
		}
	}
}

void getinv(int n, int *a, int *res)
{
	int i, k, ff = 4, gg = 748683265, tot = 2;
	res[0] = qpow(a[0], ZZQ - 2);
	Pow(k, n)
	{
		For (i, 0, ff - 1)
			rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << tot - 1);
		For (i, 0, (ff >> 1) - 1) pmt[i] = a[i];
		For (i, ff >> 1, ff - 1) pmt[i] = 0;
		For (i, ff >> 2, ff - 1) res[i] = 0;
		FFT(ff, pmt, 1); FFT(ff, res, 1);
		For (i, 0, ff - 1)
			res[i] = 1ll * res[i] * (2 - 1ll * pmt[i] * res[i] % ZZQ
			+ ZZQ) % ZZQ;
		FFT(ff, res, -1);
		For (i, 0, (ff >> 1) - 1) res[i] = 1ll * res[i] * gg % ZZQ;
		ff <<= 1; tot++;
		gg = 499122177ll * gg % ZZQ;
	}
	For (i, n, ff >> 1) res[i] = 0;
}

int main()
{
	int i, x, k;
	n = read(); m = read();
	For (i, 1, n) if ((x = read()) <= m) cnt[x] = ZZQ - 4;
	cnt[0] = sqrtc[0] = 1;
	Pow(k, m + 1)
	{
		For (i, 0, k - 1) tmp[i] = sqrtc[i];
		For (i, k, (k << 1) - 1) tmp[i] = 0;
		getinv(k << 1, tmp, invc);
		For (i, 0, ff - 1)
			rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << tot - 1);
		For (i, 0, (ff >> 1) - 1) tmp[i] = cnt[i];
		For (i, ff >> 1, ff - 1) tmp[i] = 0;
		FFT(ff, tmp, 1); FFT(ff, sqrtc, 1); FFT(ff, invc, 1);
		For (i, 0, ff - 1)
			sqrtc[i] = (sqrtc[i] - 499122177ll *
				(1ll * sqrtc[i] * sqrtc[i] % ZZQ - tmp[i] + ZZQ)
				% ZZQ * invc[i] % ZZQ + ZZQ) % ZZQ;
		FFT(ff, sqrtc, -1);
		For (i, 0, (ff >> 1) - 1) sqrtc[i] = 1ll * sqrtc[i] * gg % ZZQ;
		For (i, ff >> 1, ff - 1) sqrtc[i] = 0;
		ff <<= 1; tot++;
		gg = 499122177ll * gg % ZZQ;
	}
	For (i, m + 1, ff >> 1) sqrtc[i] = 0;
	sqrtc[0]++; invsq[0] = 499122177;
	getinv(m + 1, sqrtc, invsq);
	For (i, 1, m) printf("%d\n", 2 * invsq[i] % ZZQ);
	return 0;
}