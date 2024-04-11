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

const int MAXN = 405;
const int MAXM = 605;
const int mod = 10007;

int n, m, a[MAXM][MAXM], f[MAXM][MAXN][MAXN];
char s[MAXN];

inline int Qow(int x, int y)
{
	int r = 1;
	for (; y; y >>= 1, x = x * x % mod)
		if (y & 1)
			r = r * x % mod;
	return r;
}

inline void Gauss(int n)
{
	for (int i = 1; i <= n; i ++)
	{
		for (int j = i; j <= n; j ++)
			if (a[j][i])
			{
				for (int k = i; k <= n + 1; k ++)
					swap(a[i][k], a[j][k]);
				break;
			}
		int v = Qow(a[i][i], mod - 2);
		for (int j = 1; j <= n; j ++)
			if ((i ^ j) && a[j][i])
			{
				int t = a[j][i] * v % mod;
				for (int k = i; k <= n + 1; k ++)
					a[j][k] = (a[j][k] - a[i][k] * t % mod + mod) % mod;
			}
	}
	for (int i = 1; i <= n; i ++)
		a[i][n + 1] = 1LL * a[i][n + 1] * Qow(a[i][i], mod - 2) % mod;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	scanf("%s", s + 1), m = Read() + (n = strlen(s + 1));
	f[0][1][n] = 1;
	int x = n - 1, y = n + 1 >> 1;
	for (int i = 0; i <= x + y; i ++)
	{
		for (int j = 1; j <= n; j ++)
			for (int k = j; k <= n; k ++)
				if (f[i][j][k])
					if (s[j] == s[k])
						f[i + 1][j][k] = (f[i][j][k] * 25 + f[i + 1][j][k]) % mod, f[i + 1][j + 1][max(j, k - 1)] = (f[i + 1][j + 1][max(j, k - 1)] + f[i][j][k]) % mod;
					else
						f[i + 1][j][k] = (f[i][j][k] * 24 + f[i + 1][j][k]) % mod, f[i + 1][j + 1][k] = (f[i + 1][j + 1][k] + f[i][j][k]) % mod, f[i + 1][j][k - 1] = (f[i + 1][j][k - 1] + f[i][j][k]) % mod;
		for (int j = 1; j <= n; j ++)
			f[i + 1][j + 1][j] = (f[i][j + 1][j] * 26 + f[i + 1][j + 1][j]) % mod;
	}
	for (int i = 1, bas; i <= x + y + 1; i ++)
	{
		for (int j = 1; j <= n; j ++)
			if (m & 1)
				a[i][x + y + 2] = (f[i - 1][j + 1][j] * 26 + f[i - 1][j][j] + a[i][x + y + 2]) % mod;
			else
				a[i][x + y + 2] = (a[i][x + y + 2] + f[i][j + 1][j]) % mod;
		bas = Qow(24, i);
		for (int j = 1; j <= x; j ++)
			a[i][j] = bas, bas = bas * i % mod;
		bas = Qow(25, i);
		for (int j = 1; j <= y; j ++)
			a[i][j + x] = bas, bas = bas * i % mod;
		bas = Qow(26, i);
		a[i][x + y + 1] = bas;
	}
	Gauss(x + y + 1), m = m + 1 >> 1;
	int ret = 0, bas;
	bas = Qow(24, m);
	for (int i = 1; i <= x; i ++)
		ret = (bas * a[i][x + y + 2] + ret) % mod, bas = bas * (m % mod) % mod;
	bas = Qow(25, m);
	for (int i = 1; i <= y; i ++)
		ret = (bas * a[i + x][x + y + 2] + ret) % mod, bas = bas * (m % mod) % mod;
	bas = Qow(26, m);
	ret = (bas * a[x + y + 1][x + y + 2] + ret) % mod;
	return printf("%d\n", ret), 0;
}