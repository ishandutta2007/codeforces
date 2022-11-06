//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;

ll n, k;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld%lld", &n, &k);
	ll ans = 1;
	if(k > 1) ans += n * (n - 1) / 2;
	if(k > 2) ans += (n * (n - 1) / 2 * (n - 2) / 3) * 2;
	if(k > 3) ans += (n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4) * 9;
	printf("%lld\n", ans);
	return 0;
}