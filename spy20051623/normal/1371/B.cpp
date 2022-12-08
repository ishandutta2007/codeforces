#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, r;
	cin >> n >> r;
	int x = min(n - 1, r);
	cout << 1ll * x * (x + 1) / 2 + (n <= r) << '\n';
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