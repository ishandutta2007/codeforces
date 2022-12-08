#include <bits/stdc++.h>

using namespace std;

long long p[50];

void solve() {
	long long n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= 30; ++i) {
		if (n >= p[i]) n -= p[i], ++ans;
		else break;
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
	for (int i = 1; i <= 30; ++i) {
		p[i] = (1ll << i) * ((1ll << i) - 1) / 2;
	}
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}