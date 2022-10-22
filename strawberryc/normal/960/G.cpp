#include <bits/stdc++.h>

// 0830

template <class T>
inline void Swap(T &a, T &b) {T t = a; a = b; b = t;}

const int N = 3e5 + 5, ZZQ = 998244353;

int n, a, b, ff, tot, rev[N], A[N], B[N], yg[N], ans = 1;

std::vector<int> stir;

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
	if (op == -1)
	{
		int gg = qpow(ff, ZZQ - 2);
		for (int i = 0; i < ff; i++) a[i] = 1ll * a[i] * gg % ZZQ;
	}
}

std::vector<int> polymul(std::vector<int> a, std::vector<int> b)
{
	int n = a.size(), m = b.size();
	ff = 1; tot = 0;
	while (ff < n + m - 1) ff <<= 1, tot++;
	for (int i = 0; i < ff; i++)
	{
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << tot - 1);
		A[i] = i < n ? a[i] : 0, B[i] = i < m ? b[i] : 0;
	}	
	FFT(ff, A, 1); FFT(ff, B, 1);
	for (int i = 0; i < ff; i++) A[i] = 1ll * A[i] * B[i] % ZZQ;
	FFT(ff, A, -1);
	std::vector<int> res;
	for (int i = 0; i < n + m - 1; i++) res.push_back(A[i]);
	return res;
}

std::vector<int> calc(int l, int r)
{
	std::vector<int> res;
	if (l > r) res.push_back(1);
	else if (l == r) res.push_back(l), res.push_back(1);
	if (l >= r) return res;
	int mid = l + r >> 1;
	return polymul(calc(l, mid), calc(mid + 1, r));
}

int main()
{
	std::cin >> n >> a >> b;
	stir = calc(0, n - 2);
	if (!a || !b || a + b > n + 1) return puts("0"), 0;
	int fab = 1, fa = 1, fb = 1;
	for (int i = 1; i <= a + b - 2; i++) fab = 1ll * fab * i % ZZQ;
	for (int i = 1; i < a; i++) fa = 1ll * fa * i % ZZQ;
	for (int i = 1; i < b; i++) fb = 1ll * fb * i % ZZQ;
	std::cout << 1ll * stir[a + b - 2] * fab % ZZQ
		* qpow(fa, ZZQ - 2) % ZZQ * qpow(fb, ZZQ - 2) % ZZQ << std::endl;
	return 0;
}