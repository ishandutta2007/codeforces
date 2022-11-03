/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 553A
 */
#include <cstdio>

typedef long long ll;

const ll MOD = 1E9 + 7;

ll pm(ll e, ll n, ll m = MOD){
	ll ret = 1;
	for (; n; n >>= 1){
		if (n & 1){
			ret = ret * e % m;
		}
		e = e * e % m;
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	ll cnt = 0, ans = 1;
	for (int i = 0; i < n; ++i){
		int c;
		scanf("%d", &c);
		cnt += c;
		for (int i = 1; i < c; ++i)
			ans = ans * (cnt - i) % MOD * pm(i, MOD - 2) % MOD;
	}
	printf("%I64d\n", ans);
	return 0;
}