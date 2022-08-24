#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;
const int MAXN = 55;

int xc[4] = {1, -1, 0, 0};
int yc[4] = {0, 0, 1, -1};
bool seen[MAXN][MAXN];
bool board[MAXN][MAXN];
int n, m;

void flood (int x, int y)
{
	if (seen[x][y] || !board[x][y])
		return;
	seen[x][y] = true;
	for (int i = 0; i < 4; i++)
		flood (x + xc[i], y + yc[i]);
}

int main()
{
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			seen[i][j] = board[i][j] = false;
	cin >> n >> m;
	int count = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			char ch;
			cin >> ch;
			if (ch == '#')
			{
				board[i][j] = true; count++;}
		}
	if (count <= 2)
	{
		cout << "-1\n";
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			for (int k = 0; k < MAXN; k++) for (int l = 0; l < MAXN; l++) seen[k][l] = false;
if (board[i][j])
{
	for (int k = 0; k < 4; k++)
		if (board[i+xc[k]][j+yc[k]])
		{
			board[i][j] = false;
			flood (i+xc[k], j+yc[k]);
			for (int l = 1; l <= n; l++)
				for (int o = 1; o <= m; o++)
					if (board[l][o] && !seen[l][o])
					{
						cout << "1\n";
						return 0;
					}
			board[i][j] = true;
			break;
		}
}
}
cout << "2\n";
return 0;
}