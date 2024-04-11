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
		scanf("%lld%lld", &n, &k); --k;
		if(!(n & 1)) printf("%lld\n", k%n+1);
		else {
			ll cycle = (n - 1) * (n / 2) + (n - 1) / 2, piece = n - 1;
			k %= cycle;
			ll id = k / piece + 1; k %= piece;
			if(k < piece / 2) printf("%lld\n", (id+k+n-1)%n+1);
			else printf("%lld\n", (id+k)%n+1);
		}
	}
	return 0;
}