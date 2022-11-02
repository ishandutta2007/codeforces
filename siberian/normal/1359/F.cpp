#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const ld EPS = 1e-12;

int sign(ld x) {
	if (x > EPS) return 1;
	if (x < -EPS) return -1;
	return 0;
}

struct point{
	ld x, y;
	point() {}
	point(ld _x, ld _y) {
		x = _x, y = _y;
	}
};

point operator-(const point & a, const point & b) {
	return point(a.x - b.x, a.y - b.y);
}

point operator+(const point & a, const point & b) {
	return point(a.x + b.x, a.y + b.y);
}

ld operator^(const point & a, const point & b) {
	return a.x * b.y - a.y * b.x;
}

point operator*(const point & a, ld x) {
	return point(a.x * x, a.y * x);
}

#define vec point

ld sq(ld x) {
	return x * x;
}

ld dist(vec a) {
	return sqrt(sq(a.x) + sq(a.y));
}

struct seg{
	point l, r;
	seg() {}
	seg(point _l, point _r) {
		l = _l, r = _r;
	}
	ld get_y(ld x) const {
		if (sign(l.x - r.x) == 0) return l.y;
		return l.y + (r.y - l.y) * (x - l.x) / (r.x - l.x);
	}
};

bool checkCross(ld a, ld b, ld c, ld d) {
	if (a > b) swap(a, b);
	if (c > d) swap(c, d);
	return sign(max(a, c) - min(b, d)) <= 0;
}

bool checkCross(seg a, seg b) {
	if (!checkCross(a.l.x, a.r.x, b.l.x, b.r.x)) return false;
	if (!checkCross(a.l.y, a.r.y, b.l.y, b.r.y)) return false;
	vec v1, v2, v3;
	v1 = a.r - a.l;
	v2 = b.l - a.l;
	v3 = b.r - a.l;
	if (sign(v1 ^ v2) * sign(v1 ^ v3) == 1) return false;
	v1 = b.r - b.l;
	v2 = a.l - b.l;
	v3 = a.r - b.l;
	if (sign(v1 ^ v2) * sign(v1 ^ v3) == 1) return false;
	return true;
}

bool operator<(const seg & a, const seg & b) {
	ld x = max(min(a.l.x, a.r.x), min(b.l.x, b.r.x));
	return sign(a.get_y(x) - b.get_y(x)) == -1;
}

struct event{
	ld x;
	int type, id;
	event() {}
	event(ld _x, int _type, int _id) {
		x = _x, type = _type, id = _id;
	}
};

bool operator<(const event & a, const event & b) {
	if (sign(a.x - b.x) != 0) return a.x < b.x;
	return a.type > b.type;
}

set<seg> s;
vector<set<seg>::iterator> where;

set<seg>::iterator prev(set<seg>::iterator it) {
	if (it == s.begin()) return s.end();
	return --it;
}

set<seg>::iterator next(set<seg>::iterator it) {
	return ++it;
}

bool checkCross(const vector<seg> & a) {
	int n = a.size();
	vector<event> have;
	for (int i = 0; i < n; i++) {
		have.push_back({min(a[i].l.x, a[i].r.x), +1, i});
		have.push_back({max(a[i].l.x, a[i].r.x), -1, i});
	}
	sort(all(have));
	s = {};
	where.resize(n);
	for (auto [x, type, id] : have) {
		if (type == 1) {
			auto nxt = s.lower_bound(a[id]);
			auto prv = prev(nxt);
			if (nxt != s.end() && checkCross(a[id], *nxt)) return true;
			if (prv != s.end() && checkCross(a[id], *prv)) return true;
			where[id] = s.insert(nxt, a[id]);
		} else if (type == -1) {
			auto nxt = next(where[id]);
			auto prv = prev(where[id]);
			if (nxt != s.end() && prv != s.end() && checkCross(*nxt, *prv)) return true;
			s.erase(where[id]);
		}
	}
	return false;
}

int n;
vector<point> a;
vector<vec> v;
vector<ld> speed;

void read() {
	cin >> n;
	a.resize(n);
	v.resize(n);
	speed.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y >> v[i].x >> v[i].y >> speed[i];
	}
}

void no() {
	cout << "No show :(" << endl;
	exit(0);
}

bool check(ld t) {
	vector<seg> have;
	for (int i = 0; i < n; i++) {
		have.push_back({a[i], a[i] + (v[i] * (speed[i] * t / dist(v[i])))});
	}
	return checkCross(have);
}

ld ans;

void run() {
	ld l = 0, r = 1e10;
	if (!check(r)) no();
	for (int it = 0; it < 65; it++) {
		ld mid = (l + r) / 2;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	ans = r;
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(20);
	cout.setf(ios::fixed);
	read();
	run();
	write();
	return 0;
}