#include <iostream>
using namespace std;

const int N = 1011;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
bool vis1[N][N];
bool vis2[N][N];
int ans[N][N];
string str[N];
int n, m;

bool check(int x, int y)
{
	if(x < 0 || x >= n)
		return false;
	if(y < 0 || y >= m)
		return false;
	return true;
}

int dfs1(int x, int y)
{
	vis1[x][y] = true;
	int ret = 0;
	for(int k = 0; k < 4; k ++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(check(nx, ny))
		{
			if(str[nx][ny] == '.' && !vis1[nx][ny])
				ret += dfs1(nx, ny);
			else if(str[nx][ny] == '*')
				ret ++;
		}
	}
	return ret;
}
void dfs2(int x, int y, int a)
{
	vis2[x][y] = true;
	ans[x][y] = a;
	for(int k = 0; k < 4; k ++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(check(nx, ny))
			if(str[nx][ny] == '.' && !vis2[nx][ny])
				dfs2(nx, ny, a);
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	::n = n;
	::m = m;
	for(int i = 0; i < n; i ++)
		cin >> str[i];
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			if(str[i][j] == '.' && !vis1[i][j])
			{
				int tmp = dfs1(i, j);
				dfs2(i, j, tmp);
			}
	while(q --)
	{
		int x, y;
		cin >> x >> y;
		cout << ans[x - 1][y - 1] << '\n';
	}
	return 0;
}