#include <bits/stdc++.h>
using i64 = long long;
i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
	if (b == 0) return x = 1, y = 0, a;
	i64 r = exgcd(b, a % b, y, x);
	return y -= a / b * x, r;
}
void solve() {
	i64 a, b, d, c = 0, p = 1 << 30, x, y, l;
	scanf("%lld%lld%lld", &a, &b, &d);
	while (!(d & 1)) d >>= 1, p >>= 1, ++c;
	if ((l = (1 << c) - 1), (a & l) || (b & l)) return printf("-1\n"), void();
	exgcd(p, d, x, y), x = ((x - 1) % d + d) % d;
	printf("%lld\n", x << 30 | (p - 1) << c);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
}