// Problem: CF846E Chemistry in Berland
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF846E
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
const ll N = 1e5+5, inf = 0x3f3f3f3f3f3f3f3fll;

ll n, a[N], b[N];
long double dp[N];
vector<tuple<ll, ll> > son[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs(ll u) {
	dp[u] = b[u] - a[u];
	for(auto i : son[u]) {
		ll v = get<0>(i), k = get<1>(i);
		dfs(v);
		if(dp[v] >= 0.0) dp[u] += dp[v];
		else dp[u] += k * dp[v];
	}
}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &b[i]);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 2, n) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		son[x].emplace_back(i, y);
	}
	dfs(1);
	puts(dp[1]>=0.0?"YES":"NO");
	return 0;
}