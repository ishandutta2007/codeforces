#include <bits/stdc++.h>

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;
	std::string x, y, z;
	std::cin >> x >> y;
	std::sort(x.begin(), x.end());
	std::sort(y.begin(), y.end());
	x += 'z' + 1;
	y += 'z' + 1;
	int c = 0, f = -1;
	int p = 0, q = 0;
	for (int i = 0; p < n && q < m; ++i) {
		if (c == k) {
			if (f == 0) {
				f = 1;
				c = 1;
				z += y[q++];
			} else {
				f = 0;
				c = 1;
				z += x[p++];
			}
			continue;
		}
		if (x[p] < y[q]) {
			if (f != 0) {
				f = 0;
				c = 0;
			}
			z += x[p++];
		} else {
			if (f != 1) {
				f = 1;
				c = 0;
			}
			z += y[q++];
		}
		++c;
	}
	std::cout << z << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
}