// LUOGU_RID: 96198805
// Problem: CF630K Indivisibility
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF630K
// Memory Limit: 62 MB
// Time Limit: 500 ms
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

ll n;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll lcm(ll x, ll y) {
	if(!x || !y) return x | y;
	return x / __gcd(x, y) * y;
}

int main() {
	scanf("%lld", &n);
	ll ans = n;
	rep(S, 1, (1LL << 9) - 1) {
		ll now = 0, mul = __builtin_popcountll(S) & 1 ? -1 : 1;
		rep(i, 0, 8) if((S >> i) & 1) now = lcm(now, i+2);
		ans += mul * (n / now);
	}
	printf("%lld\n", ans);
	return 0;
}