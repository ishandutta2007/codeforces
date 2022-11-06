//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

ll T, n, a[N], tot[2];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
vector<ll> pos[2];
ll calc(ll k) {
	ll ans = 0;
	rep(i, 1, (n+1)/2) ans += abs(pos[k][i] - 2 * i + 1);
	return ans;
}

int main() {
	for(scanf("%lld", &T);T;T--) {
		tot[0] = tot[1] = 0;
		pos[0].clear(); pos[1].clear();
		pos[0].push_back(0); pos[1].push_back(0);
		scanf("%lld", &n);
		rep(i, 1, n) {
			scanf("%lld", &a[i]);
			++tot[a[i]&=1];
			pos[a[i]].push_back(i);
		}
		if(abs(tot[0]-tot[1]) > 1) {puts("-1"); continue;}
		if(n & 1) printf("%lld\n", tot[0]>tot[1]?calc(0):calc(1));
		else printf("%lld\n", min(calc(0), calc(1)));
	}
	return 0;
}