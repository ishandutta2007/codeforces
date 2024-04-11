//LG rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;

ll T, n, a, b;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld%lld", &n, &a, &b);
		if(a == 1) {
			if(b == 1 || n % b == 1) puts("Yes");
			else puts("No");
		}
		else {
			ll ok = 0;
			for(ll i=1;i<=n;i*=a) {
				if(!((n - i) % b)) {
					ok = 1;
					break;
				}
			}
			puts(ok?"Yes":"No");
		}
	}
	return 0;
}