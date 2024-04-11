#include <bits/stdc++.h>

using namespace std;

using nagai = long long;

const int N = 100005;

vector<int> g[N];

int sz[N];

void d(int u, int p)
{
	sz[u] = 1;
	for (int v : g[u])
		if (v != p)
		{
			d(v, u);
			sz[u] += sz[v];
		}
}

vector<int> cur;

bool ok = true;

void d1(int u, int p)
{
	int c = 0;
	for (int v : g[u])
		if (v != p)
			++c, d1(v, u);
	if (c >= 2)
		ok = false;
	else if (c == 0)
		cur.push_back(u);
}


int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	d(0, -1);
	int mxi = 0;
	for (int i = 0; i < n; ++i)
		if (g[i].size() > g[mxi].size())
			mxi = i;
	vector<vector<int>> ans;
	for (int v : g[mxi])
	{
		d1(v, mxi);
		cur.push_back(mxi);
		ans.push_back(cur);
		cur.clear();
	}
	if (ok)
	{
		cout << "Yes\n";
		cout << ans.size() << '\n';
		for (auto x : ans)
		{
			for (auto y : x)
				cout << y + 1 << ' ';
			cout << '\n';
		}
	}
	else
		cout << "No\n";
}