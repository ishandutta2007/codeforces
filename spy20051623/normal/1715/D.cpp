#include <bits/stdc++.h>

using i64 = long long;

struct dt {
	int x, y, z;
};

void solve() {
	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n + 1, (1 << 30) - 1), b(n + 1);
	std::vector<dt> v;
	for (int i = 0; i < q; ++i) {
		dt d;
		std::cin >> d.x >> d.y >> d.z;
		if (d.x > d.y) std::swap(d.x, d.y);
		a[d.x] &= d.z;
		a[d.y] &= d.z;
		v.push_back(d);
	}
	std::sort(v.begin(), v.end(), [&](dt &x, dt &y) {
		return x.x < y.x;
	});
	for (int i = 0; i < q; ++i) {
		int j = i;
		while (j < q - 1 && v[j].x == v[j + 1].x) ++j;
		for (int k = 0; k < 30; ++k) {
			if (b[v[i].x] >> k & 1) continue;
			bool ok = true, vis = false;
			for (int l = i; l <= j; ++l) {
				if (!(v[l].z >> k & 1)) continue;
				vis = true;
				if (v[l].y == v[i].x || !(a[v[l].y] >> k & 1)) {
					ok = false;
					break;
				}
			}
			if (!vis) continue;
			if (ok) {
				for (int l = i; l <= j; ++l) {
					if (v[l].z >> k & 1) b[v[l].y] |= 1 << k;
				}
			} else {
				b[v[i].x] |= 1 << k;
			}
		}
		i = j;
	}
	for (int i = 1; i <= n; ++i) {
		std::cout << b[i] << ' ';
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#else
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
#endif
	int t = 1;
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}