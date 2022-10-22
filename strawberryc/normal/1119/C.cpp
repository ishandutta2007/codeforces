#include <bits/stdc++.h>

// 0830

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 505, M = N * N;

int n, m, a[N][N], b[N][N];

int main()
{
	n = read(); m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			b[i][j] = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] ^ b[i][j])
				a[i][j] ^= 1, a[i][m] ^= 1, a[n][j] ^= 1, a[n][m] ^= 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] ^ b[i][j])
				return puts("No"), 0;
	puts("Yes");
	return 0;
}