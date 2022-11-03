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

int n, m;
int p[1 << 20], q[1 << 20];
int b[1 << 20], d[1 << 20];
const int bl = 1 << 8, bls = 1 << 7;
int cnt[1 << 12][1 << 12];

int main() {
	scanf("%d", &n);
	memset(p, -1, sizeof(p)); memset(q, -1, sizeof(q));
	loop(i, n) scanf("%d", p + i), --p[i];
	loop(i, n) scanf("%d", q + i), --q[i];
	loop(i, n) b[p[i]] = i, d[q[i]] = i;
	loop(i, n) p[i] = d[p[i]];
	loop(i, n) ++cnt[i / bl + 1][p[i] / bl + 1];
	cont(i, n / bl + 1) cont(j, n / bl + 1) cnt[i][j] += cnt[i][j - 1] + cnt[i - 1][j] - cnt[i - 1][j - 1];
	loop(i, n) q[p[i]] = i;
	scanf("%d", &m); int ans = n - 1;
	cont(i, m) {
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		(a += ans) %= n; (b += ans) %= n;
		(c += ans) %= n; (d += ans) %= n;
		if(a > b) swap(a, b);; if(c > d) swap(c, d);
		int as, bs, cs, ds;
		as = (a + bls) / bl; bs = (b + bls) / bl;
		cs = (c + bls) / bl; ds = (d + bls) / bl;
		ans = cnt[bs][ds] - cnt[as][ds] - cnt[bs][cs] + cnt[as][cs];
		as *= bl; bs *= bl; cs *= bl; ds *= bl;
		if(as < a) {
			circ(j, as, a - 1) if(p[j] >= c && p[j] <= d) --ans;
		} else {
			circ(j, a, as - 1) if(p[j] >= c && p[j] <= d) ++ans;
		}
		if(bs <= b) {
			circ(j, bs, b) if(p[j] >= c && p[j] <= d) ++ans;
		} else {
			circ(j, b + 1, bs - 1) if(p[j] >= c && p[j] <= d) --ans;
		}
		if(cs < c) {
			circ(j, cs, c - 1) if(q[j] >= as && q[j] < bs) --ans;
		} else {
			circ(j, c, cs - 1) if(q[j] >= as && q[j] < bs) ++ans;
		}
		if(ds <= d) {
			circ(j, ds, d) if(q[j] >= as && q[j] < bs) ++ans;
		} else {
			circ(j, d + 1, ds - 1) if(q[j] >= as && q[j] < bs) --ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}