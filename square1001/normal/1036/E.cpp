#include <map>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class point2d {
public:
	double x, y;
	point2d() : x(0), y(0) {};
	point2d(double x_, double y_) : x(x_), y(y_) {};
	bool operator<(const point2d& p) const { return x != p.x ? x < p.x : y < p.y; }
	bool operator==(const point2d& p) const { return x == p.x && y == p.y; }
	bool operator!=(const point2d& p) const { return x != p.x || y != p.y; }
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
	int ccw(const point2d& p1, const point2d& p2) const {
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
bool intersect(const segment2d& s1, const segment2d& s2) {
	return s1.p1.ccw(s1.p2, s2.p1) * s1.p1.ccw(s1.p2, s2.p2) <= 0 && s2.p1.ccw(s2.p2, s1.p1) * s2.p1.ccw(s2.p2, s1.p2) <= 0;
}
point2d intersect_point(const segment2d &s1, const segment2d &s2) {
	point2d base = s2.p2 - s2.p1;
	double d1 = std::abs(base.cross(s1.p1 - s2.p1));
	double d2 = std::abs(base.cross(s1.p2 - s2.p1));
	return s1.p1 + (s1.p2 - s1.p1) * (d1 / (d1 + d2));
}
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	int N;
	cin >> N;
	vector<segment2d> S(N);
	for (int i = 0; i < N; ++i) {
		cin >> S[i].p1.x >> S[i].p1.y >> S[i].p2.x >> S[i].p2.y;
	}
	map<pair<long long, long long>, int> d;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (intersect(S[i], S[j])) {
				point2d p = intersect_point(S[i], S[j]);
				long long px = abs(p.x) + 0.5, py = abs(p.y) + 0.5;
				if (p.x < 0) px *= -1;
				if (p.y < 0) py *= -1;
				if (abs(px - p.x) <= 1.0e-7 && abs(py - p.y) <= 1.0e-7) {
					++d[make_pair(px, py)];
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		int g = gcd(abs(S[i].p1.x - S[i].p2.x), abs(S[i].p1.y - S[i].p2.y));
		ans += g + 1;
	}
	for (pair<pair<long long, long long>, int> i : d) {
		int b = 1;
		while (b * (b - 1) / 2 < i.second) ++b;
		ans -= b - 1;
	}
	cout << ans << endl;
	return 0;
}