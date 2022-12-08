#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long n, m, x, y;
	cin >> n >> m >> x >> y;
	if (y > min(n, m) || x + y > n + m) cout << "NO\n";
	else cout << "YES\n";
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