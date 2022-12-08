#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	auto b = a;
	for (auto &i: b) {
		sort(i.begin(), i.end());
	}
	set<int> s;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] != b[i][j]) s.insert(j);
		}
	}
	if (s.empty()) cout << "1 1\n";
	else if (s.size() != 2) cout << "-1\n";
	else {
		for (int i = 0; i < n; ++i) {
			swap(a[i][*s.begin()], a[i][*++s.begin()]);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i][j] != b[i][j]) {
					cout << "-1\n";
					return;
				}
			}
		}
		cout << *s.begin() + 1 << ' ' << *++s.begin() + 1 << '\n';
	}
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