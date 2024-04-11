#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

#define R(x) const { return x; }
template <class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) R(x<p.x || (x==p.x && y<p.y))
	bool operator==(P p) R(x==p.x && y==p.y)
	P operator+(P p) R(P(x+p.x, y+p.y))
	P operator-(P p) R(P(x-p.x, y-p.y))
	P operator*(T d) R(P(x*d, y*d))
	P operator/(T d) R(P(x/d, y/d))
	T dot(P p) R(x*p.x + y*p.y)
	T cross(P p) R(x*p.y - y*p.x)
	T dist2() R(x*x + y*y) // distance^2
	double dist() R(sqrt((double)dist2())) //length
	// angle to x-axis in interval [-pi, pi]
	double angle() R(atan2(y, x))
	P unit() R(*this/(T)dist()) // makes dist()=1
	P perp() R(P(-y, x)) // rotates +pi/2 radians
	P normal() R(perp().unit())
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) R(P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)))
};

template <class P>
double segDist(const P& s, const P& e, const P& p) {
	if (s==e) return (p-s).dist();
	auto d = (e-s).dist2(), t = min(d,max({},(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).dist()/d;
}

int main() {
	cin.sync_with_stdio(false);
	int N;
	ll CX, CY;
	cin >> N >> CX >> CY;
	ll ma = 0;
	double mi = 1.0 / 0.0;
	ll x0, y0;
	ll x1, y1;
	auto test = [&](ll x, ll y, ll x2, ll y2) {
		Point<double> p1(x, y);
		Point<double> p2(x2, y2);
		Point<double> p(0, 0);
		double r = segDist(p1, p2, p);
		mi = min(mi, r);
	};
	rep(i,0,N) {
		ll x, y;
		cin >> x >> y;
		x -= CX;
		y -= CY;
		if (i == 0) x0 = x, y0 = y;
		ll d = x*x + y*y;
		ma = max(ma, d);
		// mi = min(mi, d);
		if (i != 0)
			test(x1, y1, x, y);
		if (i == N-1)
			test(x, y, x0, y0);
		x1 = x;
		y1 = y;
	}
	double pi = acos(0) * 2;
	double res = ma * pi - mi * mi * pi;
	cout << setprecision(10) << fixed << res << endl;
}