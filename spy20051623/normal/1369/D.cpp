#include <bits/stdc++.h>

using namespace std;
const int N = 2e6 + 5;
const int mod = 1e9 + 7;
long long a[N], b[N];

void solve() {
	int n;
	cin >> n;
	cout << a[n] * 4 % mod << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int i = 3; i < N; ++i) {
		a[i] = a[i - 1] + 2 * a[i - 2];
		if (!b[i - 1] && !b[i - 2]) ++a[i], ++b[i];
		a[i] %= mod;
	}
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}