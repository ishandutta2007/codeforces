#include <bits/stdc++.h>

using namespace std;

void solve() {
	int x, y, z;
	cin >> x >> y >> z;
	cout << (z - y) / x * x + y << '\n';
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