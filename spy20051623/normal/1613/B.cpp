#include <bits/stdc++.h>

using namespace std;

int a[200005];
int d[1000005];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		d[a[i]] = 1;
	}
	sort(a, a + n);
	for (int i = 1; i <= n / 2; ++i) {
		cout << a[i] << ' ' << a[0] << '\n';
	}
	for (int i = 0; i < n; ++i) {
		d[a[i]] = 0;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}