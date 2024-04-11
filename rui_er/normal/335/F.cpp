//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 5e5+5;

ll n, a[N], ans, cost[N], cnt[N], pre[N], tot;
priority_queue<ll, vector<ll>, greater<ll> > q;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) {
		scanf("%lld", &a[i]);
		ans += a[i];
	}
	sort(a+1, a+1+n, greater<ll>());
	rep(i, 1, n) {
		if(i == 1 || a[i] != a[i-1]) cost[++tot] = a[i];
		++cnt[tot];
		pre[tot] = pre[tot-1] + cnt[tot];
	}
	rep(i, 1, tot) {
		vector<ll> tmp;
		ll sz = q.size();
		ll freeNum = min(cnt[i], pre[i-1]-2*sz);
		rep(j, 1, freeNum) tmp.push_back(cost[i]);
		ll other = min(cnt[i], pre[i-1]) - freeNum;
//		printf("%lld %lld\n", freeNum, other);
		for(ll j=1;j<=other&&!q.empty();j+=2) {
			ll u = q.top(); q.pop();
//			printf("%lld (COST = %lld)\n", u, cost[i]);
			if(u < cost[i]) {
				tmp.push_back(cost[i]);
				if(j < other) tmp.push_back(cost[i]);
			}
			else {
				tmp.push_back(u);
				if(j < other && 2 * cost[i] - u > 0) tmp.push_back(2*cost[i]-u);
			}
		}
		for(auto j : tmp) q.push(j);
	}
	while(!q.empty()) {
		ll u = q.top(); q.pop();
		ans -= u;
	}
	printf("%lld\n", ans);
	return 0;
}