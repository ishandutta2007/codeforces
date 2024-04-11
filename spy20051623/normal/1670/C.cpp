#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1), c(n + 1), d(n + 1), v(n + 1);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	for (int i = 0; i < n; ++i) c[a[i]] = b[i];
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		d[p] = 1;
	}
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		if (v[i] || c[i] == i) continue;
		int p = i, vis = 0;
		do {
			v[p] = 1;
			vis |= d[p];
			p = c[p];
		} while (p != i);
		if (!vis) ans = ans * 2 % 1000000007;
	}
	cout << ans << "\n";
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