#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> g;

int main()
{
	int n, m; cin >> n >> m;
	g = vector<vector<bool>>(n, vector<bool>(n));
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		--a, --b;
		g[a][b] = g[b][a] = 1;
	}
	if (g[0][n - 1])
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				g[i][j] = !g[i][j];
	}
	int INF = 12345678;
	vector<int> d(n, INF);
	deque<int> q;
	q.push_back(0);
	d[0] = 0;
	while (q.size())
	{
		auto x = q.front();
		q.pop_front();
		for (int i = 0; i < n; ++i)
		{
			if (g[x][i] && d[x] + 1 < d[i])
				d[i] = d[x] + 1, q.push_back(i);
		}
	}
	if (d[n - 1] == INF)
		cout << -1 << endl;
	else
		cout << d[n - 1] << endl;
}