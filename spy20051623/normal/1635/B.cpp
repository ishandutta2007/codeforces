#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int a[N], b[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 2; i <= n - 1; ++i) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) b[i] = 1;
		else b[i] = 0;
	}
	int ans = 0;
	for (int i = 3; i <= n - 2; ++i) {
		if (b[i - 1] && b[i + 1]) {
			++ans;
			a[i] = max(a[i - 1], a[i + 1]);
			b[i - 1] = b[i + 1] = 0;
		}
	}
	for (int i = 1; i <= n - 1; ++i) {
		if (b[i + 1]) {
			++ans;
			a[i] = a[i + 1];
			b[i + 1] = 0;
		}
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << ' ';
	}
	cout << '\n';
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