#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

const int N = 105;

int n;
char s[N][N];
bool vis[N][N];
int ans;

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			vis[i][j] = 0;
	ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (vis[i][j])
				continue;
			int x = i, y = j;
			int cnt = 0, c1 = 0;
			do
			{
				vis[x][y] = 1;
				cnt++;
				if (s[x][y] == '1')
					c1++;
				int xx = y, yy = n - x + 1;
				x = xx, y = yy;
			}
			while (!vis[x][y]);
			ans += min(c1, cnt - c1);
		}
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}