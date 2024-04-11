#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

vector<vector<int>> g;

int cnt0 = 0;

void d(int u, int p, bool c)
{
	if (c == 0)
		++cnt0;
	for (int v : g[u])
		if (v != p)
			d(v, u, c ^ 1);
}

int main()
{
	int n;
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	d(0, -1, 0);
	cout << 1LL * cnt0 * (n - cnt0) - (n - 1) << endl;
}