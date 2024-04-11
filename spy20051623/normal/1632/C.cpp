#include <bits/stdc++.h>

using namespace std;

int calc(int a, int b) {
	int p = 1, q = 0, t = 0;
	while (p <= a) {
		if (!(a & p) && (b & p)) t += p;
		if ((a & p) && !(b & p)) q += p - t, t = 0;
		p <<= 1;
	}
	return q;
}

void solve() {
	int a, b;
	cin >> a >> b;
	int ans = b - a;
	for (int i = 0; i <= b - a; ++i) {
		ans = min(ans, i + calc(a + i, b) + 1);
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