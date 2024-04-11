// Problem: CF1681D Required Length
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1681D
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3fll;

ll n, x, ans = inf;
map<ll, ll> dis;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs(ll u, ll now) {
	dis[u] = now;
	vector<ll> bit;
	ll cnt = 0;
	for(ll i=u;i;i/=10,++cnt) bit.push_back(i%10);
	if(cnt >= n) {
		if(cnt == n) chkmin(ans, dis[u]);
		return;
	}
	for(ll i : bit) {
		if(!i) continue;
		ll v = u * i;
		if(dis.find(v) == dis.end() || dis[v] > dis[u] + 1) dfs(v, now+1);
	}
}

int main() {
	scanf("%lld%lld", &n, &x);
	dfs(x, 0);
	printf("%lld\n", ans==inf?-1LL:ans);
	return 0;
}