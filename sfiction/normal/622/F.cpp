#include <cstdio>

typedef long long ll;

const int MAXK = 1E6 + 10;
const ll MOD = 1E9 + 7;

ll y[MAXK];

ll modExp(ll e, ll n, ll m = MOD){
	ll ret = 1;
	for (; n; n >>= 1, e = e * e % m)
		if (n & 1)
			ret = ret * e % MOD;
	return ret;
}

int main(){
	int n, K;
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= K + 1; ++i)
		y[i] = (y[i - 1] + modExp(i, K)) % MOD;
	if (n <= K + 1)
		printf("%d\n", (int)y[n]);
	else{
		ll num = n, den = 1;
		for (int i = 1; i <= K + 1; ++i){
			num = num * (n - i) % MOD;
			den = den * (MOD - i) % MOD;
		}
		den = modExp(den, MOD - 2);
		ll ans = 0;
		for (int i = 0; i <= K + 1; ++i){
			ans = (ans + num * modExp(n - i, MOD - 2) % MOD * den % MOD * y[i]) % MOD;
			den = den * modExp(i + 1, MOD - 2) % MOD * (MOD + i - K - 1) % MOD;
		}
		printf("%d", (int)ans);
	}
	return 0;
}