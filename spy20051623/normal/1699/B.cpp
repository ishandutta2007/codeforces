#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n / 2; ++i) {
		for (int j = 0; j < m / 2; ++j) {
			if (i + j & 1) cout << "0 1 ";
			else cout << "1 0 ";
		}
		cout << "\n";
		for (int j = 0; j < m / 2; ++j) {
			if (i + j & 1) cout << "1 0 ";
			else cout << "0 1 ";
		}
		cout << "\n";
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}