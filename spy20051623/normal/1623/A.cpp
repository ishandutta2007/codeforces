#include <bits/stdc++.h>

using namespace std;

void solve() {
	int x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	int t1 = x1 <= x2 ? x2 - x1 : x - x1 + x - x2;
	int t2 = y1 <= y2 ? y2 - y1 : y - y1 + y - y2;
	cout << min(t1, t2) << '\n';
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