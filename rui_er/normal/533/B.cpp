//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5, inf = 0x3f3f3f3f3f3f3f3fll;

ll n, fa[N], a[N], dp[N][2];
vector<ll> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs(ll u) {
	dp[u][0] = 0;
	dp[u][1] = -inf;
	for(int v : e[u]) {
		dfs(v);
		ll x = dp[u][0], y = dp[u][1];
		chkmax(dp[u][0], x + dp[v][0]);
		chkmax(dp[u][0], y + dp[v][1]);
		chkmax(dp[u][1], x + dp[v][1]);
		chkmax(dp[u][1], y + dp[v][0]);
	}
	chkmax(dp[u][1], dp[u][0] + a[u]);
}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) {
		scanf("%lld%lld", &fa[i], &a[i]);
		if(i == 1) fa[i] = 0;
		else e[fa[i]].push_back(i);
	}
	dfs(1);
	printf("%lld\n", max(dp[1][0], dp[1][1]));
	return 0;
}