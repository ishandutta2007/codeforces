//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 2e5+5, inf = 0x3f3f3f3f3f3f3f3fll;

ll n, a[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld", &n);
	rep(i, 1, 2*n) scanf("%lld", &a[i]);
	sort(a+1, a+1+2*n);
	ll L = 1, R = n, ans = inf;
	while(R <= 2 * n) {
		ll now = 0;
		if(L == 1) now = (a[R] - a[L]) * (a[2*n] - a[R+1]);
		else if(R == 2 * n) now = (a[R] - a[L]) * (a[L-1] - a[1]);
		else now = (a[2*n] - a[1]) * (a[R] - a[L]);
		chkmin(ans, now);
		++L; ++R;
	}
	printf("%lld\n", ans);
	return 0;
}