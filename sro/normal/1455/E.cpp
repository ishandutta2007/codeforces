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

pair<int, int> a[4];

void solve() {
	loop(i, 4) scanf("%d%d", &a[i].first, &a[i].second);
	ll ans = INF;
	loop(tp, 2) {
		loop(X1, 4) loop(X2, 4) loop(Y1, 4) loop(yf, 2) {
			ll x1 = a[X1].first, x2 = a[X2].first, y1 = a[Y1].second, y2;
			if(x1 > x2) continue;
			if(yf) y2 = y1 + x2 - x1;
			else y2 = y1 - x2 + x1;
			vector<pair<ll, ll> > b = {mak(x1, y1), mak(x1, y2), mak(x2, y1), mak(x2, y2)};
			sort(all(b));
			do {
				ll res = 0;
				loop(i, 4) res += abs(a[i].first - b[i].first) + abs(a[i].second - b[i].second);
				ans = min(ans, res);
			} while(next_permutation(all(b)));
		}
		loop(i, 4) swap(a[i].first, a[i].second);
	}
	printf("%lld\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}