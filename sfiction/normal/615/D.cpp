#include <cstdio>

typedef long long ll;

const int MAXP = 2E5 + 10;
const ll MOD = 1E9 + 7;

int cnt[MAXP], pre[MAXP], suf[MAXP];

ll expMod(ll e, ll n){
	ll ret = 1;
	for (; n; n >>= 1, e = e * e % MOD)
		if (n & 1)
			ret = ret * e % MOD;
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	for (int t, i = 0; i < n; ++i){
		scanf("%d", &t);
		++cnt[t];
	}
	for (int i = 0; i < MAXP; ++i)
		++cnt[i];
	ll tm = MOD - 1;
	pre[0] = cnt[0];
	for (int i = 1; i < MAXP; ++i)
		pre[i] = pre[i - 1] * (ll)cnt[i] % tm;
	suf[MAXP - 1] = cnt[MAXP - 1];
	for (int i = MAXP - 2; i >= 0; --i)
		suf[i] = suf[i + 1] * (ll)cnt[i] % tm;

	ll ans = 1;
	for (int i = 0; i < MAXP; ++i)
		if (cnt[i] > 1){
			ll t = cnt[i] * (ll)(cnt[i] - 1) >> 1;
			ans = ans * expMod(i, t % tm * pre[i - 1] % tm * suf[i + 1] % tm) % MOD;
		}
	printf("%I64d\n", ans);
	return 0;
}