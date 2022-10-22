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

const int N = 3e5 + 5, djq = 998244353;

int n, a[N], m, f[N], fi[N], mi[N], ls[N], iN, iM, ans;

int qpow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = 1ll * res * a % djq;
		a = 1ll * a * a % djq;
		b >>= 1;
	}
	return res;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), m += a[i];
	iN = qpow(n - 1, djq - 2); iM = qpow(m, djq - 2);
	mi[m] = 1; f[m] = 0;
	for (int i = 0; i < m; i++)
	{
		fi[i] = (djq - 1ll * i * iM % djq) % djq;
		mi[i] = (1 - 1ll * (n - 2) * (m - i) % djq * iN % djq * iM % djq + djq) % djq;
		ls[i] = (djq - 1ll * (m - i) * iN % djq * iM % djq) % djq;
		f[i] = 1;
	}
	for (int i = 0; i <= m; i++)
	{
		int gg = qpow(mi[i], djq - 2);
		mi[i] = 1ll * mi[i] * gg % djq; ls[i] = 1ll * ls[i] * gg % djq;
		f[i] = 1ll * f[i] * gg % djq;
		f[i + 1] = (f[i + 1] - 1ll * fi[i + 1] * f[i] % djq + djq) % djq;
		mi[i + 1] = (mi[i + 1] - 1ll * fi[i + 1] * ls[i] % djq + djq) % djq;
	}
	for (int i = m - 1; i >= 0; i--)
		f[i] = (f[i] - 1ll * f[i + 1] * ls[i] % djq + djq) % djq;
	for (int i = 1; i <= n; i++) ans = (ans + f[a[i]]) % djq;
	return std::cout << 1ll * (ans - 1ll * (n - 1) * f[0] % djq + djq)
		* qpow(n, djq - 2) % djq << std::endl, 0;
}