//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 ll T; for(scanf("%lld", &T);T;T--)
#define mulT1 ll T, rnds; for(scanf("%lld", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const ll N = 1e5+5, K = N << 1;

ll n, m, c[K], d[K], a[K];
map<ll, bool> mp;

int main() {
	mulT0 {
		mp.clear();
		scanf("%lld", &n); m = n << 1;
		ll Xor = 0, _ = 0, id = 0;
		rep(i, 1, m) scanf("%lld", &c[i]);
		rep(i, 1, m) {
			if(c[i] & 1) {puts("NO"); _ = 1; break;}
			Xor ^= c[i];
		}
		if(_) continue;
		if(Xor) {puts("NO"); continue;}
		sort(c+1, c+1+m);
		rep(i, 1, n) d[i] = c[i*2];
		if(d[n] % m) {puts("NO"); continue;}
		a[n] = d[n] / m;
		per(i, n-1, 1) {
			ll qwq = 2 * i;
//			printf("%lld %lld %lld\n", d[i+1], d[i], qwq);
			if((d[i+1] - d[i]) % qwq) {puts("NO"); _ = 1; break;}
			a[i] = a[i+1] - (d[i+1] - d[i]) / qwq;
		}
		if(!_) {
			rep(i, 1, n) {
				if(mp[a[i]] || a[i] <= 0) {puts("NO"); _ = 1; break;}
				mp[a[i]] = 1;
			}
			if(!_) puts("YES");
//			puts("YES");
//			per(i, n, 1) printf("%lld ", -a[i]);
//			rep(i, 1, n) printf("%lld%c", a[i], " \n"[i==n]);
		}
	}
	return 0;
}