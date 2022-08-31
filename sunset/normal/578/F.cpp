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
const int MAXM = 10005;

int n, m, c, mod, cnt, f[MAXM], rel[MAXM], a[MAXN][MAXN], idx[MAXN][MAXN];
char s[MAXN][MAXN];

inline int Qow(int x, int y)
{
	int r = 1;
	for (; y; y >>= 1, x = 1LL * x * x % mod)
		if (y & 1)
			r = 1LL * r * x % mod;
	return r;
}

inline int Find(int x)
{
	while (x ^ f[x])
		x = f[x] = f[f[x]];
	return x;
}

inline bool Merge(int x, int y)
{
	x = Find(x), y = Find(y);
	if (x == y)
		return false;
	return f[x] = y, true;
}

inline void Addedge(int x, int y)
{
	x = rel[Find(x)], y = rel[Find(y)];
	a[x][x] = (a[x][x] + 1) % mod, a[y][y] = (a[y][y] + 1) % mod;
	a[x][y] = (a[x][y] + mod - 1) % mod, a[y][x] = (a[y][x] + mod - 1) % mod;
}

inline int Det(int n)
{
	int ret = 1;
	for (int i = 1; i <= n; i ++)
	{
		if (!a[i][i])
		{
			for (int j = i + 1; j <= n; j ++)
				if (a[j][i])
				{
					for (int k = i; k <= n; k ++)
						swap(a[j][k], a[i][k]);
					ret = (mod - ret) % mod;
					break;
				}
		}
		if (!a[i][i])
			return 0;
		int inv = (mod - Qow(a[i][i], mod - 2)) % mod;
		for (int j = i + 1; j <= n; j ++)
			if (a[j][i])
			{
				int r = 1LL * a[j][i] * inv % mod;
				for (int k = i; k <= n; k ++)
					a[j][k] = (1LL * r * a[i][k] + a[j][k]) % mod;
			}
		ret = 1LL * ret * a[i][i] % mod;
	}
	return ret;
}

inline int Solve(bool typ)
{
	cnt = c = 0;
	for (int i = 0; i <= n; i ++)
		for (int j = 0; j <= m; j ++)
			if ((i + j & 1) == typ)
				idx[i][j] = ++ cnt, f[cnt] = cnt;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (!typ)
			{
				if ((!(i + j & 1) && s[i][j] == '\\' && !Merge(idx[i - 1][j - 1], idx[i][j])) || ((i + j & 1) && s[i][j] == '/' && !Merge(idx[i][j - 1], idx[i - 1][j])))
					return 0;
			}
			else
			{
				if (((i + j & 1) && s[i][j] == '\\' && !Merge(idx[i - 1][j - 1], idx[i][j])) || (!(i + j & 1) && s[i][j] == '/' && !Merge(idx[i][j - 1], idx[i - 1][j])))
					return 0;
			}
	for (int i = 1; i <= cnt; i ++)
		if (Find(i) == i)
			rel[i] = ++ c;
	mset(a, 0);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (s[i][j] == '*')
			{
				if (!typ)
				{
					if (i + j & 1)
						Addedge(idx[i][j - 1], idx[i - 1][j]);
					else
						Addedge(idx[i - 1][j - 1], idx[i][j]);
				}
				else
				{
					if (i + j & 1)
						Addedge(idx[i - 1][j - 1], idx[i][j]);
					else
						Addedge(idx[i][j - 1], idx[i - 1][j]);
				}
			}
	return Det(c - 1);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read(), mod = Read();
	for (int i = 1; i <= n; i ++)
		scanf("%s", s[i] + 1);
	return printf("%d\n", (Solve(0) + Solve(1)) % mod), 0;
}