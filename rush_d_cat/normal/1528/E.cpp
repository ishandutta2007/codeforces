#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
ll mpow(ll a, ll x) {
	if (x == 0) return 1;
	ll t = mpow(a, x>>1);
	if (x % 2 == 0) return t * t % mod;
	return t * t % mod * a % mod;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; 
	cin >> n;
	n ++;
	auto add = [&](ll &x, ll y) {
		(x += y) %= mod;
	};
	auto norm = [&](ll & x) {
		x = (x % mod + mod) % mod;
	};
	vector< vector<ll> > dp(n + 1, vector<ll>(2, 0));
	vector<ll> sum(n + 1, 0);
	sum[0] = 1, dp[0][0] = 1;
	sum[1] = 2, dp[1][0] = 1;
	ll i6 = mpow(6,mod-2), i2 = mpow(2,mod-2);
	for (int i = 2; i <= n; i ++) {
		ll s = (dp[i-1][0] + dp[i-1][1]) % mod;
		dp[i][0] = s;
		dp[i][1] = (s * (s + 1) % mod * i2 % mod + s * (i>=2?(sum[i-2]-1):0) % mod) % mod;
		sum[i] = (sum[i-1] + dp[i][0] + dp[i][1]) % mod;
	}

	ll ans = 0;
	auto cal = [&](ll x) {
		return (x*(x-1)%mod*(x-2)%mod*i6%mod + x*(x-1)%mod*i2%mod*2%mod + x) % mod;
	};
	add(ans, 2 * (cal(sum[n-1]) - cal(sum[n-2])) - 1);
	// printf("%lld\n", ans);
	for (int i = 1; i < n; i ++) {
		add(ans, dp[i][1] * (dp[n-i][0] + dp[n-i][1] - 1) % mod);
	}
	cout << ans << endl;
}