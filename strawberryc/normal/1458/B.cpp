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

const int N = 105;

int n, a[N], b[N], sb, f[2][N][N * N];

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), read(b[i]), sb += b[i];
	memset(f, -1, sizeof(f));
	f[0][0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int T = i & 1;
		for (int j = 0; j <= i; j++)
			for (int k = 0; k <= i * 100; k++) f[T][j][k] = -1;
		for (int j = 0; j < i; j++)
			for (int k = 0; k <= (i - 1) * 100; k++)
			{
				if (f[T ^ 1][j][k] == -1) continue;
				f[T][j][k] = std::max(f[T][j][k], f[T ^ 1][j][k]);
				f[T][j + 1][k + a[i]] = std::max(f[T][j + 1][k + a[i]],
					f[T ^ 1][j][k] + b[i]);
			}
	}
	for (int k = 1; k <= n; k++)
	{
		int res = -1;
		for (int i = 0; i <= 10000; i++) if (f[n & 1][k][i] >= 0)
			res = std::max(res, std::min(i * 2, sb + f[n & 1][k][i]));
		printf("%.10lf ", 0.5 * res);
	}
	return puts(""), 0;
}