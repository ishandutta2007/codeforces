//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll T, n, a[N];
map<ll, ll> mp;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		mp.clear();
		scanf("%lld", &n);
		ll s = 0, ex = 0, ans = 0;
		rep(i, 1, n) {
			scanf("%lld", &a[i]);
			s += a[i];
			++mp[a[i]];
		}
		if((s * 2) % n) {puts("0"); continue;}
		ex = s * 2 / n; 
		rep(i, 1, n) {
			if(ex - a[i] > a[i]) ans += mp[ex-a[i]];
		}
		if(!(ex % 2)) ans += mp[ex/2] * (mp[ex/2] - 1) / 2;
		printf("%lld\n", ans);
	}
	return 0;
}