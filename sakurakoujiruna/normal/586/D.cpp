#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 121;

bool map[5][N];
bool vis[5][N];

int dx[] = {-1, 1, 0};
int dy[] = {1, 1, 1};

bool bfs(int n, pair <int, int> init)
{
	queue <pair <int, int> > que;
	memset(vis, 0, sizeof(vis));
	que.push(init);
	vis[init.first][init.second] = true;

	while(!que.empty())
	{
		pair <int, int> p = que.front();
		que.pop();

		if(p.second >= n)
			return true;

		int x = p.first;
		int y = p.second;

		//cout << x << ' ' << y << '\n';

		if(map[x][y + 1])
			continue;

		for(int k = 0; k < 3; k ++)
		{
			int new_x = x + dx[k];
			int new_y = y + dy[k];
			if(!map[new_x][new_y] && !map[new_x][new_y + 1] && !map[new_x][new_y + 2])
				if(!vis[new_x][new_y + 2])
				{
					vis[new_x][new_y + 2] = true;
					que.push(make_pair(new_x, new_y + 2));
				}
		}
	}

	return false;
}

int main()
{
	ios :: sync_with_stdio(false);
	int case_cnt;
	cin >> case_cnt;
	while(case_cnt --)
	{
		int n, k;
		cin >> n >> k;
		memset(map, true, sizeof(map));

		int init_x;
		int init_y;
		for(int i = 0; i < 3; i ++)
		{
			string s;
			cin >> s;
			for(int j = 0; j < n; j ++)
				if(s[j] == '.')
					map[i + 1][j + 1] = false;
				else if(s[j] == 's')
				{
					map[i + 1][j + 1] = false;
					init_x = i + 1;
					init_y = j + 1;
				}
				else
				{
					map[i + 1][j + 1] = true;
				}
		}
		map[1][n + 1] = map[2][n + 1] = map[3][n + 1] = false;
		map[1][n + 2] = map[2][n + 2] = map[3][n + 2] = false;

		if(bfs(n, make_pair(init_x, init_y)))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}