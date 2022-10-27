#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t;
LL f(LL n, LL x) {
	LL bridge = n - x;
	LL mx = x * (x - 1) / 2;
	return bridge + min(bridge, mx);
}
int main() {
	scanf("%d", &t);
	while (t --) {
		int n; scanf("%d", &n);
		// bridge: n - x
		// max: x * (x - 1) / 2
		LL lef = 1, rig = 100000;
		while (rig - lef > 1) {
			LL mid = (lef + rig) >> 1;
			if (n - mid >= mid * (mid - 1) / 2) lef = mid;
			else rig = mid;
		}
		LL ans = max(f(n, lef), f(n, lef + 1));
		printf("%lld\n", ans);
	}
}