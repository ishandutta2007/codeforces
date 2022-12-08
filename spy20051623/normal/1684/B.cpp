#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long a[3];
	for (long long &i: a) cin >> i;
	for (int i = 0; i < 3; ++i) {
		long long b[3];
		b[i] = a[i];
		b[(i + 2) % 3] = 1000000000 * a[i] + a[(i + 2) % 3];
		b[(i + 1) % 3] = b[(i + 2) % 3] + a[(i + 1) % 3];
		bool ok = true;
		for (int j = 0; j < 3; ++j) {
			if (b[j] % b[(j + 1) % 3] != a[j]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << b[0] << ' ' << b[1] << ' ' << b[2] << '\n';
			return;
		}
	}
	assert(0);
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