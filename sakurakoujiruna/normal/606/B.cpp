#include <iostream>
#include <map>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

const int N = 511;
bool vis[N][N];

int main()
{
	ios :: sync_with_stdio(false);
	map <char, int> dir;
	dir['U'] = 2;
	dir['D'] = 3;
	dir['L'] = 0;
	dir['R'] = 1;

	int n, m;
	cin >> n >> m;
	int x, y;
	cin >> x >> y;
	vis[x][y] = true;

	int sum = 0;
	string str;
	cin >> str;
	cout << 1 << ' ';
	for(int i = 0; i < str.size() - 1; i ++)
	{
		int d = dir[str[i]];
		int nx = x + dx[d];
		int ny = y + dy[d];
		int ans = 0;
		if(nx >= 1 && nx <= n
			&& ny >= 1 && ny <= m)
		{
			if(!vis[nx][ny])
				ans = 1;
			x = nx;
			y = ny;
		}
		vis[x][y] = true;
		//cout << x << ' ' << y << '\n';
		cout << ans << ' ';
		sum += ans;
	}
	cout << n * m - sum - 1 << '\n';
	return 0;
}