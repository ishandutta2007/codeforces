#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
#define Rof(i, a, b) for (i = a; i >= b; i--)

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 705;

int n, a[N], g[N][N];
bool f[N][N][2], ans;

int main()
{
	int i, j, k;
	n = read();
	For (i, 1, n) a[i] = read();
	For (i, 1, n) For (j, 1, n)
		g[i][j] = std::__gcd(a[i], a[j]);
	For (i, 1, n + 1) f[i][i - 1][0] = f[i][i - 1][1] = 1;
	Rof (i, n, 1) For (j, i, n) For (k, i, j)
	{
		if (i > 1 && g[i - 1][k] > 1)
			f[i][j][0] |= f[i][k - 1][1] && f[k + 1][j][0];
		if (j < n && g[k][j + 1] > 1)
			f[i][j][1] |= f[i][k - 1][1] && f[k + 1][j][0];
	}
	For (i, 1, n) ans |= f[1][i - 1][1] && f[i + 1][n][0];
	puts(ans ? "Yes" : "No");
	return 0;
}