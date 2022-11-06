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
const ll N = 105;

ll n, k, p[N], s[N], ans;

int main() {
	mulT0 {
		fil(s, 0); ans = 0;
		scanf("%lld%lld", &n, &k);
		rep(i, 1, n) scanf("%lld", &p[i]), s[i] = s[i-1] + p[i];
		per(i, n, 2) if(100 * p[i] > k * (s[i-1] + ans)) ans = max(ans, (p[i]*100-s[i-1]*k+k-1)/k);
		printf("%lld\n", ans);
	}
	return 0;
}