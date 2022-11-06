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
const ll N = 2e5+5, M = 1e6+5, inf = 0x3f3f3f3f3f3f3f3f, mod = 1e9+7;

ll n, m, a[N], dfn[N], low[N], vis[N], mi[N], cnt[N], now, pos[N], sz[N], indeg[N], tot, ans1, ans2 = 1LL;
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
void tarjan(ll u) {
	low[u] = dfn[u] = ++now;
	vis[u] = 1;
	s.push(u);
	for(ll i=h[u];i;i=e[i].nxt) {
		ll v = e[i].v;
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(vis[v]) low[u] = min(low[u], dfn[v]);
	}
	if(dfn[u] == low[u]) {
		++tot;
		mi[tot] = inf;
		loop {
			ll v = s.top();
			pos[v] = tot;
			++sz[tot];
			vis[v] = 0;
			s.pop();
			if(mi[tot] > a[v]) mi[tot] = a[v], cnt[tot] = 1;
			else if(mi[tot] == a[v]) ++cnt[tot];
			if(u == v) break;
		}
	}
}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	scanf("%lld", &m);
	rep(i, 1, m) {
		ll u, v;
		scanf("%lld%lld", &u, &v);
		add(u, v);
	}
	rep(u, 1, n) if(!dfn[u]) tarjan(u);
	rep(i, 1, tot) {
		ans1 += mi[i];
		ans2 = ans2 * cnt[i] % mod;
	}
	printf("%lld %lld\n", ans1, ans2);
    return 0;
}