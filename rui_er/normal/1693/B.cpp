// Problem: CF1693B Fake Plastic Trees
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1693B
// Memory Limit: 250 MB
// Time Limit: 1000 ms
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
const ll N = 2e5+5;

ll T, n, fa[N], L[N], R[N], ans;
vector<ll> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll dfs(ll u) {
	ll sum = 0;
	for(ll v : e[u]) sum += dfs(v);
	if(sum < L[u]) {++ans; return R[u];}
	return min(sum, R[u]);
}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld", &n);
		rep(i, 2, n) {
			scanf("%lld", &fa[i]);
			e[fa[i]].push_back(i);
		}
		rep(i, 1, n) scanf("%lld%lld", &L[i], &R[i]);
		dfs(1);
		printf("%lld\n", ans);
		ans = 0;
		rep(i, 1, n) e[i].clear();
	}
	return 0;
}