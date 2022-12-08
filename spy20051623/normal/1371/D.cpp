#include <bits/stdc++.h>

using namespace std;

int a[305][305];

void solve() {
	int n, m;
	cin >> n >> m;
	cout << (m % n ? 1 : 0) * 2 << '\n';
	int x = 0, y = 0;
	memset(a, 0, sizeof a);
	for (int i = 0; i < m; ++i) {
		a[x++][y++] = 1;
		if (x >= n) x -= n, ++y;
		y %= n;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j];
		}
		cout << '\n';
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