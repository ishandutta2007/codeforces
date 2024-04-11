#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, q;
	std::cin >> n >> q;
	std::vector<i64> a(n + 1), s(1), x(1), b(1), id(1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		if (a[i]) {
			b.push_back(a[i]);
			id.push_back(i);
			s.push_back(s.back() + a[i]);
			x.push_back(x.back() ^ a[i]);
		}
	}
	std::function<i64(int, int)> val = [&](int l, int r) {
		if (r < l) return -1ll;
		return s[r] - s[l - 1] - (x[r] ^ x[l - 1]);
	};
	while (q--) {
		int l, r;
		std::cin >> l >> r;
		if (id.size() == 1) {
			std::cout << l << ' ' << l << '\n';
			continue;
		}
		int L = std::lower_bound(id.begin(), id.end(), l) - id.begin(),
				R = std::upper_bound(id.begin(), id.end(), r) - id.begin() - 1,
				al = 1, ar = n;
		if (L > R) {
			std::cout << l << ' ' << l << '\n';
			continue;
		}
		l = L, r = R;
		i64 ans = val(L, R);
		while (R > L && val(L, R - 1) == ans) --R;
		if (id[R] - id[L] < ar - al) al = id[L], ar = id[R];
		while (L < r) {
			++L;
			while (R <= r && val(L, R) != ans) ++R;
			if (R <= r) {
				if (id[R] - id[L] < ar - al) al = id[L], ar = id[R];
			} else break;
		}
		std::cout << al << ' ' << ar << '\n';
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
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}