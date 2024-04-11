//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1e5+5; 

ll n, m, p, vis[N], sz[N], tot;
vector<ll> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs(ll u) {
	++sz[tot];
	vis[u] = 1;
	for(auto v : e[u]) {
		if(!vis[v]) dfs(v);
	}
}
ll qpow(ll x, ll y) {
	ll ans = 1;
	for(;y;y>>=1,x=x*x%p) if(y & 1) ans = ans * x % p;
	return ans;
}

int main() {
	scanf("%lld%lld%lld", &n, &m, &p);
	if(p == 1) return puts("0")&0;
	rep(i, 1, m) {
		ll u, v;
		scanf("%lld%lld", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	rep(i, 1, n) {
		if(!vis[i]) {
			++tot;
			dfs(i);
		}
	}
	if(tot == 1) return puts("1")&0;
	ll ans = qpow(n, tot-2);
	rep(i, 1, tot) ans = ans * sz[i] % p;
	printf("%lld\n", ans);
	return 0;
}