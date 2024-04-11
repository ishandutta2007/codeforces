#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1211;
const int Inf = 0x3f3f3f3f;

string s[N];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int dis[N][N];
int bfs(char from, char to, int n, int m)
{
	queue <pair <int, int> > que;
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			if(s[i][j] == from)
			{
				dis[i][j] = 0;
				que.push(make_pair(i, j));
			}

	while(!que.empty())
	{
		pair <int, int> p = que.front();
		que.pop();
		if(s[p.first][p.second] == to)
			return dis[p.first][p.second];
		int x = p.first;
		int y = p.second;
		for(int k = 0; k < 4; k ++)
		{
			int nx = p.first + dx[k];
			int ny = p.second + dy[k];
			if(nx < 0 || nx >= n)
				continue;
			if(ny < 0 || ny >= m)
				continue;
			
			if((s[nx][ny] == '.' || s[nx][ny] == to) && dis[nx][ny] == Inf)
			{
				dis[nx][ny] = dis[p.first][p.second] + 1;
				que.push(make_pair(nx, ny));
			}
		}
	}

	return Inf;
}

int sdis[3][N][N];
void bfs2(char from, int ff, int n, int m)
{
	queue <pair <int, int> > que;
	memset(sdis[ff], 0x3f, sizeof(sdis[ff]));
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			if(s[i][j] == from)
			{
				sdis[ff][i][j] = 0;
				que.push(make_pair(i, j));
			}

	while(!que.empty())
	{
		pair <int, int> p = que.front();
		que.pop();

		int x = p.first;
		int y = p.second;
		for(int k = 0; k < 4; k ++)
		{
			int nx = p.first + dx[k];
			int ny = p.second + dy[k];
			if(nx < 0 || nx >= n)
				continue;
			if(ny < 0 || ny >= m)
				continue;
			
			if((s[nx][ny] == '.') && sdis[ff][nx][ny] == Inf)
			{
				sdis[ff][nx][ny] = sdis[ff][p.first][p.second] + 1;
				que.push(make_pair(nx, ny));
			}
		}
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++)
		cin >> s[i];
	int dis12 = bfs('1', '2', n, m);
	int dis13 = bfs('1', '3', n, m);
	int dis23 = bfs('2', '3', n, m);

	bfs2('1', 0, n, m);
	bfs2('2', 1, n, m);
	bfs2('3', 2, n, m);
	
	int ans = min(min(dis12 + dis13 - 2, dis13 + dis23 - 2), dis12 + dis23 - 2);
	
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			if(s[i][j] == '.')
			{
				ans = min((long long)ans, (long long)sdis[0][i][j] + sdis[1][i][j] + sdis[2][i][j] - 3 + 1);
			}

	if(ans < Inf - 10)
		cout << ans << '\n';
	else
		cout << -1 << '\n';
	return 0;
}