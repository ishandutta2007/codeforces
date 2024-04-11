#include <iostream>
#include <cstring>
#include <set>
using namespace std;

const int N = 1011;

char str[N][N];
bool vis[N][N];
int size[N][N];
pair <int, int> root[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool check(int x, int y, int &n, int &m)
{
	if(x < 0 || x >= n)
		return false;
	if(y < 0 || y >= m)
		return false;
	return str[x][y] == '.';
}

int dfs(int x, int y, pair <int, int> &rt, int &n, int &m)
{
	int ret = 1;
	vis[x][y] = true;
	root[x][y] = rt;
	for(int k = 0; k < 4; k ++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(check(nx, ny, n, m) && !vis[nx][ny])
			ret += dfs(nx, ny, rt, n, m);
	}
	return ret;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i ++)
		scanf("%s", str[i]);

	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			if(str[i][j] == '.' && !vis[i][j])
			{
				pair <int, int> rt = make_pair(i, j);
				size[i][j] = dfs(i, j, rt, n, m);
			}

	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < m; j ++)
			if(str[i][j] == '.')
				printf(".");
			else
			{
				int ans = 1;
				//pair <int, int> last_root = make_pair(-1, -1);
				set <pair <int, int> > old;
				for(int k = 0; k < 4; k ++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if(check(nx, ny, n, m) && old.find(root[nx][ny]) == old.end())
					{
						ans += size[root[nx][ny].first][root[nx][ny].second];
						old.insert(root[nx][ny]);
					}
				}
				printf("%d", ans % 10);
			}
		printf("\n");
	}
	return 0;
}