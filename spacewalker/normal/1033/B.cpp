#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		ll a, b; scanf("%lld %lld", &a, &b);
		// b^2 - a^2 = (b + a)(b - a)
		if (a - b > 1) {
			printf("NO\n");
		} else {
			ll tocheck = a + b;
			bool result = true;
			for (ll x = 2; x <= sqrt(tocheck); ++x) {
				// printf("%lld cdiv %lld\n", tocheck, x);
				if (tocheck % x == 0) {
					result = false;
					break;
				}
			}
			if (result) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}