#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v[2];
	for (int i = 1; i <= n + n; ++i) {
		int p;
		cin >> p;
		v[p & 1].push_back(i);
	}
	int cnt = 0;
	for (auto &i: v) {
		for (int j = 0; j + 1 < i.size(); j += 2) {
			if (cnt++ < n - 1)
				cout << i[j] << ' ' << i[j + 1] << '\n';
		}
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