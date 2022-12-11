#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll ceilDiv(ll a, ll b) {
	return a / b + (a % b == 0 ? 0 : 1);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		ll a, b, c, d; scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		if (a <= b) {
			printf("%lld\n", b);
			continue;
		}
		a -= b;
//		printf("simp %lld %lld %lld %lld\n", a, b, c, d);
		if (c <= d) {
			printf("-1\n");
		} else {
			printf("%lld\n", b + c * ceilDiv(a, c - d));
		}
	}
	return 0;
}