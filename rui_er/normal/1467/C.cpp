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
const ll N = 3e5+5;

ll n[4], a[N][4], mi[4], s[4];

int main() {
	scanf("%lld%lld%lld", &n[1], &n[2], &n[3]);
	rep(i, 1, 3) {
		rep(j, 1, n[i]) {
			scanf("%lld", &a[j][i]);
			mi[i] = j == 1 ? a[j][i] : min(mi[i], a[j][i]);
			s[i] += a[j][i];
		}
	}
	ll qwq = min(mi[1]+mi[2], min(mi[2]+mi[3], mi[1]+mi[3])), qaq = min(s[1], min(s[2], s[3]));
	printf("%lld\n", s[1]+s[2]+s[3]-2*min(qwq, qaq));
	return 0;
}