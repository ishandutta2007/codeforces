#include <bits/stdc++.h>

using namespace std;

int a[100005];

void solve() {
	int n, x;
	cin >> n >> x;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % x) {
		cout << n << '\n';
		return;
	}
	int l = 1e9, r = 1e9;
	for (int i = 0; i < n; ++i) {
		if (a[i] % x) {
			l = i;
			break;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (a[n - 1 - i] % x) {
			r = i;
			break;
		}
	}
	if (l > n) cout << "-1\n";
	else cout << n - min(l, r) - 1 << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}