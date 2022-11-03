#include <cstdio>

typedef long long ll;

const int MAXN = 1E6 + 10;
const ll MOD = 1E9 + 7;

ll expMod(ll e, ll n){
	ll ret = 1;
	for (; n; n >>= 1, e = e * e % MOD)
		if (n & 1)
			ret = ret * e % MOD;
	return ret;
}

int main(){
	int p, k;
	ll ans;
	scanf("%d%d", &p, &k);
	if (k == 0)
		ans = expMod(p, p - 1);
	else if (k == 1)
		ans = expMod(p, p);
	else{
		int cnt = 1;
		for (ll i = k; i > 1; i = i * k % p, ++cnt);
		ans = expMod(p, (p - 1) / cnt);
	}
	printf("%d\n", (int)ans);
	return 0;
}