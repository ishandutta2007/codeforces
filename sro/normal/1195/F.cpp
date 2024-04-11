#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define foreach(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct Point {
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
	Point inline operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
	ll inline operator*(const Point &p) const { return 1ll * x * p.y - 1ll * y * p.x; }
	friend bool inline operator<(const Point &a, const Point &b) {
		bool ia = a.y > 0 || (a.y == 0 && a.x >= 0);
		bool ib = b.y > 0 || (b.y == 0 && b.x >= 0);
		if (ia != ib) return ia;
		return a * b > 0;
	}
	friend bool inline operator==(const Point &a, const Point &b) { return !((a < b) && (b < a)); }
};

template <typename tp, int siz>
struct Fenwick {
	tp dt[siz + 5];
	void init() { loop(i, siz + 5) dt[i] = tp(); }
	Fenwick() { init(); }
	void inline add(int a, tp x) {
		for (++a; a < siz + 5; a += a & -a) dt[a] += x;
	}
	tp inline sum(int a) {
		tp res = 0;
		for (++a; a; a -= a & -a) res += dt[a];
		return res;
	}
	tp inline sum(int l, int r) { return sum(r) - sum(l - 1); }
};

Fenwick<ll, 100005> bit;
int T;
vector<Point> vs[100005];
vector<int> ids[100005];
map<Point, int> id;
set<int> pos[300005];
vector<pair<pair<int, int>, int> > ps;
int is;
ll ans[300005];

int main() {
	scanf("%d", &T);
	cont(t, T) {
		int n;
		scanf("%d", &n);
		vector<Point> pt;
		while (n--) {
			int x, y;
			scanf("%d%d", &x, &y);
			pt.emb(x, y);
		}
		loop(i, SZ(pt)) vs[t].pub(pt[(i + 1) % SZ(pt)] - pt[i]);
	}
	cont(t, T) loop(i, SZ(vs[t])) {
		auto p = vs[t][i];
		int &ID = id[p];
		if (!ID) ID = ++is;
		ids[t].pub(ID);
	}
	cont(t, T) loop(i, SZ(vs[t])) pos[ids[t][i]].insert(t);
	scanf("%d", &T);
	loop(t, T) {
		int l, r;
		scanf("%d%d", &l, &r);
		ps.emb(mak(l, r), t);
	}
	sort(all(ps));
	cont(i, is) bit.add(*pos[i].begin(), 1);
	int lpos = 1;
	foreach (it, ps) {
		int l = it->first.first, r = it->first.second;
		while (lpos < l) {
			loop(j, SZ(ids[lpos])) {
				int id = ids[lpos][j];
				bit.add(lpos, -1);
				auto itr = pos[id].upper_bound(lpos);
				if (itr != pos[id].end()) bit.add(*itr, 1);
			}
			++lpos;
		}
		ans[it->second] = bit.sum(r);
	}
	loop(i, T) printf("%lld\n", ans[i]);
	return 0;
}