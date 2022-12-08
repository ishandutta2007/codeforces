#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		++mp[v[i]];
	}
	for (auto i: mp) {
		if (i.second & 1) {
			cout << "-1\n";
			return;
		}
	}
	vector<pair<int, int>> op;
	vector<int> ans;
	int p = 0, q = 1;
	while (p < v.size()) {
		while (v[q] != v[p]) ++q;
		ans.push_back((q - p) * 2);
		++p;
		int qq = q;
		while (p < q) op.emplace_back(qq + 1, v[p]), v.insert(v.begin() + 1 + qq++, 2, v[p++]);
		p = qq + 1;
		q = p + 1;
	}
	cout << op.size() << '\n';
	for (auto i: op) cout << i.first << ' ' << i.second << '\n';
	cout << ans.size() << '\n';
	for (int i: ans) cout << i << ' ';
	cout << '\n';
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