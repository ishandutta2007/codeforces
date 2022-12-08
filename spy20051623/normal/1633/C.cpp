#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long hc, dc, hm, dm, k, w, a;
	cin >> hc >> dc >> hm >> dm >> k >> w >> a;
	for (int i = 0; i <= k; ++i) {
		if ((hc - 1 + i * a) / dm >= (hm - 1) / (dc + (k - i) * w)) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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