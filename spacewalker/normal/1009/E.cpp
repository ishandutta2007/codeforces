#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;
constexpr int MOD = 998244353;
constexpr int INV2 = (MOD + 1) / 2;
int main() {
	int n; scanf("%d", &n);
	ll aheadPower = 1;
	for (int i = 0; i < n - 1; ++i) aheadPower = (aheadPower << 1) % MOD;
	ll back = 0, ans = back * aheadPower, cTerm = back;
	for (int i = 0; i < n; ++i) {
		ll x; scanf("%lld", &x);
		cTerm = (cTerm * 2 - back + x + MOD) % MOD;
		ans = (ans + cTerm * aheadPower) % MOD;
		// printf("ct ahp %lld %lld\n", cTerm, aheadPower);
		back = x;
		aheadPower = (aheadPower * INV2) % MOD;
	}
	printf("%lld\n", ans);
}