#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 55;

int n, m;
char s[N][N];
int vis[N][N], vis2[N][N];

int dfs(int x, int y)
{
	if (vis[x][y])
		return 0;
	if (x < 1 || y < 1 || x > n || y > m)
		return 0;
	if (s[x][y] != '*')
		return 0;
	vis[x][y] = 1;
	int cnt = 1;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (i != 0 || j != 0)
			{
				int v = dfs(x + i, y + j);
				if (v == -1)
					return -1;
				cnt += v;
			}
	if (cnt > 3)
		return -1;
	return cnt;
}

int dfs2(int x, int y)
{
	if (vis2[x][y])
		return 0;
	if (x < 1 || y < 1 || x > n || y > m)
		return 0;
	if (s[x][y] != '*')
		return 0;
	vis2[x][y] = 1;
	int cnt = 1;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (abs(i) + abs(j) == 1)
			{
				int v = dfs2(x + i, y + j);
				if (v == -1)
					return -1;
				cnt += v;
			}
	if (cnt > 3)
		return -1;
	return cnt;
}

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			vis[i][j] = vis2[i][j] = 0;
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	int chk = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (s[i][j] == '*' && !vis[i][j])
			{
				int v = dfs(i, j);
				if (v == -1)
					chk = 0;
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (s[i][j] == '*' && !vis2[i][j])
			{
				int v = dfs2(i, j);
				if (v != 3)
					chk = 0;
			}
	for (int i = 1; i <= n; i++)
		for (int j = 2; j < m; j++)
			if (s[i][j] == '*' && s[i][j - 1] == '*' && s[i][j + 1] == '*')
				chk = 0;
	for (int i = 2; i < n; i++)
		for (int j = 1; j <= m; j++)
			if (s[i][j] == '*' && s[i - 1][j] == '*' && s[i + 1][j] == '*')
				chk = 0;
	if (chk)
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}