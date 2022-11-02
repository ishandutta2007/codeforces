#include <bits/stdc++.h>
using namespace std;

int n, k;
basic_string<int> e[200005];
typedef long long ll;

int c[200005], d[200005], sz[200005];

void dfs1(int x, int p) {
	for (int y : e[x]) {
		if (y == p)
			continue;
		d[y] = d[x] + 1;
		dfs1(y, x);
		sz[x] += sz[y];
	}
	sz[x]++;
}

pair<ll, ll> dfs2(int x, int p) {
	ll r = 0, g = 0;
	for (int y : e[x]) {
		if (y == p)
			continue;
		auto [w, f] = dfs2(y, x);
		if (!c[x])
			r += f;
		r += w;
		g += f;
	}
	return {r, g + c[x]};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=1, u, v; i<n; i++)
		cin >> u >> v, e[u] += v, e[v] += u;
	dfs1(1, 1);
	vector<pair<int, int>> v;
	for (int i=1; i<=n; i++)
		v.emplace_back(sz[i]-d[i], i);
	sort(begin(v), end(v));
	for (int i=0; i<k; i++)
		c[v[i].second] = 1;
	cout << dfs2(1, 1).first << '\n';
}