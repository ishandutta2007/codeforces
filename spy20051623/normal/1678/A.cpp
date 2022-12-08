#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (a[0] == 0) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i]) ++cnt;
		}
		cout << cnt << "\n";
	} else {
		bool ok = 0;
		for (int i = 0; i < n - 1; ++i) {
			if (a[i] == a[i + 1]) ok = 1;
		}
		if (ok) cout << n << "\n";
		else cout << n + 1 << "\n";
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