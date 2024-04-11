#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		++mp[p];
	}
	for (auto i: mp) {
		if (i.second >= 3) {
			cout << i.first << '\n';
			return;
		}
	}
	cout << "-1\n";
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