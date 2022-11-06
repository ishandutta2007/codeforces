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
const ll N = 1e4+5, K = 1e4;

ll n, a[N];

int main() {
	rep(i, 1, K) a[i] = i * i * i;
	mulT0 {
		scanf("%lld", &n);
		ll mx = lower_bound(a+1, a+1+K, n) - a, _ = 0;
		rep(i, 1, mx) {
			ll p = lower_bound(a+1, a+1+K, n-a[i]) - a;
			if(n == a[i] + a[p]) {
				_ = 1;
				puts("YES");
				break;
			}
		}
		if(!_) puts("NO");
	}
	return 0;
}