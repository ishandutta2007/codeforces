#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long n, x, y;
	cin >> n >> x >> y;
	int ans = (x & 1) ^ (y & 1);
	for (int i = 0; i < n; ++i) {
		long long p;
		cin >> p;
		ans ^= p & 1;
	}
	cout << (!ans ? "Alice" : "Bob") << '\n';
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