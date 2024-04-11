//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

ll T, L, R, a[19], tot, dp[19][4];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll dfs(ll u, ll now, bool zero, bool lim) {
	if(now > 3) return 0;
	if(!u) return 1;
	if(!zero && !lim && dp[u][now] > -1) return dp[u][now];
	ll lst = lim ? a[u] : 9, ans = 0;
	rep(i, 0, lst) ans += dfs(u-1, now+!!i, zero && !i, lim && i == a[u]);
	if(!zero && !lim) dp[u][now] = ans;
	return ans;
}
ll calc(ll x) {
	for(tot=0;x;x/=10) a[++tot] = x % 10;
	return dfs(tot, 0, 1, 1);
}

int main() {
	memset(dp, -1, sizeof(dp));
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &L, &R);
		printf("%lld\n", calc(R)-calc(L-1));
	}
	return 0;
}