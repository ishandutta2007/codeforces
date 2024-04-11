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

ll p, a, b, c;

int main() {
	mulT0 {
		scanf("%lld%lld%lld%lld", &p, &a, &b, &c);
		ll x = p / a * a + (p % a ? a : 0);
		ll y = p / b * b + (p % b ? b : 0);
		ll z = p / c * c + (p % c ? c : 0);
		ll ans = min(x, min(y, z)) - p;
		printf("%lld\n", ans);
	}
	return 0;
}