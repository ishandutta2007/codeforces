//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

ll T, a, m;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll phi(ll x) {
	ll ans = x;
	for(ll i=2;i*i<=x;i++) {
		if(!(x % i)) {
			ans = ans / i * (i - 1);
			while(!(x % i)) x /= i;
		}
	}
	if(x > 1) ans = ans / x * (x - 1);
	return ans;
}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &a, &m);
		m /= __gcd(a, m);
		printf("%lld\n", phi(m));
	}
	return 0;
}