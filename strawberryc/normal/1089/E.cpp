#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)

const int N = 10, M = 444;

int n, X[M], Y[M];

bool vis[N][N];

void dfs(int x, int y, int dep)
{
	int i;
	if (dep == n + 1)
	{
		if (x == 8 && y == 8)
		{
			For (i, 1, n + 1) printf("%c%d ", X[i] + 'a' - 1, Y[i]);
			std::cout << std::endl;
			exit(0);
		}
		return;
	}
	For (i, 1, 8) if (!vis[x][i])
	{
		vis[x][i] = 1;
		X[dep + 1] = x; Y[dep + 1] = i;
		dfs(x, i, dep + 1);
		vis[x][i] = 0;
	}
	For (i, 1, 8) if (!vis[i][y])
	{
		vis[i][y] = 1;
		X[dep + 1] = i; Y[dep + 1] = y;
		dfs(i, y, dep + 1);
		vis[i][y] = 0;
	}
}

int main()
{
	int i;
	std::cin >> n;
	vis[1][1] = 1; X[1] = Y[1] = 1;
	dfs(1, 1, 1);
	return 0;
}