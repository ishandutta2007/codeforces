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

const int N = 1005, M = 1e5 + 5;

int n, m, d[3], a[N][N], ans[N][N];
char c[3], s[M];

int o(int i, int j, char c)
{
	if (c == 'X') return i; if (c == 'Y') return j;
	return a[i][j];
}

int th(int i, int j, int k)
{
	int res = o(i, j, c[k]);
	res = (res + d[k] % n + n) % n;
	if (!res) res = n; return res;
}

void work()
{
	read(n); read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			read(a[i][j]);
	scanf("%s", s + 1);
	c[0] = 'X'; c[1] = 'Y'; c[2] = 'Z';
	d[0] = d[1] = d[2] = 0;
	for (int i = 1; i <= m; i++)
		if (s[i] == 'R') d[1]++;
		else if (s[i] == 'L') d[1]--;
		else if (s[i] == 'D') d[0]++;
		else if (s[i] == 'U') d[0]--;
		else if (s[i] == 'I') std::swap(c[1], c[2]), std::swap(d[1], d[2]);
		else std::swap(c[0], c[2]), std::swap(d[0], d[2]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans[th(i, j, 0)][th(i, j, 1)] = th(i, j, 2);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) printf("%d ", ans[i][j]);
		puts("");
	}
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}