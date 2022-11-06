//PP-Automation
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll T, n, a[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
bool check1(ll i) {
	if(i > n - 3) return 0;
	if(a[i] < a[i+1] && a[i] > a[i+2] && a[i+1] > a[i+3] && a[i+2] < a[i+3]) return 1;
	if(a[i] > a[i+1] && a[i] < a[i+2] && a[i+1] < a[i+3] && a[i+2] > a[i+3]) return 1;
	return 0;
}
bool check2(ll i) {
	if(i > n - 2) return 0;
	if(a[i] <= a[i+1] && a[i+1] <= a[i+2]) return 0;
	if(a[i] >= a[i+1] && a[i+1] >= a[i+2]) return 0;
	return 1;
}
bool check3(ll i) {return i <= n - 1;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld", &n);
		rep(i, 1, n) scanf("%lld", &a[i]);
		if(n == 1) {puts("1"); continue;}
		if(n == 2) {puts("3"); continue;}
		ll ans = 0;
		rep(i, 1, n) ans += check1(i) + check2(i) + check3(i) + 1;
		printf("%lld\n", ans);
	}
	return 0;
}