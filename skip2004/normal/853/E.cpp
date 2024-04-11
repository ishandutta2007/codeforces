#include<bits/stdc++.h>
typedef long long ll;
const int maxn = 100100;
using std::cin;
using std::cout;

int k, n, q;

struct pt { ll x, y, v; } o[maxn], a[maxn];
struct Ask { ll x; int y, id, v; };

inline ll cross(const pt & x, const pt & y) { return (ll) x.y * y.x - (ll) x.x * y.y; }
inline ll cross(const pt & x, const pt & y, const pt & z) { return ll(y.x - x.x) * (z.y - x.y) - ll(z.x - x.x) * (y.y - x.y); }
inline pt sub(const pt & x, const pt & y) { return (pt) { x.x - y.x, x.y - y.y }; }
inline pt add(const pt & x, const pt & y) { return (pt) { x.x + y.x, x.y + y.y }; }
inline pt mul(const pt & x, int v) { return (pt) { x.x * v, x.y * v }; }
inline pt neg(const pt & x) { return (pt) { -x.x, -x.y }; }
inline int cmp0(const pt & x, const pt & y) { return cross(x, y) > 0; }
inline int cmp1(const pt & x, const pt & y) { return x.x < y.x; }
inline int cmp2(const Ask & x, const Ask & y) { return x.x < y.x; }

ll ans[maxn], bit[maxn];
inline void add(int x, int v) { for(++x;x < maxn;x += x & -x) bit[x] += v; }
inline ll ask(int x) { ll ans = 0; for(++x;x;x &= x - 1) ans += bit[x]; return ans; }
struct calculator {
	int dx, dy;
	inline ll eval(const pt & x) { return (ll) x.x * dy + (ll) x.y * dx; }
	std::vector<Ask> vector;
	inline void push(ll x, int y, int id, int v) { vector.push_back((Ask){ x, y, id, v}); }
	inline void solve() {
		static int rk[maxn];
		for(int i = 0;i < n;++i) rk[i] = i;
		memset(bit, 0, sizeof bit);
		std::sort(rk, rk + n, [&](int x, int y) { return eval(a[x]) < eval(a[y]); });
		sort(vector.begin(), vector.end(), cmp2);
		int idx = 0;
		for(Ask & x : vector) {
			for(;idx < n && eval(a[rk[idx]]) <= x.x;++idx)
				add(rk[idx], a[rk[idx]].v);
			int pos = std::upper_bound(a, a + n, (pt) {x.y}, cmp1) - a - 1;
			ans[x.id] += ask(pos) * x.v;
		}
	}
} D[20];
int idx;
inline void calc(const pt & x, const pt & y, int d, int id, int ad, int nlast = 1) {
	int dx = y.x - x.x, dy = x.y - y.y, gcd = std::abs(std::__gcd(dx, dy));
	dx /= gcd, dy /= gcd;
	const auto eval = [&](const pt & x) { return (ll) x.x * dy + (ll) x.y * dx; };
	int t = -1;
	for(int i = 0;i < idx;++i) if(D[i].dx == dx && D[i].dy == dy) t = i;
	if(t == -1) t = idx++, D[t].dx = dx, D[t].dy = dy;
	D[t].push(eval(x) - d, y.x - nlast, id, ad);
	D[t].push(eval(x) - d, x.x - 1, id, -ad);
}
std::unordered_map<ll, int> map;
inline ll pr(unsigned x, unsigned y) { return (unsigned long long) x << 32 | y; }
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> k >> n >> q;
	map.rehash(1e6 + 7);
	for(int i = 0;i < k;++i) {
		cin >> o[i].x >> o[i].y;
		if(o[i].y > 0) o[i] = neg(o[i]);
	}
	std::sort(o, o + k, cmp0);
	int bk = 0;
	for(int i = 1;i < k;++i) {
		if(cross(o[bk], o[i]) == 0) {
			o[bk] = add(o[bk], o[i]);
		} else {
			o[++bk] = o[i];
		}
	}
	k = bk + 1;
	for(int i = 0;i < n;++i) {
		cin >> a[i].x >> a[i].y >> a[i].v;
		map[pr(a[i].x, a[i].y)] += a[i].v;
	}
	std::sort(a, a + n, cmp1);
	for(int i = 0;i < q;++i) {
		int px, py, t;
		cin >> px >> py >> t;
		std::vector<pt> vec, hull;
		pt left = {px, py};
		for(int i = 0;i < k;++i) {
			left = add(left, mul(o[i], t));
			vec.push_back(mul(o[i], - t * 2));
		}
		sort(vec.begin(), vec.end(), cmp0);
		for(const pt & x : vec) hull.push_back(left = add(left, x));
		for(const pt & x : vec) hull.push_back(left = sub(left, x));
		rotate(hull.begin(), min_element(hull.begin(), hull.end(), cmp1), hull.end());
		hull.push_back(hull.front());
		const int id = i;
		ll mx = -2e9, mid = hull.size() / 2;
		for(pt & x : hull) mx = std::max(mx, x.x);
		for(int i = 0;i + 1 < hull.size();++i) {
			if(hull[i].x != hull[i + 1].x) {
				if(i < mid) {
					calc(hull[i], hull[i + 1], 0, id, 1, hull[i + 1].x != mx);
				} else {
					calc(hull[i + 1], hull[i], 1, id, -1, hull[i].x != mx);
				}
			}
		}
	}
	for(int i = 0;i < idx;++i) D[i].solve();
	for(int i = 0;i < q;++i) {
		cout << ans[i] << '\n';
	}
}