#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		ll n; scanf("%I64d", &n);
		ll best = -1;
		for (ll sixCount = 0; sixCount < 2; ++sixCount) {
			for (ll nineCount = 0; nineCount < 4; ++nineCount) {
				ll rest = n - 6*sixCount - 9*nineCount;
				if (rest >= 0 && rest % 4 == 0) {
					best = max(best, sixCount + nineCount + rest/4);
				}
			}
		}
		printf("%I64d\n", best);
	}
	return 0;
}