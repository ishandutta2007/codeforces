#include <iostream>
using namespace std;

const int N = 1024;
int ans[2][N][N];

void solve(int now, int x, int y, int dir)
{
	ans[now][x][y] = dir;
	ans[now][x + 1][y] = dir;
	ans[now][x][y + 1] = dir;
	ans[now][x + 1][y + 1] = dir * -1;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	ans[0][0][0] = 1;
	int now = 0;
	for(int k = 1; k <= n; k ++)
	{
		now ^= 1;
		for(int i = 0; i < (1 << (k - 1)); i ++)
			for(int j = 0; j < (1 << (k - 1)); j ++)
				solve(now, i * 2, j * 2, ans[now ^ 1][i][j]);
	}
	for(int i = 0; i < (1 << n); i ++)
	{
		for(int j = 0; j < (1 << n); j ++)
			if(ans[now][i][j] == 1)
				cout << '+';
			else
				cout << '*';
		cout << '\n';
	}
	return 0;
}