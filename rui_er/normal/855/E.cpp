//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

ll T, B, L, R, a[65], tot, dp[11][65][1024];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll dfs(ll u, ll sta, bool zero, bool lim) {
	if(!u) return !sta;
	if(!zero && !lim && dp[B][u][sta] > -1) return dp[B][u][sta];
	ll lst = lim ? a[u] : (B - 1), ans = 0;
	rep(i, 0, lst) {
		if(zero && !i) ans += dfs(u-1, sta, 1, 0);
		else ans += dfs(u-1, sta^(1LL<<i), 0, lim && i == a[u]);
	}
	if(!zero && !lim) dp[B][u][sta] = ans;
	return ans;
}
ll calc(ll x) {
	for(tot=0;x;x/=B) a[++tot] = x % B;
	return dfs(tot, 0, 1, 1);
}

int main() {
	memset(dp, -1, sizeof(dp));
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld%lld", &B, &L, &R);
		printf("%lld\n", calc(R)-calc(L-1));
	}
	return 0;
}