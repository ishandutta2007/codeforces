#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

const int N = 300, M = 300;
deque<char> ss[N][M];
string ans[N][M];
string ans1[N][M];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			cin >> s;
			for (auto& x : s)
				ss[i][j].push_back(x);
		}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> ans[i][j], ans1[i][j] = ans[i][j];
	vector<tuple<int, int, int, int>> ansich;
	auto que = [&](int x1, int y1, int x2, int y2)
	{
		if (x1 == x2 && y1 == y2)
		{
			 cerr << "bad " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
		}
		assert(ss[x1][y1].size());
		ansich.push_back({x1, y1, x2, y2});
		ss[x2][y2].push_front(ss[x1][y1].back());
		ss[x1][y1].pop_back();
	};
	auto print = [&]()
	{
		return 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				for (int k = 0; k < ss[i][j].size(); ++k)
					cerr << ss[i][j][k];
				cerr << " \n"[j == m - 1];
			}
	};
	while (ss[0][0].size())
	{
		if (ss[0][0].back() == '0')
			que(0, 0, 0, m - 1);
		else
			que(0, 0, n - 1, 0);
	}
	int n1 = n - 1, m1 = m - 1;
	while (ss[n1][m1].size())
	{
		if (ss[n1][m1].back() == '0')
			que(n1, m1, 0, m - 1);
		else
			que(n1, m1, n - 1, 0);
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (i == 0 || i == n1)
				continue;
			while (ss[i][j].size())
			{
				 if (ss[i][j].back() == '0')
				 {
					 que(i, j, 0, j);
				 }
				 else
				 {
					 que(i, j, n1, j);
				 }
			}
		}
	for (int it = 0; it < 2; ++it)
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (i > 0 && i < n1)
				continue;
			if (i == 0 && j == 0)
				continue;
			if (i == n1 && j == m1)
				continue;
			while (ss[i][j].size())
			{
				 if (ss[i][j].back() == '0')
				 {
					 if (i == 0)
						 que(i, j, 0, 0);
					 else
						 que(i, j, 0, j);
				 }
				 else
				 {
					 if (i == n1)
						 que(i, j, n1, m1);
					 else
						 que(i, j, n1, j);
				 }
			}
		}
	vector<pair<int, int>> ord;
	for (int i = 1; i < n - 1; ++i)
		for (int j = 0; j < m; ++j)
		{
			ord.emplace_back(i, j);
		}
	auto proc = [&](int x, int y)
	{
		while (ans[x][y].size())
		{
			if (ans[x][y].back() == '0')
			{
				if (y > 0)
					que(0, 0, 0, y);
				if (x > 0)
					que(0, y, x, y);
			}
			else
			{
				if (y < m1)
					que(n1, m1, n1, y);
				if (x < n1)
					que(n1, y, x, y);
			}
			ans[x][y].pop_back();
		}
	};
	for (auto p : ord)
	{
		int x = p.first, y = p.second;
		proc(x, y);
	}
	for (int j = 1; j < m1; ++j)
	{
		int cnt = count(ans[n1][j].begin(), ans[n1][j].end(), '0');
		for (int x = 0; x < cnt; ++x)
			que(0, 0, 0, j);
		cnt = count(ans[0][j].begin(), ans[0][j].end(), '1');
		for (int x = 0; x < cnt; ++x)
			que(n1, m1, n1, j);
	}
	for (int j = 1; j < m1; ++j)
	{
		while (ans[0][j].size())
		{
			 if (ans[0][j].back() == '0')
				 que(0, 0, 0, j);
			 else
				 que(n1, j, 0, j);
			 ans[0][j].pop_back();
		}
		while (ans[n1][j].size())
		{
			 if (ans[n1][j].back() == '0')
				 que(0, j, n1, j);
			 else
				 que(n1, m1, n1, j);
			 ans[n1][j].pop_back();
		}
	}
	print();
	while (ans[0][0].size())
	{
		if (ans[0][0].back() == '0')
			que(0, 0, 0, m1);
		else
			que(n1, m1, 0, m1);
		que(0, m1, 0, 0);
		ans[0][0].pop_back();
	}
	while (ans[n1][m1].size())
	{
		 if (ans[n1][m1].back() == '0')
			 que(0, 0, 0, m1);
		 else
			 que(n1, m1, 0, m1);
		 que(0, m1, n1, m1);
		 ans[n1][m1].pop_back();
	}
	print();
	proc(0, m1);
	proc(n1, 0);
	cout << ansich.size() << '\n';
	for (auto& [a, b, c, d] : ansich)
		cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << ' ' << d + 1 << '\n';
	print();

	return 0;
}