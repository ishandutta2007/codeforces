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

const int MAXN = 1005;

LL a[MAXN][MAXN], p[MAXN][MAXN], q[MAXN][MAXN], ans;
int n, m, k, x, y;

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read(), x = y = k = Read();
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			a[i][j] = Read() + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
	for (int i = 1; i <= n + 1; i ++)
		for (int j = 0; j <= m + 1; j ++)
			p[i][j] = a[i][j] + (j ? p[i - 1][j - 1] : 0), q[i][j] = a[i][j] + q[i - 1][j + 1];
	for (int i = k; i <= n - k + 1; i ++)
		for (int j = k; j <= m - k + 1; j ++)
		{
			LL ret = 0;
			ret += q[i + k - 1][j] - q[i - 1][j + k];
			ret += q[i - 1][j - k] - (i > k ? q[i - k - 1][j] : 0);
			ret -= p[i + k - 1][j - 1] - (j > k ? p[i - 1][j - k - 1] : 0);
			ret -= p[i - 1][j + k - 1] - (i > k ? p[i - k - 1][j - 1] : 0);
			if (ans < ret)
				ans = ret, x = i, y = j;
		}
	return printf("%d %d\n", x, y), 0;
}