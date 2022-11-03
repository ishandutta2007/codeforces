/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

ll n, u, r;
ll a[33], b[33], k[33], p[33];
ll ans = -INF;

void dfs(int now, int is) {
	if((u - now) % 2 == 0) {
		ll gx = 0;
		cont(i, n) gx += a[i] * k[i];
		ans = max(ans, gx);
	}
	if(now == u) return;
	vector<ll> as;
	cont(i, n) as.pub(a[i]);
	if(!is) {
		cont(i, n) a[i] ^= b[i];
		dfs(now + 1, 1);
	}
	cont(i, n) a[i] = as[p[i] - 1] + r;
	dfs(now + 1, 0);
}

int main() {
	scanf("%lld%lld%lld", &n, &u, &r);
	cont(i, n) scanf("%lld", a + i);
	cont(i, n) scanf("%lld", b + i);
	cont(i, n) scanf("%lld", k + i);
	cont(i, n) scanf("%lld", p + i);
	dfs(0, 0); printf("%lld\n", ans);
	return 0;
}