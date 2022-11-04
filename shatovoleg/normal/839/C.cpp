#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> list_gr;
long double res = 0;

void dfs(int v, int p = -1, int d = 0, long double cur_prob = 1.0)
{
	if (v != 0 && list_gr[v].size() == 1)
	{
		res += cur_prob * d;
		return;
	}
	for (auto x : list_gr[v])
		if (x != p)
			dfs(x, v, d + 1, cur_prob / (long double)(list_gr[v].size() - 1 * (v != 0)));
}

int main()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	list_gr.resize(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		cin >> x >> y;
		--x, --y;
		list_gr[x].push_back(y);
		list_gr[y].push_back(x);
	}
	dfs(0);
	cout << fixed << setprecision(7) << res << endl;
}