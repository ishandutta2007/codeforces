#include <bits/stdc++.h>

using namespace std;

int a[2000];

void solve() {
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		if (a[i] != x) {
			ok = false;
			break;
		}
	}
	if (ok) {
		cout << 0 << '\n';
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] == x) {
			ok = true;
			break;
		}
	}
	if (ok) {
		cout << 1 << '\n';
		return;
	}
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
	}
	if (sum == x * n) {
		cout << 1 << '\n';
		return;
	}
	cout << 2 << '\n';
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