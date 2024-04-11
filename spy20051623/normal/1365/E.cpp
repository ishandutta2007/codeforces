#include <bits/stdc++.h>

using namespace std;

long long a[1000];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			for (int k = j; k < n; ++k) {
				ans = max(ans, a[i] | a[j] | a[k]);
			}
		}
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
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}