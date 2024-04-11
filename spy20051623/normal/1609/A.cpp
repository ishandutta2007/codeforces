#include <bits/stdc++.h>

using namespace std;

long long a[100];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		while (a[i] % 2 == 0) {
			a[i] /= 2;
			++cnt;
		}
	}
	long long maxm = 0, sum = 0;
	for (int i = 0; i < n; ++i) {
		maxm = max(maxm, a[i]);
		sum += a[i];
	}
	cout << (maxm << cnt) + sum - maxm << endl;
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