// Problem: C. Virus
// Contest: Codeforces - CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/C
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
const ll N = 1e5+5;

ll T, n, m, a[N], seg[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &n, &m);
		rep(i, 1, m) scanf("%lld", &a[i]);
		sort(a+1, a+1+m);
		rep(i, 1, m-1) seg[i] = a[i+1] - a[i] - 1;
		seg[m] = (a[1] + n) - a[m] - 1;
		sort(seg+1, seg+1+m, greater<ll>());
		ll ans = n;
		rep(i, 1, m) {
			seg[i] -= 4 * (i - 1);
			if(seg[i] <= 0) break;
			ans -= max(seg[i]-1, 1LL);
		}
		printf("%lld\n", ans);
	}
	return 0;
}