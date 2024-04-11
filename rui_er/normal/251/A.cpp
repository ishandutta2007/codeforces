//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

ll n, d, a[N], ans;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld%lld", &n, &d);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, n) {
		ll j = upper_bound(a+1, a+1+n, a[i]+d) - a - 1;
		ll qwq = j - i;
		ans += qwq * (qwq - 1) / 2;
	}
	printf("%lld\n", ans);
	return 0;
}