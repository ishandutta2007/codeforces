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

ll n, a[N], s[N];

int main() {
	mulT0 {
		scanf("%lld", &n);
		rep(i, 1, n) scanf("%lld", &a[i]);
		rep(i, 1, n) s[i] = s[i-1] + a[i];
		ll k = 0, _ = 1;
		rep(i, 1, n) {
			k += i - 1;
			if(s[i] < k) {
				puts("NO");
				_ = 0;
				break;
			}
		}
		if(_) puts("YES");
	} 
	return 0;
}