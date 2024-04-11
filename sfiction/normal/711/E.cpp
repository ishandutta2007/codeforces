#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1E6 + 3;

ll modExp(ll e, ll n, ll m = MOD){
	ll ret = 1;
	for (; n; n >>= 1, e = e * e % m)
		if (n & 1)
			ret = ret * e % m;
	return ret;
}

int main(){
	ll n, k;
	scanf("%I64d%I64d", &n, &k);
	if (n < 60 && (1ll << n) < k)
		puts("1 1");
	else{
		ll cnt = n;
		for (ll t = k - 1; t; cnt += t >>= 1);
		ll A = 1, tB = modExp(2, n), C = modExp(modExp(2, MOD - 2), cnt);
		ll B = modExp(tB, k) * C % MOD;
		if (k >= MOD)
			A = 0;
		else{
			for (int i = 0; i < k; ++i)
				A = A * (tB + MOD - i) % MOD;
			A = A * C % MOD;
		}
		printf("%I64d %I64d\n", (B + MOD - A) % MOD, B);
	}
	return 0;
}