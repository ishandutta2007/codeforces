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

const int N = 3605, rqy = 998244353;

int h, w, n, f[N][N], C[N][N], f1[N], f2[N], rx, ry, ans, fac[N];
bool vis1[N], vis2[N];

inline int add(int a, int b)
{
	return a + b >= rqy ? a + b - rqy : a + b;
}

int main()
{
	int l, r, x, y;
	read(h); read(w); read(n); rx = h; ry = w;
	while (n--)
	{
		read(l); read(x); read(r); read(y);
		for (int i = l; i <= r; i++) vis1[i] = 1, rx--;
		for (int i = x; i <= y; i++) vis2[i] = 1, ry--;
	}
	f[0][0] = 1;
	for (int i = 1; i <= h; i++)
		for (int j = 0; (j << 1) <= i; j++)
		{
			f[i][j] = f[i - 1][j];
			if (j && i > 1 && !vis1[i] && !vis1[i - 1])
				f[i][j] = add(f[i][j], f[i - 2][j - 1]);
		}
	for (int i = 0; i <= h; i++) f1[i] = f[h][i];
	for (int i = 1; i <= w; i++)
		for (int j = 0; (j << 1) <= i; j++)
		{
			f[i][j] = f[i - 1][j];
			if (j && i > 1 && !vis2[i] && !vis2[i - 1])
				f[i][j] = add(f[i][j], f[i - 2][j - 1]);
		}
	for (int i = 0; i <= w; i++) f2[i] = f[w][i];
	n = std::max(w, h);
	for (int i = 0; i <= n; i++) C[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % rqy;
	for (int i = 0; (i << 1) <= rx; i++)
		for (int j = 0; (j << 1) <= ry; j++)
		{
			if ((i << 1) + j > rx || (j << 1) + i > ry) continue;
			ans = (1ll * f1[i] * f2[j] % rqy * C[rx - (i << 1)][j]
				% rqy * C[ry - (j << 1)][i] % rqy * fac[i] % rqy
				* fac[j] + ans) % rqy;
		}
	return std::cout << ans << std::endl, 0;
}