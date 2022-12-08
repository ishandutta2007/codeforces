#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] < 0) ++cnt;
	}
	for (int i = 0; i < n; ++i) {
		if (i < cnt) a[i] = -abs(a[i]);
		else a[i] = abs(a[i]);
	}
	for (int i = 1; i < n; ++i) {
		if (a[i] < a[i - 1]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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