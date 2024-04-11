#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int g = n / m;
	int a = n - g * m, b = m - a;
	for (int i = 0; i < k; ++i) {
		int st = i * a * (g + 1) % n;
		for (int j = 0; j < a; ++j) {
			cout << g + 1 << ' ';
			for (int l = 0; l < g + 1; ++l) {
				if (st >= n) st = 0;
				cout << st++ + 1 << ' ';
			}
			cout << '\n';
		}
		for (int j = 0; j < b; ++j) {
			cout << g << ' ';
			for (int l = 0; l < g; ++l) {
				if (st >= n) st = 0;
				cout << st++ + 1 << ' ';
			}
			cout << '\n';
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