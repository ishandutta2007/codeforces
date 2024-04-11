#include <bits/stdc++.h>

using namespace std;

void solve() {
	int l, r, k;
	cin >> l >> r >> k;
	if (l == r) {
		cout << (l != 1 ? "YES\n" : "NO\n");
		return;
	}
	if (!k) {
		cout << "NO\n";
		return;
	}
	cout << ((r - l + 1) / 2 + (l & r & 1) <= k ? "YES\n" : "NO\n");
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