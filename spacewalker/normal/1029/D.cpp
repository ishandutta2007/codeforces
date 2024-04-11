#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#include <map>

using namespace std;
typedef long long ll;
// 10^n * a + b = 0 mod k
// 10^n * a = -b mod k
// 
map<ll, ll> ascaled[15];

int numLength(int x) {
	if (x == 0) return 0;
	else return 1 + numLength(x / 10);
}

ll modpower10(int i, int k) {
	if (i == 0) return 1;
	else return (10 * modpower10(i - 1, k)) % k;
}

int main() {
	int n, k; scanf("%d %d", &n, &k);
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &arr[i]);
	}
	for (ll plen = 1, pow10 = 10; plen < 13; ++plen, pow10 = (pow10 * 10) % k) {
		for (int i = 0; i < n; ++i) {
			++ascaled[plen][(pow10 * arr[i]) % k];
			// printf("occ of %lld %lld\n", plen, (pow10 * arr[i]) % k);
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += ascaled[numLength(arr[i])][(k - arr[i] % k)%k];
		// printf("%lld matches with (%d, %lld)\n", arr[i], numLength(arr[i]), (k - arr[i] % k) % k);
		if ((modpower10(numLength(arr[i]), k) * arr[i] % k + arr[i] % k) % k == 0) {
			--ans;
		}
	}
	printf("%lld\n", ans);
	return 0;
}