#include <cstdio>

typedef long long ll;

const int MOD = 1E9 + 7;

ll modExp(ll e, ll n, ll m = MOD){
	ll ret = 1;
	for (; n; n >>= 1, e = e * e % m)
		if (n & 1)
			ret = ret * e % m;
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	bool flag = true, sign = true;
	ll m = 1, t;
	for (int i = 0; i < n; ++i){
		scanf("%I64d", &t);
		if (t != 1)
			flag = false;
		sign &= t & 1;
		m = t % (MOD - 1) * m % (MOD - 1);
	}
	if (flag){
		puts("0/1");
		return 0;
	}
	m = (m + MOD - 2) % (MOD - 1);
	int num = (modExp(2, m) + (sign & 1 ? -1 : 1)) * modExp(3, MOD - 2) % MOD, den = modExp(2, m);
	printf("%d/%d\n", num, den);
	return 0;
}