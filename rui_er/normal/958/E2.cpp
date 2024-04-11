//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 5e5+5;

ll n, k, t[N], diff[N], dp[N], cnt[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void solve() {
	rep(i, 2, n) {
		if(dp[i-1] < dp[i-2] + diff[i]) {
			dp[i] = dp[i-1];
			cnt[i] = cnt[i-1];
		}
		else if(dp[i-1] == dp[i-2] + diff[i]) {
			dp[i] = dp[i-1];
			cnt[i] = max(cnt[i-1], cnt[i-2]+1);
		}
		else {
			dp[i] = dp[i-2] + diff[i];
			cnt[i] = cnt[i-2] + 1;
		}
	}
}

int main() {
	scanf("%lld%lld", &k, &n);
	rep(i, 1, n) scanf("%lld", &t[i]);
	sort(t+1, t+1+n);
	rep(i, 2, n) diff[i] = t[i] - t[i-1];
	ll L = -1e9, R = 1e9 + 1, ans = 0;
	while(L < R) {
		ll M = (L + R) >> 1;
		rep(i, 2, n) diff[i] += M;
		solve();
		if(cnt[n] >= k) ans = M, L = M + 1;
		else R = M;
		rep(i, 2, n) diff[i] -= M;
	}
	rep(i, 2, n) diff[i] += ans;
	solve();
	printf("%lld\n", dp[n]-ans*k);
	rep(i, 2, n) diff[i] -= ans;
	return 0;
}