#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
typedef long long nagai;

vector<int> uni;
vector<vector<int>> g;

vector<bool> isuni;
vector<int> cntuni;
vector<int> d;

void dfs1(int u, int p)
{
	cntuni[u] = isuni[u];
	for (int v : g[u])
	{
		if (v == p)
			continue;
		d[v] = d[u] + 1;
		dfs1(v, u);
		cntuni[u] += cntuni[v];
	}
}

nagai dfs2(int u, int p, int cnt)
{
	vector<pair<int, int>> buckets;
	for (int v : g[u])
		if (v != p)
			buckets.push_back({cntuni[v], v});
	buckets.push_back({isuni[u], u});
	sort(buckets.begin(), buckets.end());
	nagai cnt1 = 0;
	for (int i = 0; i + 1 < buckets.size(); ++i)
		cnt1 += buckets[i].first;
	nagai ans = (cntuni[u] - cnt) / 2LL * d[u];
	if (cnt1 + cnt < buckets.back().first)
		ans = cnt1 * d[u] + dfs2(buckets.back().second, u, cnt + cnt1);
	return ans;
}

int main()
{
	int n, k; cin >> n >> k;
	d.resize(n);
	k *= 2;
	for (int i = 0; i < k; ++i)
	{
		int x; cin >> x;
		uni.push_back(x - 1);
	}
	g.resize(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b; cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cntuni.resize(n);
	isuni.resize(n);
	for (auto& x : uni)
		isuni[x] = true;
	dfs1(0, -1);
	nagai ans = 0;
	for (int i : uni)
		ans += d[i];
	cout << ans - 2 * dfs2(0, -1, 0) << endl;

}