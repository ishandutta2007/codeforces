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

int n, m, d[MAXN], a[MAXN][MAXN];
double ans, c[MAXN][MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 0; i <= n; i ++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j ++)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	}
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++)
			if (~(a[i][j] = Read()))
				d[i] ++, d[j] ++;
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++)
			if (~a[i][j])
				ans += a[i][j] * (c[d[i] - 1][m - 1] + c[d[j] - 1][m - 1]);
	ans /= c[n][m];
	cout << (LL)(ans + 1e-9) << endl;
	return 0;
}