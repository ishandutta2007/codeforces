#include <bits/stdc++.h>

using namespace std;

int a[1005], l[1005], r[1005];

void solve() {
	int n;
	cin >> n;
	r[n + 1] = 0;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) l[i] = i & 1 ? l[i - 1] + a[i] : l[i - 1] - a[i];
	for (int i = n; i >= 1; --i) r[i] = i & 1 ? r[i + 1] + a[i] : r[i + 1] - a[i];
	if (l[n] == 0) {
		cout << n << '\n';
		for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	cout << n - 1 << '\n';
	for (int i = 1; i <= n; ++i) {
		if (l[i - 1] == r[i + 1]) {
			for (int j = 1; j <= n; ++j) {
				if (j != i) cout << a[j] << ' ';
			}
			cout << '\n';
			return;
		}
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