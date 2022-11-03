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

const lf eps = 1e-10, pi = acosl(-1);
int sign(const lf &x) {return x < -eps ? -1 : (x > eps);} //  0  1-1  0
bool inline feql(const lf &a, const lf &b) {return !sign(a - b);}
bool inline fsml(const lf &a, const lf &b) {return !~sign(a - b);}
bool inline flar(const lf &a, const lf &b) {return sign(a - b) == 1;}

//  Tp 
template<typename Tp> struct Point {
	Tp x, y;
	Point(Tp x = 0, Tp y = 0): x(x), y(y) {}
	Point inline operator+(const Point &p) const {return Point(x + p.x, y + p.y);}
	Point inline &operator+=(const Point &p) {return x += p.x, y += p.y, *this;}
	Point inline operator-(const Point &p) const {return Point(x - p.x, y - p.y);}
	Point inline &operator-=(const Point &p) {return x -= p.x, y -= p.y, *this;}
	Point inline operator*(const Tp &p) const {return Point(x * p, y * p);}
	Point inline &operator*=(const Tp &p) {return x *= p, y *= p, *this;}
	Point inline operator/(const Tp &p) const {return Point(x / p, y / p);}
	Point inline &operator/=(const Tp &p) {return x /= p, y /= p, *this;}
	Tp inline operator*(const Point &p) const {return x * p.y - y * p.x;} // 
	Tp inline operator%(const Point &p) const {return x * p.x + y * p.y;} // 
	lf inline size() const {return sqrtl(x * x + y * y);} // 
	Tp inline length() const {return x * x + y * y;} // 
	lf inline operator^(const Point &p) const {return acosl(*this % p / size() / p.size());} // 
	lf inline angle() const {return atan2l(y, x);} // ATAN2
	bool inline operator<(const Point &p) const {return feql(x, p.x) ? fsml(x, p.x) : fsml(y, p.y);}
	bool inline operator>(const Point &p) const {return feql(x, p.x) ? flar(x, p.x) : flar(y, p.y);}
	friend ostream inline &operator<<(ostream &o, const Point &p) {o << '(' << p.x << ',' << p.y << ')'; return o;}
};
typedef Point<lf> point;
typedef Point<ll> ipoint;

//  Tp 
template<typename Tp> struct Line {
	Tp a, b;
	Line() {}
	Line(Tp a, Tp b): a(a), b(b) {}
};
typedef Line<point> line;

lf inline delta(const line &x, const line &y) {
	point p1 = x.a, v1 = x.b - x.a;
	point p2 = y.a, v2 = y.b - y.a;
	if(!sign(fabs(v1 * v2))) throw !sign((p2 - p1) * v2);
	return ((p2 - p1) * v1) / (v1 * v2);
}

int n, m;
point p[1005];
line l;

void solve() {
	point o = l.a, v = l.b - l.a;
	lf ans = 0;
	vector<pair<lf, int> > fu;
	cont(i, n) {
		lf li = sign(v * (p[i] - o)), ri = sign(v * (p[i + 1] - o));
		if(li == ri) continue;
		lf del = delta(line(p[i], p[i + 1]), l);
		if(li > ri) fu.pub(mak(del, li && ri ? 2 : 1));
		else fu.pub(mak(del, li && ri ? -2 : -1));
	}
	sort(all(fu));
	int qzh = 0;
	loop(i, SZ(fu) - 1) {
		qzh += fu[i].second;
		if(qzh) ans += fu[i + 1].first - fu[i].first;
	}
	printf("%.10Lf\n", ans * v.size());
}

int main() {
	scanf("%d%d", &n, &m);
	cont(i, n) {
		lf x, y; scanf("%Lf%Lf", &x, &y);
		p[i] = point(x, y);
	}
	p[n + 1] = p[1];
	while(m--) {
		lf x1, y1, x2, y2; scanf("%Lf%Lf%Lf%Lf", &x1, &y1, &x2, &y2);
		l = line(point(x1, y1), point(x2, y2));
		solve();
	}
}