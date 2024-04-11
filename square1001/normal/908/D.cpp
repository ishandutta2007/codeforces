#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
int binpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = (long long)ret * a % mod;
		a = (long long)a * a % mod;
		b >>= 1;
	}
	return ret;
}
int pa, pb, pinv, lim, dp[1009][1009]; bool vis[1009][1009];
int solve(int a, int rem) {
	if (vis[a][rem]) return dp[a][rem];
	int ret = 0, mul = 1;
	for (int i = 0; a + i < rem; ++i) {
		ret = (ret + (long long)solve(a + i, rem - a - i) * mul) % mod;
		mul = 1ll * mul * pa % mod;
	}
	ret = 1ll * ret * pb % mod;
	ret = (ret + (long long)mul * ((long long)pa * pinv % mod + max(lim, lim + a - rem))) % mod;
	vis[a][rem] = true;
	dp[a][rem] = ret;
	return ret;
}
int main() {
	int ra, rb;
	cin >> lim >> ra >> rb;
	long long ri = binpow(ra + rb, mod - 2);
	pa = ra * ri % mod;
	pb = rb * ri % mod;
	pinv = binpow(pb, mod - 2);
	cout << solve(1, lim) << '\n';
	return 0;
}