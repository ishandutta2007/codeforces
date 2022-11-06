// Problem: The Enchanted Forest
// Contest: Codeforces
// URL: https://m2.codeforces.com/contest/1687/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll T, n, k, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &n, &k);
		rep(i, 1, n) scanf("%lld", &a[i]);
		if(k < n) {
			ll sum = 0, ans = 0;
			rep(i, 1, k) sum += a[i];
			ans = sum;
			rep(i, k+1, n) {
				sum += a[i] - a[i-k];
				chkmax(ans, sum);
			}
			ans += (k - 1) * k / 2;
			printf("%lld\n", ans);
		}
		else {
			ll ans = accumulate(a+1, a+1+n, 0LL);
			ans += ((k - 1) + (k - n)) * n / 2;
			printf("%lld\n", ans);
		}
	}
	return 0;
}