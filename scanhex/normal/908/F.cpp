#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> r, g, b;
	vector<int> xs(n), type(n);
	vector<vector<int>> tp(3);
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		char ch;
		cin >> ch;
		xs[i] = x;
		if (ch == 'R')
			r.push_back(x), type[i] = 1;
		if (ch == 'G')
			g.push_back(x), type[i] = 2;
		if (ch == 'B')
			b.push_back(x), type[i] = 0;
	}
	for (int i = 0; i < n; ++i)
		tp[type[i]].push_back(xs[i]);
	vector<int> ptr(2);
	nagai ans = 0;
	for (int i = 0; i + 1 < g.size(); ++i)
	{
		nagai ans1 = 2LL * (g[i + 1] - g[i]);
		nagai ans2 = 3LL * (g[i + 1] - g[i]);
		for (int j = 0; j < 2; ++j)
		{
			vector<int> lst;
			lst.push_back(g[i]);
			while (ptr[j] < n && (type[ptr[j]] != j || xs[ptr[j]] < g[i]))
				++ptr[j];
			while (ptr[j] < n && xs[ptr[j]] < g[i + 1])
			{
				if (type[ptr[j]] == j)
					lst.push_back(xs[ptr[j]]);
				++ptr[j];
			}
			lst.push_back(g[i + 1]);
			int mx = 0;
			for (int i = 0; i + 1 < lst.size(); ++i)
				mx = max(mx, lst[i + 1] - lst[i]);
			ans2 -= mx;
		}
		ans += min(ans1, ans2);
	}
	if (g.size() == 0)
	{
		nagai ans = 0;
		if (b.size())
			ans += b.back() - b.front();
		if (r.size())
			ans += r.back() - r.front();
		cout << ans << endl;
		return 0;
	}
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < tp[i].size(); ++j)
		{
			if (tp[i][j] < g[0])
			{
				int mn = g[0] - tp[i][j];
				if (j + 1 < tp[i].size())
					mn = min(mn, tp[i][j + 1] - tp[i][j]);
				ans += mn;
			}
			if (tp[i][j] > g.back())
			{
				int mn = tp[i][j] - g.back();
				if (j > 0)
					mn = min(mn, tp[i][j] - tp[i][j - 1]);
				ans += mn;
			}
		}
	}
	cout << ans << endl;
}