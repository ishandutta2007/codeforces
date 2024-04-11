#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ll n, p; scanf("%lld %lld", &n, &p);
	for (int bc = 1; bc <= 40; ++bc) {
		ll adjSum = n - bc * p; // rep using exactly bc terms
		if (adjSum < 0) continue;
		ll minTermNeed = __builtin_popcountll(adjSum);
		if (adjSum >= bc && minTermNeed <= bc) {
			printf("%d\n", bc);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}