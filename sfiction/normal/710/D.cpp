#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y){
	if (b == 0){
		x = 1, y = 0;
		return a;
	}
	ll d = exgcd(b, a % b, x, y);
	ll t = y;
	y = x - a / b * y;
	x = t;
	return d;
}

ll mcount(ll a, ll  b, ll c){
	return a < b ? 0 : (a - b) / c + 1;
}

int main(){
	ll a1, b1, a2, b2, L, R;
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d\n", &a1, &b1, &a2, &b2, &L, &R);
	if (b2 < b1)
		swap(a1, a2), swap(b1, b2);
	ll k, l;
	ll d = exgcd(a1, -a2, k, l);
	if (d < 0)
		d = -d, k = -k, l = -l;

	if ((b2 - b1) % d)
		puts("0");
	else{
		for (; k < 0 || l < 0; )
			k += a2 / d, l += a1 / d;
		k *= (b2 - b1) / d, l *= (b2 - b1) / d;
		int t = min(k / (a2 / d), l / (a1 / d));
		k -= a2 / d * t, l -= a1 / d * t;
		ll X = a1 * k + b1;
		ll e = a1 * a2 / d;
		printf("%I64d\n", mcount(R, X, e) - mcount(L - 1, X, e));
	}
	return 0;
}