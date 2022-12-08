#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
	long long n, k;
	cin >> n >> k;
	int mn = 1e9 + 5;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mn = min(mn, a[i]);
	}
	for (int i = 0; i < n; ++i) {
		a[i] -= mn;
	}
	int mx = -1;
	for (int i = 0; i < n; ++i) {
		mx = max(mx, a[i]);
	}
	if (k & 1) {
		for (int i = 0; i < n; ++i) {
			a[i] = mx - a[i];
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
	cout << '\n';
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