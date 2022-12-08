#include <bits/stdc++.h>

using namespace std;

int a[505], b[505];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	multiset<pair<int, int>> p, q;
	for (int i = 0; i < n / 2; ++i) {
		int x = a[i], y = a[n - 1 - i];
		if (x > y) swap(x, y);
		p.emplace(x, y);
	}
	for (int i = 0; i < n / 2; ++i) {
		int x = b[i], y = b[n - 1 - i];
		if (x > y) swap(x, y);
		q.emplace(x, y);
	}
	if ((n & 1) && a[n / 2] != b[n / 2]) cout << "NO\n";
	else if (p == q) cout << "YES\n";
	else cout << "NO\n";
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