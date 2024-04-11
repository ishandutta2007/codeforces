#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long k, x, y;
	cin >> x >> y >> k;
	cout << (k * (y + 1) - 2) / (x - 1) + 1 + k << '\n';
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