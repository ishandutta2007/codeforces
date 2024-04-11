#include <bits/stdc++.h>

using i64 = long long;

int qry(int x, int y) {
	std::cout << "? " << x << " " << y << std::endl;
	int s;
	std::cin >> s;
	return s;
}

void solve() {
	int n;
	std::cin >> n;
	int nn = 1 << n;
	std::vector<int> a(nn);
	for (int i = 0; i < nn; ++i) {
		a[i] = i + 1;
	}
	while (n > 1) {
		std::vector<int> b;
		for (int i = 0; i < nn; i += 4) {
			int x = qry(a[i], a[i + 2]);
			if (x == 0) {
				int y = qry(a[i + 1], a[i + 3]);
				if (y == 1) b.push_back(a[i + 1]);
				else b.push_back(a[i + 3]);
			} else if (x == 1) {
				int y = qry(a[i], a[i + 3]);
				if (y == 1) b.push_back(a[i]);
				else b.push_back(a[i + 3]);
			} else {
				int y = qry(a[i + 1], a[i + 2]);
				if (y == 1) b.push_back(a[i + 1]);
				else b.push_back(a[i + 2]);
			}
		}
		n -= 2;
		nn >>= 2;
		a = b;
	}
	int ans;
	if (n == 1) ans = qry(a[0], a[1]) == 1 ? a[0] : a[1];
	else ans = a[0];
	std::cout << "! " << ans << std::endl;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#else
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
#endif
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}