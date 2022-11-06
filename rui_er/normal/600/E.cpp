//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1e5+5; 

ll n, c[N], sz[N], son[N], buc[N], ans[N], now, sum;
vector<ll> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs(ll u, ll f) {
	sz[u] = 1;
	for(auto v : e[u]) {
		if(v == f) continue;
		dfs(v, u);
		sz[u] += sz[v];
		if(sz[v] > sz[son[u]]) son[u] = v;
	}
}
void add(ll u, ll f, ll dt) {
	buc[c[u]] += dt;
	if(buc[c[u]] > now) {
		now = buc[c[u]];
		sum = c[u];
	}
	else if(buc[c[u]] == now) sum += c[u];
	for(auto v : e[u]) {
		if(v == f) continue;
		add(v, u, dt);
	}
}
void calc(ll u, ll f, ll sv) {
	for(auto v : e[u]) {
		if(v == f || v == son[u]) continue;
		calc(v, u, 0);
	}
	if(son[u]) calc(son[u], u, 1);
	++buc[c[u]];
	if(buc[c[u]] > now) {
		now = buc[c[u]];
		sum = c[u];
	}
	else if(buc[c[u]] == now) sum += c[u];
	for(auto v : e[u]) {
		if(v == f || v == son[u]) continue;
		add(v, u, 1);
	}
	ans[u] = sum;
	if(!sv) {
		add(u, f, -1);
		now = sum = 0;
	}
}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &c[i]);
	rep(i, 1, n-1) {
		ll u, v;
		scanf("%lld%lld", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	calc(1, 0, 0);
	rep(i, 1, n) printf("%lld%c", ans[i], " \n"[i==n]);
	return 0;
}