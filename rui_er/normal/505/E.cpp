//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1e5+5, inf = 0x3f3f3f3f3f3f3f3fll; 

ll n, m, k, p, h[N], a[N], now[N];
priority_queue<tuple<ll, ll> > q;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool check(ll M) {
	fill(now+1, now+1+n, M);
	while(!q.empty()) q.pop();
	rep(i, 1, n) if(now[i] - m * a[i] < h[i]) q.push(make_tuple(-(now[i]/a[i]), i));
	rep(i, 1, m) rep(j, 1, k) {
		if(q.empty()) return 1;
		auto qwq = q.top(); q.pop();
		ll tms = -get<0>(qwq), id = get<1>(qwq);
		if(tms < i) return 0;
		now[id] += p;
		tms = now[id] / a[id];
		if(now[id] - m * a[id] < h[id]) q.push(make_tuple(-tms, id));
	}
	return q.empty();
}

int main() {
	scanf("%lld%lld%lld%lld", &n, &m, &k, &p);
	rep(i, 1, n) scanf("%lld%lld", &h[i], &a[i]);
	ll L = 0, R = inf, ans = inf;
	while(R - L >= 5) {
		ll M = (L + R) >> 1;
		if(check(M)) {
			chkmin(ans, M);
			R = M - 1;
		}
		else L = M + 1;
	}
	rep(i, L, R) if(check(i)) chkmin(ans, i);
	printf("%lld\n", ans);
    return 0;
}