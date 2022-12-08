#include <bits/stdc++.h>

using namespace std;

int a[100005];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	bool ok = false;
	for (int i = 1; i < n - 1; ++i) {
		if (a[i] >= 2) {
			ok = true;
			break;
		}
	}
	if (n == 3 && (a[1] & 1)) ok = false;
	if (!ok) {
		cout << "-1\n";
		return;
	}
	long long ans = 0;
	for (int i = 1; i < n - 1; ++i) {
		ans += (a[i] + 1) / 2;
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