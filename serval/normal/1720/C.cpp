#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 505;

int n, m;
int cnt, mn;
char a[N][N];

void solve()
{
	scanf("%d%d", &n, &m);
	cnt = 0;
	mn = 4;
	for (int i = 1; i <= n; i++)
		scanf("%s", a[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cnt += a[i][j] - '0';
			if (i < n && j < m)
				mn = min(mn, a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1]
					- max({a[i][j], a[i + 1][j], a[i][j + 1], a[i + 1][j + 1]}) - 3 * '0');
		}
	printf("%d\n", cnt - mn + min(mn, 1));
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}