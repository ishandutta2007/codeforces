#include <bits/stdc++.h>

using namespace std;
const int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
map<pair<int, int>, int> m;
pair<int, int> p[200005], ans[200005];
int vis[200005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		p[i] = make_pair(x, y);
		m[p[i]] = i;
	}
	queue<pair<int, int>> q;
	for (auto i: m) {
		for (auto j: d) {
			int x = i.first.first + j[0], y = i.first.second + j[1];
			if (m.find(make_pair(x, y)) == m.end()) {
				q.push(i.first);
				ans[i.second] = make_pair(x, y);
				vis[i.second] = 1;
				break;
			}
		}
	}
	while (!q.empty()) {
		auto i = q.front();
		q.pop();
		for (auto j: d) {
			int x = i.first + j[0], y = i.second + j[1];
			auto it = m.find(make_pair(x, y));
			if (it != m.end() && !vis[it->second]) {
				q.emplace(x, y);
				ans[it->second] = ans[m[i]];
				vis[it->second] = 1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
	return 0;
}