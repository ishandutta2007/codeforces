#include <bits/stdc++.h>

using namespace std;
const long long inf = 2e18;

struct edge {
	long long x, y, h;
};

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	map<long long, map<long long, long long>> mp;
	map<long long, map<long long, vector<edge>>> g;
	vector<long long> x(n);
	for (int i = 0; i < n; ++i) cin >> x[i];
	while (k--) {
		long long a, b, c, d, h;
		cin >> a >> b >> c >> d >> h;
		--a, --b, --c, --d;
		mp[a][b] = mp[c][d] = inf;
		g[a][b].push_back({c, d, h});
	}
	mp[0][0] = 0;
	mp[n - 1][m - 1] = inf;
	for (auto &i: mp) {
		auto &row = i.second;
		auto en = --row.end();
		for (auto it = row.begin(); it != en;) {
			long long cv = it->second, cp = it->first;
			++it;
			it->second = min(it->second, cv + x[i.first] * abs(it->first - cp));
		}
		en = row.begin();
		for (auto it = --row.end(); it != en;) {
			long long cv = it->second, cp = it->first;
			--it;
			it->second = min(it->second, cv + x[i.first] * abs(it->first - cp));
		}
		auto &rg = g[i.first];
		for (auto &j: rg) {
			if (mp[i.first][j.first] == inf) continue;
			for (auto &e: j.second) {
				mp[e.x][e.y] = min(mp[e.x][e.y], mp[i.first][j.first] - e.h);
			}
		}
	}
	if (mp[n - 1][m - 1] == inf) cout << "NO ESCAPE\n";
	else cout << mp[n - 1][m - 1] << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}