#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int ans = 0;
	while (n % 6 == 0) {
		n /= 6;
		++ans;
	}
	while (n % 3 == 0) {
		n /= 3;
		ans += 2;
	}
	if (n == 1) cout << ans << '\n';
	else cout << "-1\n";
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