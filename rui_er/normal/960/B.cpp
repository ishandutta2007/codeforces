//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 ll T; for(scanf("%d", &T);T;T--)
#define mulT1 ll T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const ll N = 1e3+5;

ll n, a[N], k, _, ans;
priority_queue<ll> q;

int main() {
	scanf("%lld%lld%lld", &n, &k, &_); k += _;
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, n) {scanf("%lld", &_); q.push(abs(a[i]-_));}
	while(k--) {ll qwq = q.top(); q.pop(); q.push(qwq?qwq-1:1);}
	while(!q.empty()) {ans += q.top() * q.top(); q.pop();}
	printf("%lld\n", ans);
	return 0;
}