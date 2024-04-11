#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << "YES\n";
		for (int i = 1; i <= n; ++i) {
			cout << i << '\n';
		}
		return;
	}
	if (n & 1) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (int i = 0; i < n / 2; ++i) {
		for (int j = 0; j < k; ++j) {
			cout << 2 * i * k + 2 * j + 1 << ' ';
		}
		cout << '\n';
	}
	for (int i = 0; i < n / 2; ++i) {
		for (int j = 0; j < k; ++j) {
			cout << 2 * i * k + 2 * j + 2 << ' ';
		}
		cout << '\n';
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