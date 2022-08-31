#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 155;
const int mod = 1e9 + 7;

int n, m, ans, f[MAXN][MAXN][MAXN][2][2];

inline int Sum(int i, int l1, int l2, int r1, int r2, int t1, int t2)
{
	return (0LL + f[i][l2][r2][t1][t2] + f[i][l1 - 1][r1 - 1][t1][t2] + mod + mod - f[i][l1 - 1][r2][t1][t2] - f[i][l2][r1 - 1][t1][t2]) % mod;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 1; i <= n; i ++)
	{
		for (int l = 1; l <= m; l ++)
			for (int r = l; r <= m; r ++)
			{
				f[i][l][r][0][0] = ((i == 1) + Sum(i - 1, l, r, l, r, 0, 0)) % mod;
				f[i][l][r][0][1] = (Sum(i - 1, l, r, r + 1, m, 0, 0) + Sum(i - 1, l, r, r, m, 0, 1)) % mod;
				f[i][l][r][1][0] = (Sum(i - 1, 1, l - 1, l, r, 0, 0) + Sum(i - 1, 1, l, l, r, 1, 0)) % mod;
				f[i][l][r][1][1] = (0LL + Sum(i - 1, 1, l - 1, r + 1, m, 0, 0) + Sum(i - 1, 1, l, r, m, 1, 1) + Sum(i - 1, 1, l - 1, r, m, 0, 1) + Sum(i - 1, 1, l, r + 1, m, 1, 0)) % mod;
			}
		for (int l = 1; l <= m; l ++)
			for (int r = 1; r <= m; r ++)
				for (int t1 = 0; t1 < 2; t1 ++)
					for (int t2 = 0; t2 < 2; t2 ++)
						f[i][l][r][t1][t2] = (0LL + f[i][l][r][t1][t2] + f[i][l - 1][r][t1][t2] + f[i][l][r - 1][t1][t2] + mod - f[i][l - 1][r - 1][t1][t2]) % mod;
		for (int t1 = 0; t1 < 2; t1 ++)
			for (int t2 = 0; t2 < 2; t2 ++)
				ans = (1LL * (n - i + 1) * f[i][m][m][t1][t2] + ans) % mod;
	}
	return printf("%d\n", ans), 0;
}