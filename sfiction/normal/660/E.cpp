#include <cstdio>

typedef long long ll;

const ll MOD = 1E9 + 7;

ll modExp(ll e, ll n, ll m = MOD){
	ll ret = 1;
	for (; n; n >>= 1, e = e * e % MOD)
		if (n & 1)
			ret = ret * e % MOD;
	return ret;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d", m > 1 ? (int)((m * modExp(2 * m - 1, n) % MOD - modExp(m, n) + MOD) % MOD * modExp(m - 1, MOD - 2) % MOD) : n + 1);
	return 0;
}