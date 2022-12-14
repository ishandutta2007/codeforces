#include <bits/stdc++.h>
using namespace std;

int x, y, p, q, xx, pp, TT, t;

int main() {
	scanf("%d", &TT);
	while (TT --) {
		scanf("%d %d %d %d", &x, &y, &p, &q);
		pp = q - p;
		xx = y - x;
		if ((!pp && xx) || (!p && x)) {
			puts("-1");
			continue;
		}
		if (!pp || !p) {
			puts("0");
			continue;
		}
		int d = __gcd(p, pp);
		p /= d;
		pp /= d;
        t = max((x + p - 1) / p, (xx + pp - 1) / pp);
        printf("%I64d\n", 1ll * q * t - y);
	}
	return 0;
}