#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, q;
	std::cin >> n >> q;
	std::vector<i64> a(n + 1), s(n + 1), x(n + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		s[i] = s[i - 1] + a[i];
		x[i] = x[i - 1] ^ a[i];
	}
	std::function<i64(int, int)> val = [&](int l, int r) {
		if (r < l) return -1ll;
		return s[r] - s[l - 1] - (x[r] ^ x[l - 1]);
	};
	while (q--) {
		int l, r;
		std::cin >> l >> r;
		int L = l, R = r, al = 1, ar = n;
		i64 ans = val(l, r);
		while (R > L && val(L, R - 1) == ans) --R;
		if (R - L < ar - al) al = L, ar = R;
		while (L < r) {
			++L;
			while (R <= r && val(L, R) != ans) ++R;
			if (R <= r) {
				if (R - L < ar - al) al = L, ar = R;
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