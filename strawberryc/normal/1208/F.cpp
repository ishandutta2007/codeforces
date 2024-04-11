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

const int N = 1e6 + 5, M = 3e6 + 5;

int n, a[N], ans;

struct elem
{
	int mx, cmx;
	
	friend inline elem operator + (elem a, elem b)
	{
		return (elem) {std::max(a.mx, b.mx),
			std::min(std::max(a.mx, b.cmx), std::max(a.cmx, b.mx))};
	}
} f[M];

int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		if (i > f[a[i]].mx) f[a[i]].cmx = f[a[i]].mx, f[a[i]].mx = i;
		else if (i > f[a[i]].cmx) f[a[i]].cmx = i;
	}
	for (int k = 0; k <= 20; k++)
		for (int i = 0; i < 2097152; i++)
			if (!((i >> k) & 1)) f[i] = f[i] + f[i | (1 << k)];
	for (int i = n; i >= 1; i--)
	{
		int res = 0, S = 0;
		for (int j = 20; j >= 0; j--)
			if ((a[i] >> j) & 1) res |= 1 << j;
			else if (f[S | (1 << j)].cmx > i) S |= 1 << j, res |= 1 << j;
		if (i <= n - 2 && res > ans) ans = res;
	}
	return std::cout << ans << std::endl, 0;
}