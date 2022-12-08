#include <bits/stdc++.h>

using namespace std;

int a[100][100], x[100], y[100];

void solve() {
	memset(x, 0, sizeof x);
	memset(y, 0, sizeof y);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j]) {
				x[i] = 1;
				y[j] = 1;
			}
		}
	}
	int cx = 0, cy = 0;
	for (int i = 0; i < n; ++i) {
		if (!x[i]) ++cx;
	}
	for (int i = 0; i < m; ++i) {
		if (!y[i]) ++cy;
	}
	if (min(cx, cy) & 1) cout << "Ashish\n";
	else cout << "Vivek\n";
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