#include <cmath>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
class point2d {
public:
	double x, y;
	point2d() : x(0), y(0) {};
	point2d(double x_, double y_) : x(x_), y(y_) {};
	bool operator==(const point2d& p) { return x == p.x && y == p.y; }
	bool operator!=(const point2d& p) { return x != p.x || y != p.y; }
	point2d& operator+=(const point2d& p) { x += p.x; y += p.y; return *this; }
	point2d& operator-=(const point2d& p) { x -= p.x; y -= p.y; return *this; }
	point2d& operator*=(const double v) { x *= v; y *= v; return *this; }
	point2d operator+(const point2d& p) const { return point2d(*this) += p; }
	point2d operator-(const point2d& p) const { return point2d(*this) -= p; }
	point2d operator*(const double v) const { return point2d(*this) *= v; }
	double norm() const { return x * x + y * y; }
	double abs() const { return std::sqrt(x * x + y * y); }
	double dot(const point2d& p) const { return x * p.x + y * p.y; }
	double cross(const point2d& p) const { return x * p.y - y * p.x; }
	int ccw(const point2d& p1, const point2d& p2) {
		// RETURNS: P0 -> P1 -> P2 IS COLLINEAR --> ((P0, P1, P2) IS CENTER --> (2, -2, 0)), COUNTER-CLOCKWISE --> 1, CLOCKWISE --> -1
		point2d pr1 = p1 - point2d(*this);
		point2d pr2 = p2 - point2d(*this);
		if (pr1.cross(pr2) != 0) return pr1.cross(pr2) > 0 ? 1 : -1;
		if (pr1.dot(pr2) < 0) return 2;
		return pr1.norm() < pr2.norm() ? -2 : 0;
	}
};
class segment2d {
public:
	point2d p1, p2;
	segment2d() : p1(point2d()), p2(point2d()) {};
	segment2d(const point2d& p1_, const point2d& p2_) : p1(p1_), p2(p2_) {};
	double norm() const { return (p1 - p2).norm(); }
	double abs() const { return (p1 - p2).abs(); }
};
double distance(const point2d& p, const segment2d& s) {
	double d1 = (p - s.p1).norm();
	double d2 = (p - s.p2).norm();
	double d0 = s.norm();
	if (d0 + d1 < d2 || d0 + d2 < d1) return std::sqrt(std::min(d1, d2));
	return std::abs((p - s.p1).cross(s.p2 - s.p1)) / std::sqrt(d0);
}
int contain(const std::vector<point2d>& v, const point2d& p) {
	// (IN POLYGON, ON THE EDGE, OUT OF POLYGON) = (1, 0, -1)
	int ans = -1;
	for (int i = 0; i < v.size(); ++i) {
		point2d p1 = v[i] - p;
		point2d p2 = v[(i + 1) % v.size()] - p;
		if (p1.x > p2.x) std::swap(p1, p2);
		if (p1.x <= 0 && 0 < p2.x && p1.cross(p2) < 0) ans *= -1;
		if (p1.cross(p2) == 0 && p1.dot(p2) <= 0) return 0;
	}
	return ans;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n; point2d c;
	cin >> n >> c.x >> c.y;
	vector<point2d> v(n);
	double pr = -1.0e+99;
	for (int i = 0; i < n; ++i) {
		cin >> v[i].x >> v[i].y;
		double d = (v[i] - c).norm();
		pr = max(pr, d);
	}
	double pl = 1.0e+99;
	for (int i = 0; i < n; ++i) {
		pl = min(pl, distance(c, segment2d(v[i], v[i + 1 != n ? i + 1 : 0])));
	}
	if (contain(v, c) == 1) pl = 0.0;
	cout << fixed << setprecision(15) << (pr - pl * pl) * acos(-1) << '\n';
	return 0;
}