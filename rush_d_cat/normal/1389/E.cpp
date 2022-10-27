#include <bits/stdc++.h>
using namespace std;
typedef long long LL;  
int t;
LL m, d, w;
LL gcd(LL x, LL y) {
	return y == 0 ? x : gcd(y, x % y);
}
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%lld%lld%lld", &m, &d, &w);
		int k = (d - 1 + w) % w;
		LL lim = min(m, d); // 0 <= x < y < lim
		if (k == 0) {
			printf("%lld\n", lim * (lim - 1) / 2);
		} else {
			LL g = gcd(k, w);
			w /= g;
			LL h = lim / w;
			LL c1 = lim % w;
			LL c2 = w - c1;
			LL ans = c1 * (h + 1) * h / 2 + c2 * h * (h - 1) / 2;
			printf("%lld\n", ans);
		}
	}
}