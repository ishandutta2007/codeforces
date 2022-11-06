//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define mulT0 ll T; for(scanf("%lld", &T);T;T--)
#define mulT1 ll T, rnds; for(scanf("%lld", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const ll N = 2e3+5;

ll n, a[N], ans, now;
priority_queue<ll> q;

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, n) {
		if(a[i] >= 0) {now += a[i]; ++ans;}
		else {
			while(!q.empty() && now + a[i] < 0 && q.top() + a[i] > 0) {now += q.top(); q.pop(); --ans;}
			if(now + a[i] >= 0) {now += a[i]; q.push(-a[i]); ++ans;}
		}
	}
	printf("%lld\n", ans);
	return 0;
}