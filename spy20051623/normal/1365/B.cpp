#include <bits/stdc++.h>

using namespace std;

int a[10000], b[10000], c[10000];

void solve() {
	int n;
	cin >> n;
	vector<int> x, y;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		c[i] = a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	sort(c, c + n);
	int v[2] = {0, 0};
	for (int i = 0; i < n; ++i) {
		v[b[i]] = 1;
	}
	if (v[0] && v[1]) {
		cout << "YES\n";
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] != c[i]) {
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