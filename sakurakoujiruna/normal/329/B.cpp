#include <iostream>
#include <queue>
using namespace std;

const int N = 1011;
char c[N][N];
int dis[N][N];
bool vis[N][N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

#define x first
#define y second

int main()
{
	//ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		scanf("%s", c[i] + 1);

	queue <pair <int, int> > que;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if(c[i][j] == 'E')
			{
				vis[i][j] = true;
				que.push({i, j});
			}

	while(!que.empty())
	{
		pair <int, int> cur = que.front();
		que.pop();
		for(int k = 0; k < 4; k ++)
		{
			int nx = cur.x + dx[k];
			int ny = cur.y + dy[k];
			if(c[nx][ny] != 0 && c[nx][ny] != 'T' && !vis[nx][ny])
			{
				vis[nx][ny] = true;
				dis[nx][ny] = dis[cur.x][cur.y] + 1;
				que.push({nx, ny});
			}
		}
	}

	int ans = 0;
	int dd = -1;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if(c[i][j] == 'S')
				dd = dis[i][j];

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if(c[i][j] >= '1' && c[i][j] <= '9' && vis[i][j] && dis[i][j] <= dd)
				ans += c[i][j] - '0';

	cout << ans << '\n';
	return 0;
}