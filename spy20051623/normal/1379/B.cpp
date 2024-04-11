#include <bits/stdc++.h>

using namespace std;

void solve() {
	//A
	long long m, l, r;
	cin >> l >> r >> m;
	int d = r - l;
	for (int i = l; i <= r; ++i) {
		int s = m % i;
		if (s <= d && m / i > 0) {
			cout << i << ' ' << l + s << ' ' << l << '\n';
			return;
		}
		s = i - s;
		if (s <= d && m / i >= 0) {
			cout << i << ' ' << r - s << ' ' << r << '\n';
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