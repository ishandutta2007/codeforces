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

const int MAXN = 55;
const int mod = 1e9 + 7;

int n, d[MAXN], s[MAXN], f[MAXN][MAXN], g[MAXN][MAXN][MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 0; i < n; i ++)
		d[i] = Read(), s[i + 1] = s[i] + d[i];
	if (d[0] + 1 > n)
		return puts("0"), 0;
	g[0][0][0] = 1;
	for (int i = 0; i <= n; i ++)
		for (int k = 0; k <= n; k ++)
			for (int j = 0; j <= n; j ++)
				if (j || k)
				{
					if (k)
					{
						if (i >= 2)
							g[i][j][k] = (1LL * g[i - 2][j][k - 1] * i * (i - 1) / 2 + g[i][j][k]) % mod;// 00
						if (i && j)
							g[i][j][k] = (1LL * g[i - 1][j - 1][k - 1] * i * j + g[i][j][k]) % mod; // 01
						if (i && k >= 2)
							g[i][j][k] = (1LL * g[i - 1][j + 1][k - 2] * i * (k - 1) + g[i][j][k]) % mod; // 02
						if (j >= 2)
							g[i][j][k] = (1LL * g[i][j - 2][k - 1] * j * (j - 1) / 2 + g[i][j][k]) % mod; // 11
						if (j && k >= 2)
							g[i][j][k] = (1LL * g[i][j][k - 2] * j * (k - 1) + g[i][j][k]) % mod; // 12
						if (k >= 3)
							g[i][j][k] = (1LL * g[i][j + 2][k - 3] * (k - 1) * (k - 2) / 2 + g[i][j][k]) % mod; // 22
					}
					else
					{
						if (i)
							g[i][j][k] = (1LL * g[i - 1][j - 1][k] * i + g[i][j][k]) % mod; // 0
						if (j >= 2)
							g[i][j][k] = (1LL * g[i][j - 2][k] * (j - 1) + g[i][j][k]) % mod; // 1
					}
				}
	f[n][n - 1] = 1;
	for (int l = n - 1; l; l --)
		for (int r = l; r < n; r ++)
		{
			int q = s[r + 1] - s[l] - (r - l + 1 << 1), p = r - l + 1 - q;
			for (int i = 0; i <= p + 2 * q && i < n - r; i ++)
				f[l][r] = (1LL * f[r + 1][r + i] * g[i][p][q] + f[l][r]) % mod;
		}
	return printf("%d\n", f[1][d[0]]), 0;
}