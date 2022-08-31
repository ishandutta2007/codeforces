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

const int MAXN = 100005;
const int mod = 1e9 + 7;

int n, m, a[MAXN], bin[MAXN], inv[MAXN], s[MAXN], f[18][MAXN], g[18][MAXN];

inline int Get(int l, int r)
{
	return 1LL * (s[r] - s[l - 1] + mod) * inv[l - 1] % mod;
}

inline int Solve(int l, int r)
{
	int ret = 0;
	for (int i = 17; ~i; i --)
		if (f[i][r] >= l)
			ret = (ret + g[i][r]) % mod, r = f[i][r];
	ret = (ret + Get(l, r)) % mod;
	return ret;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read(), bin[0] = inv[0] = 1;
	for (int i = 1; i <= n; i ++)
		a[i] = Read(), bin[i] = (bin[i - 1] << 1) % mod, inv[i] = 1LL * inv[i - 1] * (mod + 1 >> 1) % mod, s[i] = (1LL * bin[i] * (a[i] + mod) + s[i - 1]) % mod;
	for (int i = 1; i <= n; i ++)
	{
		LL cur = 0;
		for (int j = i; j; j --)
		{
			cur = 2 * (cur + a[j]);
			if (cur <= 0)
			{
				f[0][i] = j - 1, g[0][i] = (cur % mod + mod) % mod;
				break;
			}
			else if (cur > 2000000000)
			{
				f[0][i] = -1;
				break;
			}
		}
	}
	for (int i = 1; i < 18; i ++)
		for (int j = 1; j <= n; j ++)
			if (!~f[i - 1][j])
				f[i][j] = -1;
			else
				f[i][j] = f[i - 1][f[i - 1][j]], g[i][j] = (g[i - 1][j] + g[i - 1][f[i - 1][j]]) % mod;
	while (m --)
	{
		int l = Read(), r = Read(), ret = (a[l] + Solve(l + 1, r)) % mod;
		printf("%d\n", (ret + mod) % mod);
	}
	return 0;
}