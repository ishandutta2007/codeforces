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

ll n, k;

int main() {
	mulT0 {
		scanf("%lld%lld", &n, &k);
		if(n <= k) printf("%lld\n", ll(ceil(1.0*k/n)));
		else {
			ll x = ceil(1.0 * n / k);
			k *= x;
			printf("%lld\n", ll(ceil(1.0*k/n)));
		}
	}
	return 0;
}