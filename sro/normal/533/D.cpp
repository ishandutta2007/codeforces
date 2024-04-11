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

int n;
ll x[1 << 17], d[1 << 17];
ll f[1 << 17], g[1 << 17];
vector<ll> stk;
vector<pair<ll, ll> > s1, s2;

int main() {
	scanf("%d", &n);
	loop(i, n + 2) scanf("%lld", x + i);
	cont(i, n) scanf("%lld", d + i), d[i] <<= 1;
	f[0] = INF; stk.pub(0);
	cont(i, n) {
		while(x[i] > f[stk.back()]) stk.pob();
		if(d[i] > x[i] - x[stk.back()]) {
			f[i] = d[i] + x[stk.back()];
			if(f[i] >= x[n + 1]) return puts("0"), 0;
			while(f[stk.back()] <= f[i]) stk.pob();
			stk.pub(i);
		} else {
			f[i] = -INF;
		}
	}
	stk.clear();
	g[n + 1] = -INF; stk.pub(n + 1);
	range(i, n, 1, -1) {
		if(x[i] < g[stk.back()]) stk.pob();
		if(d[i] > x[stk.back()] - x[i]) {
			g[i] = x[stk.back()] - d[i];
			if(g[i] <= x[0]) return puts("0"), 0;
			while(g[stk.back()] >= g[i]) stk.pob();
			stk.pub(i);
		} else {
			g[i] = INF;
		}
	}
	ll ans = x[n + 1] - x[0];
	cont(i, n) {
		if(f[i] != -INF) {
			ans = min(ans, x[n + 1] - x[i]);
			s1.pub(mak(f[i], x[i]));
		}
	}
	cont(i, n) {
		if(g[i] != INF) {
			ans = min(ans, x[i] - x[0]);
			s2.pub(mak(g[i], x[i]));
		}
	}
	sort(all(s1)); sort(all(s2));
	int r = 0;
	set<ll> ss;
	loop(i, SZ(s1)) {
		while(r < SZ(s2) && s2[r].first <= s1[i].first) {
			ss.insert(s2[r++].second);
		}
		set<ll>::iterator it = ss.upper_bound(s1[i].second);
		if(it != ss.end()) ans = min(ans, *it - s1[i].second);
	}
	printf("%.10lf\n", ans / 2.);
	return 0;
}