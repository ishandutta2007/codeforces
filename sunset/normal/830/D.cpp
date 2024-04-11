#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair < int, int > pii;

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
const int mod = 1e9 + 7;

int n, f[MAXN][MAXN];

inline void Inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(); f[1][0] = f[1][1] = 1;
	for (int i = 2; i <= n; i ++)
		for (int j = 0; j <= n; j ++)
			if (f[i - 1][j])
				for (int k = 0; k <= n; k ++)
					if (f[i - 1][k])
					{
						int cur = 1LL * f[i - 1][j] * f[i - 1][k] % mod;
						if (j + k <= n)
							Inc(f[i][j + k], 1LL * ((j << 1) + (k << 1) + 1) * cur % mod);
						if (j + k + 1 <= n)
							Inc(f[i][j + k + 1], cur);
						if (j + k > 1 && j + k - 1 <= n)
							Inc(f[i][j + k - 1], 1LL * (j + k) * (j + k - 1) * cur % mod);
					}
	return printf("%d\n", f[n][1]), 0;
}