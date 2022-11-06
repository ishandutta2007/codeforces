// Problem: CF1700C Helping the Nature
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1700C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll T, n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld", &n);
		rep(i, 1, n) scanf("%lld", &a[i]);
		a[n+1] = -a[n];
		per(i, n, 2) a[i] -= a[i-1];
		ll ans = 0;
		rep(i, 2, n) {
			if(a[i] > 0) {
				a[n+1] -= a[i];
				ans += a[i];
				a[i] = 0;
			}
			else if(a[i] < 0) {
				a[1] += a[i];
				ans -= a[i];
				a[i] = 0;
			}
		}
		ans += abs(a[1]);
		printf("%lld\n", ans);
	}
	return 0;
}