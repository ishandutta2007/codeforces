#include <bits/stdc++.h>

using namespace std;

int a[100000];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long x;
	cin >> x;
	int ans = 0, s = 0;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		if (i == s) {
			++ans;
			sum = a[i];
			continue;
		}
		if (sum + a[i] < x * (i - s + 1)) {
			s = i + 1;
			continue;
		}
		++ans;
		if (a[i] < x || a[s] >= x || s < i - 1) {
			s = i;
			sum = a[i];
		} else sum += a[i];
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