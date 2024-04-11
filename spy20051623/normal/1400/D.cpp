#include <bits/stdc++.h>

using namespace std;

int h[10000005];
int a[100000];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	long long ans = 0;
	for (int i = 1; i < n - 2; ++i) {
		for (int j = 0; j < i; ++j) {
			++h[a[j] * 3001 + a[i]];
		}
		for (int j = i + 2; j < n; ++j) {
			ans += h[a[i + 1] * 3001 + a[j]];
		}
	}
	cout << ans << '\n';
	for (int i = 1; i < n - 2; ++i) {
		for (int j = 0; j < i; ++j) {
			--h[a[j] * 3001 + a[i]];
		}
	}
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