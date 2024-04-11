#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

const int N = 2e5 + 5;

set<int> g[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int>> es;
	for (int i = 0; i < m; ++i)
	{
		 int a, b;
		 cin >> a >> b;
		 --a, --b;
		 es.emplace_back(a, b);
	}
	vector<bool> dele(n);
	int curans = 0;
	for (auto& x : es)
	{
		g[x.first].insert(x.second);
		g[x.second].insert(x.first);
	}
	queue<int> que;
	function<void(int)> del = [&](int x)
	{
		if (dele[x])
			return;
		dele[x] = true;
		--curans;
		while (g[x].size())
		{
			int y = *g[x].begin();
			g[x].erase(g[x].begin());
			g[y].erase(x);
			if (g[y].size() < k)
				del(y);
		}
		g[x].clear();
	};
	curans = n;
	for (int i = 0; i < n; ++i)
	{
		if (g[i].size() < k)
			del(i);
	}
	vector<int> ans(m);
	for (int i = m - 1; i >= 0; --i)
	{
		ans[i] = curans;
		int a = es[i].first, b = es[i].second;
		g[a].erase(b);
		g[b].erase(a);
		if (g[a].size() < k)
			del(a);
		if (g[b].size() <  k)
			del(b);
	}
	for (int x : ans)
		cout << x << '\n';
	return 0;
}