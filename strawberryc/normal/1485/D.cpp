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

const int N = 505;

int n, m, a[N][N];

int main()
{
	read(n); read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(a[i][j]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d ", i + j & 1 ? 720720 : 720720 - a[i][j]
				* a[i][j] * a[i][j] * a[i][j]);
		puts("");
	}
	return 0;
}