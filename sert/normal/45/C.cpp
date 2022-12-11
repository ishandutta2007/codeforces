#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	string g;
	cin >> g;
	vector<int> a(n), nxt(n), prev(n);
	set<pair<int, pair<int, int>>> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		nxt[i] = (i + 1 < n ? i + 1 : -1);
		prev[i] = (i > 0 ? i - 1 : -1);
		if (i > 0 && g[i] != g[i - 1]) {
			s.insert(make_pair(abs(a[i] - a[i - 1]), make_pair(i - 1, i)));
		}
	}

	vector<pair<int, int>> ans;
	vector<bool> del(n, false);

	while (!s.empty()) {
		auto q = s.begin()->second;
		int v = q.first;
		int w = q.second;
		s.erase(s.begin());
		if (del[v] || del[w] || nxt[v] != w || prev[w] != v) continue;
		ans.emplace_back(v, w);
		int v1 = prev[v];
		int w1 = nxt[w];
		if (v1 != -1) nxt[v1] = w1;
		if (w1 != -1) prev[w1] = v1;
		nxt[v] = nxt[w] = prev[v] = prev[w] = -1;
		del[v] = del[w] = true;

		if (v1 != -1 && w1 != -1 && g[v1] != g[w1]) {
			s.insert(make_pair(abs(a[v1] - a[w1]), make_pair(v1, w1)));
		}
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
#ifdef SERT
	int t = 3;
	for (int i = 1; i < t; i++) {
		solve();
	}
#endif
}