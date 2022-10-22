#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 2e5 + 5, rqy = 1e9 + 7;

int n, l[N], r[N], pb[N], sp[N], ilr[N], ans1, ans2;

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

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(l[i]);
	for (int i = 1; i <= n; i++) read(r[i]);
	for (int i = 1; i <= n; i++) ilr[i] = qpow(r[i] - l[i] + 1, rqy - 2);
	for (int i = 1; i < n; i++)
	{
		pb[i] = (1 - 1ll * Max(0, Min(r[i], r[i + 1]) - Max(l[i], l[i + 1]) + 1)
			* ilr[i] % rqy * ilr[i + 1] % rqy + rqy) % rqy;
		sp[i] = (sp[i - 1] + pb[i]) % rqy;
		if (i > 1) ans2 = (1ll * pb[i] * sp[i - 2] + ans2) % rqy;
		ans1 = (ans1 + pb[i]) % rqy;
	}
	for (int i = 1; i < n - 1; i++)
	{
		int pb = 1;
		pb = (pb - 1ll * Max(0, Min(r[i], r[i + 1]) - Max(l[i], l[i + 1]) + 1)
			* ilr[i] % rqy * ilr[i + 1] % rqy + rqy) % rqy;
		pb = (pb - 1ll * Max(0, Min(r[i + 1], r[i + 2]) - Max(l[i + 1], l[i + 2])
			+ 1) * ilr[i + 1] % rqy * ilr[i + 2] % rqy + rqy) % rqy;
		pb = (1ll * Max(0, Min(Min(r[i], r[i + 1]), r[i + 2])
			- Max(Max(l[i], l[i + 1]), l[i + 2]) + 1) * ilr[i] % rqy
			* ilr[i + 1] % rqy * ilr[i + 2] + pb) % rqy;
		ans2 = (ans2 + pb) % rqy;
	}
	return std::cout << (2ll * ans2 + 3ll * ans1 + 1) % rqy << std::endl, 0;
}