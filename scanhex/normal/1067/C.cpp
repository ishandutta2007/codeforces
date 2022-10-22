#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

int check(int n, vector<pair<int, int>> mem)
{
	vector<vector<int>> matr(n, vector<int>(n));
	for (auto& x : mem)
		matr[x.first][x.second] = 4;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (matr[i][j] >= 4)
				cerr << '#';
			else
				cerr << '.';
		}
		cerr << '\n';
	}
	return mem.size();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> ansich;
	int sz = max(2 * n, 10);
	vector<vector<int>> matr(sz, vector<int>(sz));
	vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
	vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};
	int n2 = n / 2;
	int n3 = n / 3;
	int n4 = n / 4;
	queue<pair<int, int>> mem;
	int cntbad = 0;
	int sum = 0;
	auto add = [&](int x, int y)
	{
		x += n / 3;
		y += n / 3;
		if (matr[x][y] >= 4)
		{
			++cntbad;
			return;
		}
		ansich.emplace_back(x, y);
		return;
		mem.emplace(x, y);
		matr[x][y] = 4;
		while (mem.size())
		{
			++sum;
			int a = mem.front().first;
			int b = mem.front().second;
			mem.pop();
			for (int k = 0; k < dx.size(); ++k)
			{
				int a1 = a + dx[k], b1 = b + dy[k];
				if (a1 >= 0 && b1 >= 0 && a1 < n && b1 < n && ++matr[a1][b1] == 4)
					mem.emplace(a1, b1);
			}
		}
	};
	for (int i = 0; i < n3; i += 1)
	{
		add(i, i);
		add(i, i + 2);
	}
	if (n % 3 >= 1)
		add(n3, n3);
	if (n % 3 >= 2)
		add(n3, n3 + 2);
	for (int i = 3; i < n3 + 3; ++i)
	{
		add(i, 1);
	}
	/*
	for (int i = 2; i < n4 + 2; i += 1)
	{
		add(i, 0);
		add(n4 / 2 - 1, i);
	}
	*/
	/*
	cerr << cntbad << '\n';
	for (auto& x : ansich)
		x.first += n / 3, x.second += n / 3;
	set<pair<int, int>> st(ansich.begin(), ansich.end());
	assert(st.size() == ansich.size());
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (matr[i][j] >= 4)
				cerr << '#';
			else
				cerr << '.';
		}
		cerr << '\n';
	}
	cout << sum << '\n';
	cerr << ansich.size() << '\n';
	*/
	for (auto& x : ansich)
		cout << x.first << ' ' << x.second << '\n';
	return 0;
}