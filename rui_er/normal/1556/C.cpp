//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 1e3+5, inf = 0x3f3f3f3f3f3f3f3fll;

ll n, a[N], s[N], ans;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld", &n);
	n &= n ^ 1;
	rep(i, 1, n) {
		scanf("%lld", &a[i]);
		s[i] = s[i-1] + ((i & 1) ? a[i] : -a[i]);
	}
	for(ll L=1;L<n;L+=2) {
		ll mn = inf, now = 0, tmp = 1;
		rep(R, L+1, n) {
			if(R & 1) now += a[R];
			else {
				ll brk = min(a[L], a[R]-(s[R-1]-s[L]));
				if(a[L] < tmp) break; // too many `)'
				if(brk >= tmp) ans += brk - tmp + 1;
				now -= a[R];
			}
			chkmin(mn, now);
			chkmax(tmp, -mn);
		}
	}
	printf("%lld\n", ans);
	return 0;
}