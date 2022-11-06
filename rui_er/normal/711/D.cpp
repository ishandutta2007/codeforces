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
const ll N = 2e5+5, M = 1e6+5, mod = 1e9+7;

ll n, dfn[N], low[N], vis[N], now, pos[N], sz[N], tot, k, tmp = 1, ans;
stack<ll> s;
struct Edge {
	ll v, nxt;
	Edge(ll a=0, ll b=0) : v(a), nxt(b) {}
	~Edge() {}
}e[M];
ll ne = 1, h[N];
void add(ll u, ll v) {
	e[++ne] = Edge(v, h[u]);
	h[u] = ne;
}
void tarjan(ll u, ll from) {
	low[u] = dfn[u] = ++now;
	vis[u] = 1;
	s.push(u);
	for(ll i=h[u];i;i=e[i].nxt) {
		if((i ^ 1) == from) continue;
		ll v = e[i].v;
		if(!dfn[v]) {
			tarjan(v, i);
			low[u] = min(low[u], low[v]);
		}
		else if(vis[v]) low[u] = min(low[u], dfn[v]);
	}
	if(dfn[u] == low[u]) {
		++tot;
		loop {
			ll v = s.top();
			pos[v] = tot;
			++sz[tot];
			vis[v] = 0;
			s.pop();
			if(u == v) break;
		}
	}
}
ll qpow(ll x, ll y) {
	ll res = 1;
	for(;y;y>>=1,x=x*x%mod) if(y & 1) res = res * x % mod;
	return res;
}

// ans=2^(n-sum(k))*mul(2^k-2)
int main() {
	scanf("%lld", &n);
	rep(i, 1, n) {
		ll x;
		scanf("%lld", &x);
		add(i, x); add(x, i);
	}
	rep(u, 1, n) if(!dfn[u]) tarjan(u, 0);
	k = n;
	rep(i, 1, tot) if(sz[i] > 1) {
		tmp = tmp * (qpow(2, sz[i]) - 2) % mod;
		k -= sz[i];
	}
	ans = qpow(2, k) * tmp % mod;
	printf("%lld\n", ans);
    return 0;
}