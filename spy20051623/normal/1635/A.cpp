#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		ans |= x;
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