#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

vector<vector<int>> g;

nagai ans;

int n, k;

vector<pair<nagai, nagai>> dfs(int u, int p)
{
//	cerr << u << " begin" << endl;
	vector<pair<nagai, nagai>> cur(k);
	cur[0].second++;
	for (int x : g[u])
	{
		if (x == p)
			continue;
		auto pa = dfs(x, u);
		vector<pair<nagai, nagai>> pa1(k);
		for (int i = 0; i < k; ++i)
		{
			int j = (i + 1) % k;
			pa1[j].first = pa[i].first + pa[i].second;
			pa1[j].second = pa[i].second;
		}
		pa = pa1;
		nagai ans1 = 0;
		for (int i = 0; i < k; ++i)
			for (int j = 0; j < k; ++j)
			{
				if (i + j > 0)
					ans1 += pa[j].second * cur[i].second;
				if (i + j > k)
					ans1 += pa[j].second * cur[i].second;
				ans1 += ((pa[j].first - j * pa[j].second) / k) * cur[i].second;
				ans1 += ((cur[i].first - i * cur[i].second) / k) * pa[j].second;
			}
		ans += ans1;
//		cerr << x << ' ' << ans1 << endl;
		for (int i = 0; i < k; ++i)
		{
			cur[i].first += pa[i].first;
			cur[i].second += pa[i].second;
//			cerr << j << ' ' << i << ' ' << pa[i].second << endl;
		}
	}
//	cerr << u << " end\n";
//	for (auto& x : cur)
//		cerr << x.first << ' ' << x.second << endl;
	return cur;
}

int main()
{
	scanf("%d %d", &n, &k);
	g.resize(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0, -1);
	cout << ans << endl;

}