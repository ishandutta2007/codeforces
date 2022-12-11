#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
constexpr ll MOD = 998244353;

/*
2ang must be an integer multiple of 360/n

ergo 2*ang = 360*k/n
so 2*ang*n = 360*k

so we have to find some n such that 2*ang*n is divisible by 360
obviously n = 360 works, so we just have to check if smaller is possible

additional condition: k is the number of sides we cover.
for this config to work, ang 

*/

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		ll ang; scanf("%lld", &ang);
		ll ans = -1;
		for (int pans = 3; pans <= 360; ++pans) {
			if (2*ang*pans % 360 == 0) {
				ll sct = 2*ang*pans/360;
				if (sct >= pans - 1) continue;
				ans = pans;
				break;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}