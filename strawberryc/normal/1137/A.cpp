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

const int N = 1005;

int n, m, a[N][N], cntx[N], cnty[N], thx[N][N], thy[N][N], w[N];

int main()
{
	n = read(); m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = read();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) w[j] = a[i][j];
		std::sort(w + 1, w + m + 1);
		cntx[i] = std::unique(w + 1, w + m + 1) - w - 1;
		for (int j = 1; j <= m; j++)
			thx[i][j] = std::lower_bound(w + 1, w + cntx[i] + 1, a[i][j]) - w;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++) w[j] = a[j][i];
		std::sort(w + 1, w + n + 1);
		cnty[i] = std::unique(w + 1, w + n + 1) - w - 1;
		for (int j = 1; j <= n; j++)
			thy[j][i] = std::lower_bound(w + 1, w + cnty[i] + 1, a[j][i]) - w;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d ", std::max(thx[i][j], thy[i][j])
				+ std::max(cntx[i] - thx[i][j], cnty[j] - thy[i][j]));
		puts("");
	}
	return 0;
}