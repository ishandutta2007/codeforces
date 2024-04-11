#include <bits/stdc++.h>

using namespace std;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

vector<int> a;
vector<string> matr;
vector<int> dir;
int sx = -1, sy = -1;

int ans = 0;

void calc()
{
	int cx = sx, cy = sy;
	for (int x : dir)
	{
		int y = a[x];
		cx += dx[y];
		cy += dy[y];
		if (cx < 0 || cy < 0 || cx >= matr.size() || cy >= matr[0].size() || matr[cx][cy] == '#')
			return;
		if (matr[cx][cy] == 'E')
		{
			++ans;
			return;
		}
	}
}

void gena(int x)
{
	if (x == 4)
		calc();
	else
		for (int i = 0; i < 4; ++i)
			if (!count(a.begin(), a.end(), i))
			{
				a.push_back(i);
				gena(x + 1);
				a.pop_back();
			}
}

int main()
{
	int n, m;
	cin >> n >> m;
	matr.resize(n);
	for (auto& x : matr)
		cin >> x;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (matr[i][j] == 'S')
				sx = i, sy = j;
	string s;
	cin >> s;
	dir.resize(s.size());
	for (int i = 0; i < s.size(); ++i)
		dir[i] = s[i] - '0';
	gena(0);
	cout << ans << endl;
}