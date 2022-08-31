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

double ans, p[MAXN][MAXN];
int n, m, a[MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 1; i <= n; i ++)
		a[i] = Read();
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			if (i ^ j)
				p[i][j] = a[i] > a[j];
	for (int i = 1, x, y; i <= m; i ++)
	{
		x = Read(), y = Read(), p[x][y] = p[y][x] = 0.5;
		for (int j = 1; j <= n; j ++)
			if ((j ^ x) && (j ^ y))
				p[x][j] = p[y][j] = (p[x][j] + p[y][j]) / 2, p[j][x] = p[j][y] = (p[j][x] + p[j][y]) / 2;
	}
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++)
			ans += p[i][j];
	return printf("%.9lf\n", ans), 0;
}