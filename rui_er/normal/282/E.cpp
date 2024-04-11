//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1e5+5, K = N * 41;

ll n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Trie {
	ll son[K][2], tag[K], sz;
	Trie() : sz(1) {
		memset(son, 0, sizeof(son));
		memset(tag, 0, sizeof(tag));
	}
	~Trie() {}
	void insert(ll val) {
		ll u = 1;
		per(i, 40, 0) {
			ll c = (val >> i) & 1;
			if(!son[u][c]) son[u][c] = ++sz;
			u = son[u][c];
		}
		++tag[u];
	}
	ll query(ll val) {
		ll u = 1, ans = 0;
		per(i, 40, 0) {
			ll c = (val >> i) & 1;
			if(son[u][c^1]) ans |= (1LL << i), u = son[u][c^1];
			else u = son[u][c];
		}
		return ans;
	}
}trie;

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	ll now = 0, ans = 0;
	trie.insert(0);
	rep(i, 1, n) trie.insert(now^=a[i]);
	now = 0;
	per(i, n, 1) chkmax(ans, trie.query(now^=a[i]));
	printf("%lld\n", ans);
	return 0;
}