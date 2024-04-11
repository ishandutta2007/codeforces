#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll ceilDiv(ll a, ll b) {
	return a / b + (a % b != 0);
}

int main() {
	ll k, b, n, t; scanf("%lld %lld %lld %lld", &k, &b, &n, &t);
	if (k == 1) {
		// the bacteria at time x is a_0 + (x - 1)b
		// 1 + (n - 1)b <= t + (ans - 1)b
		// 1 + nb - b <= t + ans * b - b
		// (1 + nb - t) / b <= ans
		printf("%lld\n", max(0LL, ceilDiv(1 + n * b - t, b)));
		return 0;
	}
	for (ll expt = 0, cval = 1;; expt++, cval *= k) {
		if (cval * (k + b - 1) > t * k + b - t) {
			ll xval = expt - 1;
			printf("%lld\n", max(0LL, n - xval));
			return 0;
		}
	}
}