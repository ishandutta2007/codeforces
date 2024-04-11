/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); i++)
#define cont(i, n)          for(int i = 1; i <= (n); i++)
#define circ(i, a, b)       for(int i = (a); i <= (b); i++)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
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

struct BIT {
	ll dt[1 << 17];
	void inline add(int a, ll x) {
		a = (1 << 17) - a - 1;
		while(a < (1 << 17)) {
			dt[a] += x;
			a += a & -a;
		}
	}
	ll inline get(int a) {
		a = (1 << 17) - a - 1;
		ll res = 0;
		while(a) {
			res += dt[a];
			a -= a & -a;
		}
		return res;
	}
} as, bs;

int n, q;
ll ia[1 << 17], ib[1 << 17];
int s[1 << 17];

void inline add(int i, ll x) {
	if(!i) return;
	if(x > 0) {
		ll bi = bs.get(i), bj = bs.get(i + 1);
		if(bj > bi || i == n) {
			ll toup = min(x, bj - bi);
			bs.add(i, toup);
			x -= toup;
		}
		as.add(i, x);
	} else {
		x = -x;
		ll ai = as.get(i), aj = as.get(i + 1);
		if(aj < ai || i == n) {
			ll toup = min(x, ai - aj);
			as.add(i, -toup);
			x -= toup;
		}
		bs.add(i, -x);
	}
}

ll avg(ll a, ll b) {
	ll sm = a + b;
	if(sm > 0) return (sm + 1) / 2;
	else return sm / 2;
}

int main() {
	scanf("%d", &n);
	cont(i, n) scanf("%d", s + i);
	ia[1] = s[1]; ib[1] = 0;
	circ(i, 2, n) {
		if(s[i] > s[i - 1]) {
			ia[i] = ia[i - 1];
			ib[i] = ib[i - 1] + s[i] - s[i - 1];
		} else {
			ia[i] = ia[i - 1] + s[i] - s[i - 1];
			ib[i] = ib[i - 1];
		}
	}
	range(i, n, 1, -1) {
		as.add(i, ia[i] - ia[i + 1]);
		bs.add(i, ib[i] - ib[i + 1]);
	}
	scanf("%d", &q);
	printf("%lld\n", avg(as.get(1), bs.get(n)));
	while(q--) {
		int l, r, x; scanf("%d%d%d", &l, &r, &x);
		add(r, x); add(l - 1, -x);
		printf("%lld\n", avg(as.get(1), bs.get(n)));
	}
	return 0;
}