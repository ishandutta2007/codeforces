#include <bits/stdc++.h>

using namespace std;

long long a[10000];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long g[2] = {0, 0};
	for (int i = 0; i < n; ++i) {
		g[i & 1] = gcd(g[i & 1], a[i]);
	}
	for (int i = 0; i < 2; ++i) {
		bool ok = true;
		for (int j = i ^ 1; j < n; j += 2) {
			if (a[j] % g[i] == 0) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << g[i] << '\n';
			return;
		}
	}
	cout << 0 << '\n';
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