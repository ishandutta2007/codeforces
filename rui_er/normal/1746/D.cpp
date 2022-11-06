// LUOGU_RID: 90659852
// Problem: D. Paths on the Tree
// Contest: Codeforces - Codeforces Global Round 23
// URL: https://codeforces.com/contest/1746/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
const ll N = 2e5+5;

ll T, n, k, fa[N], a[N], deg[N], dp1[N], dp2[N];
vector<ll> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs(ll u, ll rem) {
	dp1[u] = rem * a[u];
	dp2[u] = (rem + 1) * a[u];
	if(deg[u]) {
		vector<ll> diff;
		for(ll v : e[u]) {
			dfs(v, rem/deg[u]);
			dp1[u] += dp1[v];
			dp2[u] += dp1[v];
			diff.push_back(dp2[v]-dp1[v]);
		}
		sort(diff.begin(), diff.end(), greater<ll>());
		rep(i, 0, rem%deg[u]) {
			if(i < rem % deg[u]) dp1[u] += diff[i];
			dp2[u] += diff[i];
		}
	}
}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &n, &k);
		rep(i, 2, n) {
			scanf("%lld", &fa[i]);
			e[fa[i]].push_back(i);
			++deg[fa[i]];
		}
		rep(i, 1, n) scanf("%lld", &a[i]);
		dfs(1, k);
		printf("%lld\n", dp1[1]);
		rep(i, 1, n) {
			fa[i] = a[i] = deg[i] = dp1[i] = dp2[i] = 0;
			e[i].clear();
		}
	}
	return 0;
}