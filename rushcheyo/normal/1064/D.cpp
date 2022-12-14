#include <bits/stdc++.h>
using namespace std;

const int D[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, r, c, x, y, minl[2005][2005];
bool vis[2005][2005];
deque<pair<int, int> > q;
char s[2005][2005];

int main()
{
	cin >> n >> m >> r >> c >> x >> y;
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	memset(minl, 0x3f, sizeof minl);
	minl[r][c] = 0;
	q.emplace_back(r, c);
	while (!q.empty())
	{
		pair<int, int> u = q.front(); q.pop_front();
		vis[u.first][u.second] = true;
		for (int i = 0; i < 4; i++)
		{
			int x = u.first + D[i][0], y = u.second + D[i][1];
			if (x < 1 || x > n || y < 1 || y > m || vis[x][y] || s[x][y] == '*') continue;
			if (i == 3)
			{
				if (minl[u.first][u.second] + 1 < minl[x][y])
					minl[x][y] = minl[u.first][u.second] + 1, q.emplace_back(x, y);
			}
			else
			{
				if (minl[u.first][u.second] < minl[x][y])
					minl[x][y] = minl[u.first][u.second], q.emplace_front(x, y);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (minl[i][j] <= x && j - c + minl[i][j] <= y) ans++;
	printf("%d\n", ans);
	return 0;
}