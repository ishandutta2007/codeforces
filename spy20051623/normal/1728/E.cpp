#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;

long long exgcd(long long a, long long b, long long &x, long long &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	} else {
		long long r = exgcd(b, a % b, y, x);
		y -= a / b * x;
		return r;
	}
}

void solve() {
	int n;
	std::cin >> n;
	std::vector<i64> a(n + 1), b(n + 1), c(n + 1), s(n + 1);
	i64 sum = 0;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i] >> b[i];
		c[i] = a[i] - b[i];
		sum += b[i];
	}
	std::sort(c.begin() + 1, c.end(), std::greater<>());
	int v = 0;
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + c[i];
		if (c[i] >= 0) ++v;
	}
	int m;
	std::cin >> m;
	while (m--) {
		i64 x, y;
		std::cin >> x >> y;
		i64 p, q;
		i64 g = exgcd(x, y, p, q);
		if (n % g) {
			std::cout << "-1\n";
			continue;
		}
		p *= x * n / g;
		q *= y * n / g;
		i64 d = x * y / g;
		p = (p % d + d) % d;
		i64 L = (v - p) / d * d + p, R = L + d;
		i64 ans = -1;
		if (L >= 0 && L <= n) ans = std::max(ans, sum + s[L]);
		if (R >= 0 && R <= n) ans = std::max(ans, sum + s[R]);
		std::cout << ans << '\n';
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