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

const int maxn = 1 << 17;
int n;
ll k;
ll qzh[20][maxn];

void mergesort(int i, int l, int m, int r) {
	int ls = l, rs = m, ps = l;
	while(ls < m && rs < r) {
		if(qzh[i][ls] < qzh[i][rs]) {
			qzh[i + 1][ps] = qzh[i][ls];
			ls++; ps++;
		} else {
			qzh[i + 1][ps] = qzh[i][rs];
			rs++; ps++;
		}
	}
	while(ls < m) {
		qzh[i + 1][ps] = qzh[i][ls];
		ls++; ps++;
	}
	while(rs < r) {
		qzh[i + 1][ps] = qzh[i][rs];
		rs++; ps++;
	}
}

ll count(int i, int l, int m, int r, ll x) {
	int ls = l - 1;
	ll ans = 0;
	circ(j, m, r - 1) {
		if(qzh[i][j] == INF) break;
		while(ls + 1 < m && qzh[i][j] - qzh[i][ls + 1] >= x) ls++;
		ans += ls - l + 1;
	}
	return ans;
}

bool check(ll m) {
	ll ans = 0;
	loop(i, 17) {
		int mii = 1 << i;
		range(j, 0, maxn - 1, mii << 1) {
			ans += count(i, j, j + mii, j + mii + mii, m);
		}
	}
	return ans >= k;
}

int main() {
	scanf("%d%lld", &n, &k);
	cont(i, n) {
		int x; scanf("%d", &x);
		qzh[0][i] = qzh[0][i - 1] + x;
	}
	circ(i, n + 1, maxn - 1) qzh[0][i] = INF;
	loop(i, 17) {
		int mii = 1 << i;
		range(j, 0, maxn - 1, mii << 1) {
			mergesort(i, j, j + mii, j + mii + mii);
		}
	}
	ll l = -2e14, r = 2e14;
	while(r - l > 1) {
		ll m = l + (r - l) / 2;
		if(check(m)) l = m;
		else r = m;
	}
	return 0 & printf("%lld\n", l);
}