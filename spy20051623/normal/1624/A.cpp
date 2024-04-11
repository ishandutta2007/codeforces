#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int mn = 1e9, mx = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		mn = min(mn, x);
		mx = max(mx, x);
	}
	cout << mx - mn << '\n';
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