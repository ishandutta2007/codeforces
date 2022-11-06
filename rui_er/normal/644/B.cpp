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
const ll N = 2e5+5;

ll n, b, t[N], d[N], ans[N], now;
queue<ll> q;

int main() {
	scanf("%lld%lld", &n, &b);
	rep(i, 1, n) scanf("%lld%lld", &t[i], &d[i]);
	q.push(ans[1]=now=t[1]+d[1]);
	rep(i, 2, n) {
		while(!q.empty() && q.front() <= t[i]) q.pop();
		if(ll(q.size()) > b) {
			ans[i] = -1;
			continue;
		}
		now = max(now, t[i]);
		now += d[i];
		q.push(ans[i]=now);
	}
	rep(i, 1, n) printf("%lld%c", ans[i], " \n"[i==n]);
	return 0;
}