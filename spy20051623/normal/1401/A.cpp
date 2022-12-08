#include <bits/stdc++.h>

using namespace std;

void solve() {
	int x, y;
	cin >> x >> y;
	cout << (y > x ? y - x : y - x & 1) << '\n';
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