#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	n = unique(a, a + n) - a;
	if (n == 1 || a[0] >= 2) {
		cout << "YES\n";
		return;
	}
	if (a[0] == 1) {
		for (int i = 0; i < n - 1; ++i) {
			if (a[i] == a[i + 1] - 1) {
				cout << "NO\n";
				return;
			}
		}
		cout << "YES\n";
	} else {
		if (a[1] == 1) cout << "NO\n";
		else cout << "YES\n";
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