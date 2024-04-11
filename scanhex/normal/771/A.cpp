#include <bits/stdc++.h>

using namespace std;

vector<int> c;
vector<bool> used;
vector<vector<int>> g;

void dfs(int x)
{
	if (used[x])
		return;
	used[x] = true; 
	c.push_back(x);
	for (int y : g[x])
		dfs(y);
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	g.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	used.resize(n);
	for (int i = 0; i < n; ++i)
	{
		if (!used[i])
		{
			c.clear();
			dfs(i);
			for (int x : c)
				if (g[x].size() != c.size() - 1)
				{
					cout << "NO" << endl;
					return 0;
				}

		}
	}
	cout << "YES" << endl;
}