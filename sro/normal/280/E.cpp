#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const double eps = 1e-6;

struct Segment {
	double l, r;
	double bg, st, xl;
	double inline getval(double pos) const {
		return bg + (st + st + xl * (pos - l)) * (pos - l) / 2;
	}
	double inline get0() const {
		if (fabs(xl) < eps) return fabs(l) < eps ? 0 : -Inf;
		return l - st / xl;
	}
	void inline split(double pos, Segment &a, Segment &b) {
		a.l = l; a.r = pos;
		a.bg = bg; a.st = st; a.xl = xl;
		b.l = pos; b.r = r;
		b.bg = getval(pos); b.st = st + (pos - l) * xl; b.xl = xl;
	}
};

const int maxn = 6005;
int n, q, a, b;

struct SegFunc {
	Segment segs[12005];
	int segc;
	pair<int, double> inline get0() const {
		loop(i, segc) {
			if (segs[i].st > 0) return mak(i, segs[i].l);
			double p = segs[i].get0();
			if (p >= segs[i].l && p <= segs[i].r) {
				return mak(i, p);
			}
			if (!i && p < segs[i].l) return mak(i, segs[i].l);
			if (i == segc - 1 && p > segs[i].r) return mak(i, segs[i].r);
		}
		assert(0);
		return mak(Inf, Inf);
	}
	double inline getval(double p) {
		loop(i, segc) {
			if (p >= segs[i].l && p <= segs[i].r) {
				return segs[i].getval(p);
			}
		}
		return Inf;
	}
	int inline findpos(double p) {
		loop(i, segc) if (p >= segs[i].l && p <= segs[i].r) return i;
		return Inf;
	}
	void inline shr(double dis) {
		int pos = 0;
		double pp = 0;
		tie(pos, pp) = get0();
		Segment lp, rp; segs[pos].split(pp, lp, rp);
		static Segment nsegs[12005];
		int nsegc = pos, nsegbg = pos;
		if (lp.r - lp.l > eps) nsegs[nsegc++] = lp;
		if (dis > eps) nsegs[nsegc++] = {rp.l, rp.l + dis, rp.bg, 0, 0};
		rp.l += dis; rp.r += dis;
		if (rp.r - rp.l > eps) nsegs[nsegc++] = rp;
		circ(i, pos + 1, segc - 1) {
			segs[i].l += dis; segs[i].r += dis;
			nsegs[nsegc++] = segs[i];
		}
		segc = nsegc;
		circ(i, nsegbg, segc - 1) segs[i] = nsegs[i];
		while (segs[segc - 1].l >= q) --segc;
		segs[segc - 1].r = q;
	}
	void inline movr(double dis) {
		parse(it, segs) it.l += dis, it.r += dis;
		while (segs[segc - 1].l >= q) --segc;
		segs[segc - 1].r = q;
	}
	void inline add(const Segment &seg) {
		double nst = seg.st + seg.xl * (segs[0].l - seg.l);
		parse(it, segs) {
			it.bg += seg.getval(it.l);
			it.st += nst;
			it.xl += seg.xl;
			nst += seg.xl * (it.r - it.l);
		}
	}
};

int x[maxn];
SegFunc sf;
double mostpos[maxn];

int main() {
	scanf("%d%d%d%d", &n, &q, &a, &b);
	cont(i, n) scanf("%d", x + i);
	sf.segs[0] = {1, (double)q, 1. * (1 - x[1]) * (1 - x[1]), 2. * (1 - x[1]), 2};
	sf.segc = 1;
	cont(i, n) {
		if (i >= 2) {
			sf.movr(a);
			sf.shr(b - a);
			sf.add({1, (double)q, 1. * (1 - x[i]) * (1 - x[i]), 2. * (1 - x[i]), 2});
		}
		mostpos[i] = sf.get0().second;
	}
	double val = sf.getval(sf.get0().second);
	vector<double> res;
	double lst;
	res.pub(lst = mostpos[n]);
	range(i, n - 1, 1, -1) {
		double xju = lst - mostpos[i];
		if (xju >= a && xju <= b) res.pub(lst = mostpos[i]);
		else if (xju < a) res.pub(lst -= a);
		else if (xju > b) res.pub(lst -= b);
	}
	reverse(all(res));
	parse(it, res) printf("%.6lf ", it);
	printf("\n%.6lf\n", val);
	return 0;
}