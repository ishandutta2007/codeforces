#include <cstdio>

typedef long long ll;

const ll MOD = 1E9 + 7, INV2 = 5E8 + 4;

int main(){
	ll n, m, n0;
	scanf("%I64d%I64d", &n, &m);
	for (n0 = 1; n0 * n0 <= n; ++n0);
	--n0;
	ll tn = n % MOD, ans = 0;
	if (n < m){
		ans = (m - n) % MOD * tn % MOD;
		m = n;
	}
	if (m < n0){
		for (int i = 1; i <= m; ++i)
			ans += n % i;
		ans %= MOD;
	}
	else{
		ll sum = 0;
		for (int i = 1; i <= n0; ++i){
			sum = (sum + n - n % i) % MOD;
			ll l = n / (i + 1) + 1, r = n / i;
			if (l <= m){
				if (m < r)
					r = m;
				sum = (sum + (r + l) % MOD * ((r - l + 1) % MOD) % MOD * INV2 % MOD * i) % MOD;
			}
		}
		if (n - n0 * n0 < n0)
			sum = (sum + MOD - n0 * n0 % MOD) % MOD;
		ans = (ans + m % MOD * tn % MOD + MOD - sum) % MOD;
	}
	printf("%I64d\n", ans);
	return 0;
}