#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, b, x, y;
	cin >> n >> b >> x >> y;
	int p = 0;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (p + x <= b) p += x;
		else p -= y;
		ans += p;
	}
	cout << ans << '\n';
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