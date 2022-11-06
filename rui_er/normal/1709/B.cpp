// Problem: B. Also Try Minecraft
// Contest: Codeforces - Educational Codeforces Round 132 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1709/problem/B
// Memory Limit: 256 MB
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
const ll N = 1e5+5;

ll n, m, a[N], pre[N], suf[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 2, n) pre[i] = pre[i-1] + max(a[i-1]-a[i], 0LL);
	per(i, n-1, 1) suf[i] = suf[i+1] + max(a[i+1]-a[i], 0LL);
	// rep(i, 1, n) printf("%lld%c", pre[i], " \n"[i==n]);
	// rep(i, 1, n) printf("%lld%c", suf[i], " \n"[i==n]);
	while(m--) {
		ll s, t;
		scanf("%lld%lld", &s, &t);
		if(s == t) puts("0");
		else if(s < t) printf("%lld\n", pre[t] - pre[s]);
		else printf("%lld\n", suf[t] - suf[s]);
	}
	return 0;
}