//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define double long double
#define int long long

typedef pair<double, double> point;
#define x first
#define y second
point operator +(point a, point b) { return point(a.x + b.x, a.y + b.y); }
point operator -(point a, point b) { return point(a.x - b.x, a.y - b.y); }
double operator *(point a, point b) { return a.x * b.x + a.y * b.y; }
double operator ^(point a, point b) { return a.x * b.y - a.y * b.x; }
double	get_dis(point a, point b) { return sqrt(abs((a - b) * (a - b))); }

const int N = 5e4 + 4, M = N * 2;
const double oo = 4e12;
const double eps = 1e-18;

int read() { int x; cin >> x; return x; }

double a[N], b[N], c[N];

point line_intersect(int x, int y) {
	return point((c[x] * b[y] - c[y] * b[x]) / (a[x] * b[y] - a[y] * b[x]), (a[x] * c[y] - a[y] * c[x]) / (a[x] * b[y] - a[y] * b[x]));
}
bool zero_delta;
pair<point, point> circle_line_intersect(int line, double cx, double cy, double r) {
	double la = a[line], lb = b[line], lc = c[line] - la * cx - lb * cy;
	double delta = r * r * (la * la + lb * lb) - lc * lc;
	if (delta < 0) {
		zero_delta = 1;
		return {point(1e6 + 49, 1e6 + 49), point(49, 49)};	
	}
	zero_delta = 0;
	delta = sqrt(r * r * (la * la + lb * lb) - lc * lc);
	double x1 = ((la * lc + lb * delta) / (la * la + lb * lb)) + cx;
	double y1 = ((lb * lc - la * delta) / (la * la + lb * lb)) + cy;
	double x2 = ((la * lc - lb * delta) / (la * la + lb * lb)) + cx;
	double y2 = ((lb * lc + la * delta) / (la * la + lb * lb)) + cy;
	return {point(x1, y1), point(x2, y2)};
}

int fen[M];
int query(int m, int res = 0) { m++;
	while (m > 0)
		res += fen[m], m -= m & -m;
	return res;
}
void update(int m, int x) { m++;
	while (m < M)
		fen[m] += x, m += m & -m;
}


pair<double, int> s[N * 2];
int n, m, ql[N], qr[N], mark[N];
pair<point, point> seg[N];
double qx, qy; 
int qcnt;

double angle(point a) { return atan2(a.y, a.x); }

void build(double rad) {
	m = 0;
	memset(ql, -1, sizeof ql);
	memset(qr, -1, sizeof qr);
	memset(mark, 0, sizeof mark);
	point o = {qx, qy};
	rep(i, n) {
		auto foo = circle_line_intersect(i, qx, qy, rad);
		point p1 = foo.first, p2 = foo.second;
		if (zero_delta)
			continue;
			
		mark[i] = 1;
		s[m++] = {angle(p1 - o), i};
		s[m++] = {angle(p2 - o), i};
	}
	sort(s, s + m);
	int cur = 0;
	rep(i, m) {
		int id = s[i].second;
		cur++;
		if (mark[id])
			ql[id] = cur;
		else
			qr[id] = cur + 1;
		mark[id] ^= 1;
	}
}


vector<int> to[M];
int check(double rad) {
	build(rad);
	rep(i, M)
		to[i].clear();
	rep(i, n) if (mark[i]) {
		to[ql[i]].push_back(qr[i]);
	}
	memset(fen, 0, sizeof fen);
	long long res = 0;
	rep(l, M) {
		for (int r : to[l]) {
			res += query(r) - query(l);
			update(r, 1);
		}
	}
	return res;
}

pair<int, int> ord[N];

double find(double rad) {
	build(rad);
	int t = 0;
	rep(i, n) if (mark[i]) {
		ord[t++] = {qr[i] - ql[i], i};
	}
	sort(ord, ord + t);
	reverse(ord, ord + t);
	set<pair<int, int>> setl, setr;
	double res = 0, mx = 0;
	int cnt = 0;
	rep(_, t) {
		int i = ord[_].second;
		auto it = setl.lower_bound(make_pair(ql[i], -1));
		while (it != setl.end() && it->first < qr[i]) {
			double d = get_dis({qx, qy}, line_intersect(i, it->second));
			++it;
			mx = max(mx, d);
			res += d;
			cnt++;
		}
		it = setr.lower_bound(make_pair(ql[i] + 1, -1));
		while (it != setr.end() && it->first <= qr[i]) {
			double d = get_dis({qx, qy}, line_intersect(i, it->second));
			++it;
			mx = max(mx, d);
			res += d;
			cnt++;
		}
		setl.insert({ql[i], i});
		setr.insert({qr[i], i});
	}
	return res + rad * (qcnt - cnt);
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> qx >> qy >> qcnt;
	qx /= 1000;
	qy /= 1000;
	rep(i, n) {
		double x, y;
		cin >> x >> y;
		a[i] = x / 1000;
		b[i] = -1;
		c[i] = -y / 1000;
	}
	double bl = 0, br = 2e12 + 6;
	rep(_, 80) {
		double bm = (bl + br) / 2;
		int z = check(bm);
		if (z >= qcnt)
			br = bm;
		else
			bl = bm;
	}
	cout << setprecision(6) << fixed << find(bl);
}