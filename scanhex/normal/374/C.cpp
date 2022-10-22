#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define long long long

using namespace std;

vector<vector<int>> used;
vector<vector<int>> maxx;
vector<vector<char>> matr;

char next(char x)
{
	switch (x)
	{
	case 'D':
		return 'I';
	case 'I':
		return 'M';
	case 'M':
		return 'A';
	case 'A':
		return 'D';
	}
}

const int INF = INT_MAX / 2;

vector<int> DX = { -1, 0, 1, 0 };
vector<int> DY = { 0, 1, 0, -1 };

int dfs(int x, int y, char from)
{
	if (x < 0 || y < 0 || x >= matr.size() || y >= matr[0].size())
		return -1;
	if (next(from) != matr[x][y])
		return -1;
	if (used[x][y] == 1)
		return INF;
	if (used[x][y] == 2)
		return maxx[x][y];
	used[x][y] = 1;
	maxx[x][y] = 1;
	for (int i = 0; i < DX.size(); ++i)
	{
		maxx[x][y] = max(maxx[x][y], 1 + dfs(x + DX[i], y + DY[i], matr[x][y]));
	}
	used[x][y] = 2;
	return maxx[x][y];
}

int main()
{
	int n, m;
	cin >> n >> m;
	matr = vector<vector<char>>(n, vector<char>(m));
	used = maxx = vector<vector<int>>(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j)
			matr[i][j] = s[j];
	}
	int maxi = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			maxi = max(maxi, dfs(i, j, 'A'));
	if (maxi >= INF - 5)
		cout << "Poor Inna!";
	else if (maxi < 4)
		cout << "Poor Dima!";
	else
		cout << maxi / 4;
	return 0;
}