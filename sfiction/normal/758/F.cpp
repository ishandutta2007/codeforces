#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1E7 + 10;
const ll INF = 1E7 + 10;

ll quickExp(ll e, ll n, ll INF = 1E9 + 10){
	ll ret = 1;
	for (; n; n >>= 1){
		if (n & 1){
			if (INF / ret < e)
				return INF;
			ret *= e;
		}
		e = INF / e < e ? INF : e * e;
	}
	return ret;
}

int sqr(int n, int k){
	int ret = max<int>(1, pow(n - 0.5, 1. / k));
	for (; quickExp(ret, k, n) < n; ++ret);
	return ret;
}

int val[MAXN];

int main(){
	ll n, l, r;
	scanf("%lld%lld%lld", &n, &l, &r);
	if (n == 1)
		printf("%lld\n", r - l + 1);
	else if (n == 2)
		printf("%lld\n", (r - l + 1) * (r - l));
	else{
		int l0 = sqr(l, n - 1), r0 = sqr(r + 1, n - 1);
		ll ans = 0;
		for (int i = 1; i < r0; ++i){
			val[i] = quickExp(i, n - 1);
			for (int j = 1; j < i; ++j){
				if (__gcd(i, j) > 1)
					continue;
				ans += max(0ll, r / val[i] - (l - 1) / val[j]);
			}
		}
		printf("%lld\n", ans << 1);
	}
	return 0;
}