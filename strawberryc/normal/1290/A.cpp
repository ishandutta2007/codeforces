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

const int N = 3505;

int n, m, k, a[N], b[N], mn[N][N];

void work()
{
	read(n); read(m); read(k);
	for (int i = 1; i <= n; i++) read(a[i]);
	int ans = 0;
	if (k >= m) k = m - 1; m = n - m + 1;
	for (int i = 1; i <= n - m + 1; i++) b[i] = Max(a[i], a[i + m - 1]);
	for (int i = 1; i <= n - m + 1; i++)
	{
		mn[i][i + m - 1] = b[i];
		for (int j = i + m; j <= n; j++)
			mn[i][j] = Min(mn[i][j - 1], b[j - m + 1]);
	}
	for (int l = 0; l <= k; l++)
		for (int r = 0; l + r <= k; r++)
			ans = Max(ans, mn[l + 1][n - r]);
	printf("%d\n", ans);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}