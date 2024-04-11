#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

vector<int> col;
vector<vector<int>> g;
vector<vector<int>> dp;

vector<vector<int>> comp;
vector<bool> used;


int maxd = 0;
int maxdi = 0;

void dfs(int u, int p, int d)
{
	if (used[u])
		return;
	used[u] = true;
	if (d > maxd)
		maxd = d, maxdi = u;
	for (auto& x : g[u])
		dfs(x, u, d + int(col[u] != col[x]));
}


int main()
{
	int n;
	scanf("%d", &n);
	col.resize(n);
	g.resize(n);
	for (auto& x : col)
		scanf("%d", &x);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		g[b].push_back(a);
		g[a].push_back(b);
	}
	used.resize(n);
	dfs(0, 0, 0);
	fill(used.begin(), used.end(), false);
	dfs(maxdi, -1, 0);
	cout << (maxd + 1) / 2 << endl;
}