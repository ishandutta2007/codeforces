#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int NMAX = 2000010;

ll wtsHere[NMAX];

ll a, b, c, d;

ll sumWays(ll ib, ll jb, ll k) {
//	printf("SW %lld %lld %lld\n", ib, jb, k);
	ll ng = min(ib, jb);
	if (k < 0 || k > ib + jb) return 0;
	if (k <= ng) return k + 1;
	if (k >= ib + jb - ng) return ib + jb - k + 1;
	else return ng + 1;
}

int main() {
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	ll ans = 0;
	for (int x = 1; x < NMAX; ++x) {
		wtsHere[x] = sumWays(b - a, c - b, x - a - b);
//		if (wtsHere[x] > 0) printf("%d %lld\n", x, wtsHere[x]);
	}
	for (int i = NMAX - 2; i >= 0; --i) wtsHere[i] += wtsHere[i+1];
	for (ll x = c; x <= d; ++x) {
//		printf("%lld above %lld\n", wtsHere[x + 1], x);
		ans += wtsHere[x + 1];
	}
	printf("%lld\n", ans);
	return 0;
}