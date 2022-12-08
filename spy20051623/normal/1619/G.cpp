#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int fa[N], w[N];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void solve() {
	map<int, map<int, int>> m1, m2;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		int x, y, t;
		cin >> x >> y >> t;
		fa[i] = i;
		w[i] = t;
		m1[x][y] = i;
		m2[y][x] = i;
	}
	for (auto &i: m1) {
		for (auto j = ++i.second.begin(); j != i.second.end(); ++j) {
			auto it = j;
			--it;
			if (j->first - it->first <= k) {
				int x = it->second, y = j->second;
				w[find(x)] = min(w[find(x)], w[find(y)]);
				fa[find(y)] = find(x);
			}
		}
	}
	for (auto &i: m2) {
		for (auto j = ++i.second.begin(); j != i.second.end(); ++j) {
			auto it = j;
			--it;
			if (j->first - it->first <= k) {
				int x = it->second, y = j->second;
				w[find(x)] = min(w[find(x)], w[find(y)]);
				fa[find(y)] = find(x);
			}
		}
	}
	vector<int> v;
	for (int i = 1; i <= n; ++i) {
		if (fa[i] == i) v.push_back(w[i]);
	}
	sort(v.begin(), v.end());
	int l = 0, r = 3e5, ans;
	while (l <= r) {
		int m = (l + r) >> 1;
		int x = v.size() - (upper_bound(v.begin(), v.end(), m) - v.begin());
		if (x <= m + 1) ans = m, r = m - 1;
		else l = m + 1;
	}
	cout << ans << '\n';
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