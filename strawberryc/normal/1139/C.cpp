#include <bits/stdc++.h>

// 20030830

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 1e5 + 5, ZZQ = 1e9 + 7;

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

int n, k, fa[N], sze[N], ans;

int cx(int x)
{
	if (fa[x] != x) fa[x] = cx(fa[x]);
	return fa[x];
}

void zm(int x, int y)
{
	int ix = cx(x), iy = cx(y);
	if (ix != iy) fa[iy] = ix, sze[ix] += sze[iy];
}

int main()
{
	int x, y, z;
	n = read(); k = read();
	for (int i = 1; i <= n; i++) fa[i] = i, sze[i] = 1;
	for (int i = 1; i < n; i++)
	{
		x = read(); y = read(); z = read();
		if (!z) zm(x, y);
	}
	for (int i = 1; i <= n; i++)
		if (fa[i] == i) ans = (qpow(sze[i], k) + ans) % ZZQ;
	std::cout << (qpow(n, k) - ans + ZZQ) % ZZQ << std::endl;
	return 0;
}