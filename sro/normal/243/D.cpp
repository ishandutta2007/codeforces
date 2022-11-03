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

struct Point {
	int x, y, ix, iy;
	friend inline bool operator<(const Point &a, const Point &b) {
		return a.x < b.x;
	}
};

int n, x, y, m;
int a[1005][1005];
vector<Point> pts;
vector<int> lss;

struct Segtree {
	int dat[1 << 22];
	void inline pd(int now) {
		dat[now << 1] = max(dat[now << 1], dat[now]);
		dat[now << 1 | 1] = max(dat[now << 1 | 1], dat[now]);
	}
	void inline pu(int now) {
		dat[now] = min(dat[now << 1], dat[now << 1 | 1]);
	}
	void inline modify(int l, int r, int x, int now = 1, int nl = 0, int nr = m) {
		if(nl >= l && nr <= r) {
			dat[now] = max(dat[now], x);
			return;
		}
		if(nl > r || nr < l) return;
		pd(now); int m = (nl + nr) >> 1;
		modify(l, r, x, now << 1, nl, m);
		modify(l, r, x, now << 1 | 1, m + 1, nr);
		pu(now);
	}
	int inline get(int l, int r, int now = 1, int nl = 0, int nr = m) {
		if(nl >= l && nr <= r) return dat[now];
		if(nl > r || nr < l) return Inf;
		pd(now); int m = (nl + nr) >> 1;
		return min(get(l, r, now << 1, nl, m), get(l, r, now << 1 | 1, m + 1, nr));
	}
} seg;

int main() {
	scanf("%d%d%d", &n, &x, &y);
	loop(i, n) loop(j, n) scanf("%d", a[i] + j);
	if(x < 0) {
		x = -x;
		loop(i, n >> 1) loop(j, n) swap(a[i][j], a[n - 1 - i][j]);
	}
	if(y < 0) {
		y = -y;
		loop(i, n) loop(j, n >> 1) swap(a[i][j], a[i][n - 1 - j]);
	}
	loop(i, n) loop(j, n) {
		Point p; p.ix = i; p.iy = j;
		p.x = x * i + y * j; p.y = y * i - x * j + x * n;
		lss.pub(p.y); lss.pub(p.y + x + y - 1);
		pts.pub(p);
	}
	sort(all(lss)); lss.resize(unique(all(lss)) - lss.begin()); m = lss.size();
	sort(all(pts));
	ll res = 0;
	loop(i, n * n) {
		Point &p = pts[i];
		int pyl = lower_bound(all(lss), p.y) - lss.begin(), pyr = lower_bound(all(lss), p.y + x + y - 1) - lss.begin();
		int see = seg.get(pyl, pyr);
		res += max(0, a[p.ix][p.iy] - see);
		seg.modify(pyl, pyr, a[p.ix][p.iy]);
	}
	printf("%lld\n", res);
	return 0;
}