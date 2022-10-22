#include <bits/stdc++.h>
#define p2 p << 1
#define p3 p << 1 | 1

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

const int N = 1e6 + 5;

int n, k, f[N][2][2], ans = -1;
bool is[N], win[2], los[2];

void dp(int l, int r, int p)
{
	if (l + 1 == r) return (void) (f[p][is[l]][is[r]] = f[p][is[r]][is[l]]
		= is[l] || is[r]);
	int mid = l + r >> 1;
	dp(l, mid, p2); dp(mid + 1, r, p3);
	for (int a = 0; a < 2; a++) for (int b = 0; b < 2; b++)
	for (int c = 0; c < 2; c++) for (int d = 0; d < 2; d++)
	{
		if (f[p2][a][b] == -1 || f[p3][c][d] == -1) continue;
		win[0] = a; win[1] = c; los[0] = b; los[1] = d;
		int tf = f[p2][a][b] + f[p3][c][d] + (a || c) + (b || d);
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
		{
			f[p][win[i]][los[j]] = std::max(f[p][win[i]][los[j]],
				tf + (win[i ^ 1] || los[j]));
			f[p][win[i]][win[i ^ 1]] = std::max(f[p][win[i]][win[i ^ 1]],
				tf + (win[i ^ 1] || los[j]));
		}
	}
}

int main()
{
	memset(f, -1, sizeof(f));
	int x;
	read(n); n = 1 << n; read(k);
	while (k--) read(x), is[x] = 1;
	dp(1, n, 1);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (f[1][i][j] != -1)
				ans = std::max(ans, f[1][i][j] + (i || j));
	return std::cout << ans << std::endl, 0;
}