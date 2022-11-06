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

ll n, m, a[N], b[N], g;

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, m) scanf("%lld", &b[i]);
	rep(i, 2, n) a[i] = abs(a[i]-a[1]), g = __gcd(g, a[i]);
	rep(i, 1, m) printf("%lld%c", __gcd(g, a[1]+b[i]), " \n"[i==m]);
	return 0;
}