#include <cstdio>

typedef long long ll;

const ll MOD = 1E9 + 7;

ll expMod(ll e, ll n, ll p = MOD){
	ll ret = 1;
	for (; n; n >>= 1, e = e * e % p)
		if (n & 1)
			ret = ret * e % p;
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", (int)((expMod(3, 3 * n) - expMod(7, n) + MOD) % MOD));
	return 0;
}