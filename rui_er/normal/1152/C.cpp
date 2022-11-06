// mo ni sai 20220729 T2
//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

ll a, b;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll calc(ll a, ll b, ll k) {
	a += k; b += k;
	return a / __gcd(a, b) * b;
}

int main() {
// 	fileIO("abklcm");
	scanf("%lld%lld", &a, &b);
	if(a < b) swap(a, b);
	ll diff = a - b, ans = 0;
	for(ll i=1;i*i<=diff;i++) {
		if(!(diff % i)) {
			ll rem = a % i, k = (i - rem) % i;
			if(calc(a, b, k) < calc(a, b, ans) || calc(a, b, k) == calc(a, b, ans) && k < ans) ans = k;
			if(i * i < diff) {
				ll j = diff / i, rem = a % j, k = (j - rem) % j;
				if(calc(a, b, k) < calc(a, b, ans) || calc(a, b, k) == calc(a, b, ans) && k < ans) ans = k;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}