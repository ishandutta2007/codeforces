#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	--n;
	for (int i = 2; i < 100; ++i) {
		if (gcd(i, n - i) == 1) {
			cout << i << ' ' << n - i << ' ' << 1 << '\n';
			return;
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