//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 1e5+5, inf = 0x3f3f3f3f3f3f3f3fll;

ll n, a[N], pos[N], tot, cnt[N], dis[N], ans = inf;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
ll calc(ll d) { // calculating d|S
	ll now = 0;
	for(ll i=d;i<=tot;i+=d) {
		ll fst = pos[i-d+1], lst = pos[i], mid = pos[i-d/2];
		ll cost = (2 * cnt[mid] - cnt[fst-1] - cnt[lst]) * mid + (dis[fst-1] + dis[lst] - 2 * dis[mid]);
		now += cost;
	}
	return now;
}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) {
		scanf("%lld", &a[i]);
		if(a[i]) {
			pos[++tot] = i;
			cnt[i] = 1;
			dis[i] = i;
		}
	}
	rep(i, 1, n) {
		cnt[i] += cnt[i-1];
		dis[i] += dis[i-1];
	}
	rep(i, 2, tot) if(!(tot % i)) chkmin(ans, calc(i)); // get every divisor
	printf("%lld\n", ans==inf?-1:ans);
	return 0;
}