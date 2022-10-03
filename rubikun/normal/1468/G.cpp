#pragma GCC optimize("Ofast")

#include "bits/stdc++.h"
using namespace std;
using ll = long long;

using Real = double;
using Point = complex<Real>;
const Real EPS = 1e-8, PI = acos(-1);
inline bool eq(Real a, Real b) { return fabs(b - a) < EPS; }

ostream &operator<<(ostream &os, Point &p) {
  os << fixed << setprecision(3) << "{" << p.real() << " " << p.imag() << "}";
}

struct Line {
  Point a, b;
  Line() = default;
  Line(Point a, Point b) : a(a), b(b) {}
};

struct Segment : Line {
  Segment() = default;
  Segment(Point a, Point b) : Line(a, b) {}
};

Real cross(const Point &a, const Point &b) {
  return real(a) * imag(b) - imag(a) * real(b);
}

bool intersect(const Line &l, const Segment &s) {
  return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS;
}

Point crosspoint(const Line &l, const Line &m) {
  Real A = cross(l.b - l.a, m.b - m.a);
  Real B = cross(l.b - l.a, l.b - m.a);
  if (eq(abs(A), 0.0) and eq(abs(B), 0.0)) return m.a;
  return m.a + (m.b - m.a) * B / A;
}

using Segments = vector<Segment>;
using Lines = vector<Line>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll N, H;
  cin >> N >> H;
  vector<Point> P(N);
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    P[i] = Point(a, b);
  }
  Point eye = P.back();
  eye += Point(0, H);
  double ans = 0;
  Point Last = P.back();
  // cerr << "eye: " << eye << endl;
  for (int i = N - 2; i >= 0; i--) {
    // cerr << "---------" << i << "--------" << endl;
    Line l(eye, Last);
    Segment a(P[i], P[i + 1]);
    if (!eq(fabs(Last - P[i + 1]), 0) and !intersect(l, a)) continue;
    auto d1 = Last - eye;
    auto d2 = P[i + 1] - P[i];
    if (cross(d1, d2) <= -EPS) continue;
    Line b(P[i], P[i + 1]);
    Point p = eye;
    if (!eq(fabs(Last - P[i + 1]), 0))
      p = crosspoint(l, b);
    else
      p = Last;
    // cerr << Last << " " << P[i+1] << " " << P[i] << " " << p << endl;
    ans += fabs(p - P[i]);
    Last = P[i];
  }
  cout << fixed << setprecision(30) << ans << endl;
  return 0;
}