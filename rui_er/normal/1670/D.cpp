//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

ll T, n;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll f(ll x) {
	ll a = x / 3, b = (x - a) / 2, c = x - a - b;
	return 2 * (a * b + b * c + a * c);
}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld", &n);
		ll L = 0, R = 1000000001;
		while(L < R) {
			ll M = (L + R) >> 1;
			if(f(M) >= n) R = M;
			else L = M + 1;
		}
		printf("%lld\n", L);
	}
	return 0;
}