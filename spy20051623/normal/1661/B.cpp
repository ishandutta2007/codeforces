#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int ans = 100;
	for (int i = 0; i < 18; ++i) {
		int x = (n + i) % 32768, y = i;
		while (x) {
			++y;
			x = x * 2 % 32768;
		}
		ans = min(ans, y);
	}
	cout << ans << ' ';
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