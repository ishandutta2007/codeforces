/*
                     _ooOoo_
                    o8888888o
                    88" . "88
                    (| -_- |)
                    O\  =  /O
                 ____/`---'\____
               .'  \\|     |//  `.
              /  \\|||  :  |||//  \
             /  _||||| -:- |||||-  \
             |   | \\\  -  /// |   |
             | \_|  ''\---/''  |   |
             \  .-\__  `-`  ___/-. /
           ___`. .'  /--.--\  `. . __
        ."" '<  `.___\_<|>_/___.'  >'"".
       | | :  `- \`.;`\ _ /`;.`/ - ` : | |
       \  \ `-.   \_ __\ /__ _/   .-` /  /
  ======`-.____`-.___\_____/___.-`____.-'======
                     `=---='
  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                    BUG
*/
//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 ll T; for(scanf("%lld", &T);T;T--)
#define mulT1 ll T, rnds; for(scanf("%lld", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const ll N = 2e5+5, K = 1e3+5, W = 2e5, P = 1e7+5, mod = 1e9+7, inf = 0x3f3f3f3f3f3f3f3f;

ll n, q, a[N], rt[N], tot, ans;
ll tab[N], prime[N], primecnt = 0;
ll qpow(ll x, ll y) {
	ll res = 1;
	for(;y;y>>=1,x=x*x%mod) if(y & 1) res = res * x % mod;
	return res;
}
struct Node {
	ll w, lc, rc;
	Node(ll a=0, ll b=0, ll c=0) : w(a), lc(b), rc(c) {}
	~Node() {}
}t[P];
void pushup(ll u) {t[u].w = min(t[t[u].lc].w, t[t[u].rc].w);}
void insert(ll &u, ll l, ll r, ll pos, ll delta) {
	if(!u) u = ++tot;
	if(l == r) {t[u].w += delta; return;}
	ll mid = (l + r) >> 1;
	if(pos <= mid) insert(t[u].lc, l, mid, pos, delta);
	else insert(t[u].rc, mid+1, r, pos, delta);
	pushup(u);
}

void sieve() {
	rep(i, 2, W) tab[i] = 1;
	rep(i, 2, W) {
		if(tab[i]) prime[++primecnt] = i;
		for(ll j=1;j<=primecnt&&prime[j]*i<=n;j++) {
			tab[prime[j]*i] = 0;
			if(!(i % prime[j])) break;
		}
	}
}

int main() {
	sieve();
	scanf("%lld%lld", &n, &q);
	rep(i, 1, n) {
		scanf("%lld", &a[i]);
		rep(j, 1, primecnt) {
			if(prime[j] * prime[j] > a[i]) break;
			ll cnt = 0;
			while(a[i] % prime[j] == 0) ++cnt, a[i] /= prime[j];
			if(cnt) insert(rt[j], 1, n, i, cnt);
			if(a[i] == 1) break;
		}
		if(a[i] != 1) {
			ll pr = lower_bound(prime+1, prime+1+primecnt, a[i]) - prime;
			insert(rt[pr], 1, n, i, 1);
		}
	}
	ans = 1; 
	rep(i, 1, primecnt) ans *= qpow(prime[i], t[rt[i]].w);
	while(q--) {
		ll pos, w;
		scanf("%lld%lld", &pos, &w);
		rep(i, 1, primecnt) {
			if(prime[i] * prime[i] > w) break;
			ll cnt = 0;
			while(w % prime[i] == 0) ++cnt, w /= prime[i];
			if(cnt) {
				ll lst = t[rt[i]].w;
				insert(rt[i], 1, n, pos, cnt);
				ans = ans * qpow(prime[i], t[rt[i]].w-lst) % mod;
			}
			if(w == 1) break;
		}
		if(w != 1) {
			ll pr = lower_bound(prime+1, prime+1+primecnt, w) - prime;
			ll lst = t[rt[pr]].w;
			insert(rt[pr], 1, n, pos, 1);
			ans = ans * qpow(w, t[rt[pr]].w-lst) % mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}