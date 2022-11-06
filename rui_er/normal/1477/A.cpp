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
const ll N = 2e5+5;

ll n, k, a[N];

int main() {
	mulT0 {
		scanf("%lld%lld", &n, &k);
		rep(i, 1, n) scanf("%lld", &a[i]);
		rep(i, 2, n) a[i] -= a[1]; k -= a[1];
		ll g = 0;
		rep(i, 2, n) g = __gcd(g, abs(a[i]));
		puts((const char*[]){"NO", "YES"}[!(k%g)]);
	}
	return 0;
}