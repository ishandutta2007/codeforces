#include <bits/stdc++.h>

using namespace std;

long long a[105], b[105];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	long long p = 2e9, f = 2e9;
	long long s = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] <= p) {
			long long d = f - p;
			s += d * (d + 1) / 2;
			f = a[i];
			p = a[i] - b[i];
			continue;
		}
		p = min(p, a[i] - b[i]);
	}
	long long d = f - p;
	s += d * (d + 1) / 2;
	cout << s << '\n';
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