//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5, K = N * 32, inf = 0x3f3f3f3f3f3f3f3fll;

ll n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Trie {
	ll son[K][2], L[K], R[K], rt, sz;
	Trie() : rt(1), sz(1) {
		memset(son, 0, sizeof(son));
		memset(L, 0x3f, sizeof(L));
		memset(R, 0, sizeof(R));
	}
	void insert(ll val, ll id) {
		ll u = rt;
		chkmin(L[u], id);
		chkmax(R[u], id);
		per(i, 30, 0) {
			ll c = (val >> i) & 1;
			if(!son[u][c]) son[u][c] = ++sz;
			chkmin(L[son[u][c]], id);
			chkmax(R[son[u][c]], id);
			u = son[u][c];
		}
	}
	ll query(ll u, ll val, ll dep) {
		if(dep < 0) return 0;
		ll ans = 0;
		per(i, dep, 0) {
			ll c = (val >> i) & 1;
			if(son[u][c]) u = son[u][c];
			else u = son[u][c^1], ans |= 1LL << i;
		}
		return ans;
	}
	ll dfs(ll u, ll dep) {
		if(!u || dep < 0) return 0;
		if(son[u][0] && son[u][1]) {
			ll ans = inf, l = 0, r = 0, x = 0;
			if(R[son[u][0]] - L[son[u][0]] > R[son[u][1]] - L[son[u][1]]) {
				l = L[son[u][1]];
				r = R[son[u][1]];
				x = son[u][0];
			}
			else {
				l = L[son[u][0]];
				r = R[son[u][0]];
				x = son[u][1];
			}
			rep(i, l, r) chkmin(ans, query(x, a[i], dep-1));
			return dfs(son[u][0], dep-1) + dfs(son[u][1], dep-1) + ans + (1LL << dep);
		}
		return dfs(son[u][0]|son[u][1], dep-1);
	}
}trie;

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	sort(a+1, a+1+n);
	rep(i, 1, n) trie.insert(a[i], i);
	printf("%lld\n", trie.dfs(1, 30));
    return 0;
}