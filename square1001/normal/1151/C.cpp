#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
const int inv2 = (mod + 1) / 2;
int main() {
	long long L, R;
	cin >> L >> R; ++R;
	long long ans = 0, odd = 1, even = 2;
	for (int i = 0; i <= 60; ++i) {
		long long pl = (1LL << i), pr = (2LL << i);
		pl = max(pl, L);
		pr = min(pr, R);
		if (pl < pr) {
			long long s = (i % 2 == 0 ? odd + (pl - (1LL << i)) * 2 : even + (pl - (1LL << i)) * 2);
			long long g = s + (pr - pl - 1) * 2;
			ans += ((s + g) % mod) * (((g - s) / 2 + 1) % mod) % mod * inv2 % mod;
			ans %= mod;
		}
		if (i % 2 == 0) odd += 2LL << i;
		else even += 2LL << i;
	}
	cout << ans << endl;
	return 0;
}