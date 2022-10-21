#include<bits/stdc++.h>
using namespace std;

#define double long double
const int maxn = 3e5 + 5;
const double PI = acos(-1.0);
const double eps = 5e-10;

template <class T> int sgn(T x) { return (x > eps) - (x < eps); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes d is t ()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated a  radians ccw around the origin
	P rotate(double a) const {
	return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
	return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P> bool onSegment(P s, P e, P p) {
	return abs(p.cross(s, e)) <= eps && (s - p).dot(e - p) < eps;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b);
	auto oc = a.cross(b, c), od = a.cross(b, d);
	if (sgn(oa) * sgn(ob) < -eps && sgn(oc) * sgn(od) < -eps)
	return {(a * ob - b * oa) / (ob - oa)};
	set<P> s;
	if (onSegment(c, d, a)) s.insert(a);
	if (onSegment(c, d, b)) s.insert(b);
	if (onSegment(a, b, c)) s.insert(c);
	if (onSegment(a, b, d)) s.insert(d);
	return {s.begin(), s.end()};
}

int n, hi;
Point<double> p[maxn], q[maxn];

double dist(Point<double> a, Point<double> b) {
	return (double)sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
	scanf("%d%d",&n,&hi);
	for(int i=1;i<=n;i++) {
		int x,y; scanf("%d%d",&x,&y);
		p[i] = Point<double>(x, y);
		// printf("%lf %lf\n",p[i].x,p[i].y);
	}
	auto eye = Point<double>(p[n].x,p[n].y+hi);

	double ans = 0;
	for(int i=1;i<n;i++) {
		double slope = (double)(eye.y - p[i].y) / (eye.x - p[i].x);
		q[i] = Point<double>(0, p[i].y - slope * p[i].x);
		ans += dist(p[i], p[i+1]);
		// printf("q %d = %lf %lf\n",i,q[i].x,q[i].y);
	}

	int pos = n-1;
	double mn = (double)(eye.y - p[n-1].y) / (eye.x - p[n-1].x);
	for(int i=n-2;i>=1;i--) {
		double slope = (double)(eye.y - p[i].y) / (eye.x - p[i].x);
		// cout << "slope: " << slope << endl;
		if(slope - mn > eps) {
			// cout << "yo: " << i << endl;
			ans -= dist(p[i], p[i+1]);
		}
		else {
			// printf("\ti = %d: pos = %d\n",i,pos);
			auto seg = segInter(eye, q[pos], p[i], p[i+1]);
			// printf("\tintersect\n");
			// for(auto t : seg) cout << "\t" << t.x << " " << t.y << endl;
			if(seg.size() == 1) {
				ans -= dist(seg[0], p[i+1]);
			}
			mn = slope;
			pos = i;
		}
	}
	cout << fixed << setprecision(30) << ans << endl;
}