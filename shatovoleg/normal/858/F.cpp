#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define inf 2000000000
#define mod 1000000009

void useFiles(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

vector<vector<int>> g;
vector<int> used;
vector<vector<int>> ans;

int solve(int v, int p = -1)
{
	vector<int> arr;
	used[v] = 1;
	for (auto x : g[v])
		if (x != p && used[x] == 1)
			arr.push_back(x);
	for (auto x : g[v])
	{
		if (!used[x])
		{
			int d = solve(x, v);
			if (d == -1)
				arr.push_back(x);
			else
				ans.push_back({v, x, d});
		}
	}
	used[v] = 2;
	for (int i = 0; i < (arr.size() >> 1); ++i)
		ans.push_back({arr[i << 1], v, arr[(i << 1) + 1]});
	if (arr.size() % 2 != 0)
		return arr.back();
	return -1;
}

int main()
{
	int n, m;
	cin >> n >> m;
	g.resize(n);
	used.resize(n, 0);
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 0; i < n; ++i)
		if (!used[i])
			solve(i);
	cout << ans.size() << endl;
	for (auto &v : ans)
	{
		for (auto &x : v)
			cout << x + 1 << " ";
		cout << endl;
	}
}