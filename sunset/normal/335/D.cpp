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

const int MAXN = 3005;

int n, m = 3000, a[MAXN][MAXN], s[MAXN][MAXN], r[MAXN][MAXN], d[MAXN][MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 1; i <= n; i ++)
	{
		int x1 = Read(), y1 = Read(), x2 = Read(), y2 = Read();
		for (int x = x1 + 1; x <= x2; x ++)
			for (int y = y1 + 1; y <= y2; y ++)
				a[x][y] = i;
	}
	for (int i = 1; i <= m; i ++)
		for (int j = 1; j <= m; j ++)
			s[i][j] = (!a[i][j]) + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
	for (int i = m; ~i; i --)
		for (int j = m; ~j; j --)
			r[i][j] = a[i][j + 1] == a[i + 1][j + 1] ? 0 : r[i][j + 1] + 1, d[i][j] = a[i + 1][j] == a[i + 1][j + 1] ? 0 : d[i + 1][j] + 1;
	for (int i = 0; i < m; i ++)
		for (int j = 0; j < m; j ++)
			for (int k = 1; k <= r[i][j] && k <= d[i][j] && !(s[i + k][j + k] + s[i][j] - s[i + k][j] - s[i][j + k]); k ++)
				if (k <= r[i + k][j] && k <= d[i][j + k])
				{
					vector <int> ans;
					for (int x = i + 1; x <= i + k; x ++)
						for (int y = j + 1; y <= j + k; y ++)
							ans.pb(a[x][y]);
					sort(ans.begin(), ans.end()), ans.erase(unique(ans.begin(), ans.end()), ans.end());
					printf("YES %d\n", ans.size());
					for (auto x : ans)
						printf("%d ", x);
					putchar(10);
					return 0;
				}
	return puts("NO"), 0;
}