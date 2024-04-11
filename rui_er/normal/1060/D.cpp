//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 ll T; for(scanf("%d", &T);T;T--)
#define mulT1 ll T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

ll n, l[N], r[N], ans;

int main() {
	scanf("%lld", &n); ans = n;
	rep(i, 1, n) scanf("%lld%lld", &l[i], &r[i]);
	sort(l+1, l+1+n); sort(r+1, r+1+n);
	rep(i, 1, n) ans += max(l[i], r[i]);
	printf("%lld\n", ans);
	return 0;
}