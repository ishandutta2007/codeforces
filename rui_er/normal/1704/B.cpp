// Problem: B. Luke is a foodie
// Contest: Codeforces - CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5, inf = 0x3f3f3f3f3f3f3f3fll;

ll T, n, x, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &n, &x);
		rep(i, 1, n) scanf("%lld", &a[i]);
		ll mn = inf, mx = -inf, ans = 0;
		rep(i, 1, n) {
			if(mn == inf && mx == -inf) mn = mx = a[i];
			else if(a[i] < mn) {
				if(mx - a[i] > 2 * x) {++ans; mn = mx = a[i];}
				else mn = a[i];
			}
			else if(a[i] > mx) {
				if(a[i] - mn > 2 * x) {++ans; mn = mx = a[i];}
				else mx = a[i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}