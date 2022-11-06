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

ll n, k, b[N], s[N];

int main() {
	mulT0 {
		scanf("%lld", &n); k = n + 2;
		rep(i, 1, k) scanf("%lld", &b[i]);
		sort(b+1, b+1+k);
		rep(i, 1, k) s[i] = s[i-1] + b[i];
		if(b[n+1] == s[n]) rep(i, 1, n) printf("%lld ", b[i]);
		else {
			int ok = 0;
			rep(i, 1, n+1) if(b[n+2] == s[n+1] - b[i]) {ok = i; break;}
			if(ok) {rep(i, 1, n+1) if(i != ok) printf("%lld ", b[i]);}
			else printf("-1");
		}
		puts("");
	}
	return 0;
}