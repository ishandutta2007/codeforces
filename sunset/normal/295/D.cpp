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

const int MAXN = 2005;
const int mod = 1e9 + 7;

int n, m, ans, f[MAXN][MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int j = 2; j <= m; j ++)
		f[1][j] = 1;
	for (int i = 2; i <= n; i ++)
		for (int j = 2, s = 0; j <= m; j ++)
			s = (s + f[i - 1][j]) % mod, f[i][j] = (f[i][j - 1] + s) % mod;
	for (int i = 2; i <= n; i ++)
		for (int j = 2; j <= m; j ++)
			f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
	for (int i = 1; i <= n; i ++)
		for (int j = 2; j <= m; j ++)
			ans = (1LL * (m - j + 1) * f[i][j] % mod * (f[n - i + 1][j] - f[n - i][j] + mod) + ans) % mod;
	return printf("%d\n", ans), 0;
}