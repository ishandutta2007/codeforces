#include <bits/stdc++.h>

using namespace std;

int ask(int x, int y) {
	cout << "? " << x << ' ' << y << endl;
	int s;
	cin >> s;
	return s;
}

void solve() {
	long long ans = 0, k = 2;
	for (int i = 0; i < 30; ++i) {
		if (ans && ask(ans, ans + k) != k) ans |= k / 2;
		else if (!ans && ask(ans + k / 2, ans + k / 2 + k) == k) ans |= k / 2;
		k <<= 1;
	}
	cout << "! " << (1 << 30) - ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
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