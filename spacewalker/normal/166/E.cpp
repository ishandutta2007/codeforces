#include <cstdio>
#include <vector>
#include <algorithm>
#define NMAX 10000000
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
	int n; scanf("%d", &n);
	ll aw = 0;
	ll bw = 0;
	ll cw = 0;
	ll dw = 1;
	for (int i = 1; i <= n; ++i) {
		ll naw = (bw + cw + dw) % MOD;
		ll nbw = (aw + cw + dw) % MOD;
		ll ncw = (aw + bw + dw) % MOD;
		ll ndw = (aw + bw + cw) % MOD;
		aw = naw;
		bw = nbw;
		cw = ncw;
		dw = ndw;
	}
	printf("%lld\n", dw);
	return 0;
}