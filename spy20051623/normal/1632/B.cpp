#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int nn = n - 1, p = 1;
	while (nn > 1) nn >>= 1, p <<= 1;
	for (int i = n - 1; i >= p; --i) cout << i << ' ';
	for (int i = 0; i < p; ++i) cout << i << ' ';
	cout << '\n';
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