#include <bits/stdc++.h>
using namespace std;

using R = long double;
constexpr R pi = acos((R)-1), eps = 1e-10;

int sgn(R a) { return (a > eps) - (a < -eps); }
int sgn(R a, R b) { return sgn(a - b); }
using P = complex<R>;
istream& operator>>(istream& i, P& p) { R x, y; i >> x >> y; p = P(x, y); return i; }
ostream& operator<<(ostream& o, P p) { return o << fixed << setprecision(15) << real(p) << ' ' << imag(p); }
bool cmp(P p, P q) { return 2 * sgn(real(p), real(q)) + sgn(imag(p), imag(q)) < 0; }
bool eql(P p, P q) { return !cmp(p, q) and !cmp(q, p); }
R dot(P p, P q) { return real(conj(p) * q); }
R crs(P p, P q) { return imag(conj(p) * q); }
// -2: back, -1: cw, 0: on, 1: ccw, 2: front
int ccw(P p, P q) {
  int s = sgn(crs(p, q));
  if (s) return s;
  if (dot(p, q) < 0) return -2;
  if (dot(p, q - p) > 0) return 2;
  return 0;
}
int ccw(P o, P p, P q) { return ccw(p - o, q - o); }
struct L {
  P s, t;
  P vec() const { return t - s; }
  R abs() const { return std::abs(vec()); }
  R arg() const { return std::arg(vec()); }
};
int ccw(L s, P p) { return ccw(s.s, s.t, p); }

P proj(P p, L l) {
  P e = l.vec() / l.abs();
  return l.s + dot(p - l.s, e) * e;
}
P refl(P p, L l) { return (R)2 * proj(p, l) - p; }
R distPP(P p, P q) { return abs(q - p); }
R distPL(P p, L l) { return distPP(p, proj(p, l)); }
R distPS(P p, L s) {
  P q = proj(p, s);
  if (!ccw(s, q)) return distPP(p, q);
  return min(distPP(p, s.s), distPP(p, s.t));
}
R distLL(L l, L m) {
  if (sgn(crs(l.vec(), m.vec()))) return 0;
  return distPL(l.s, m);
}
R distLS(L l, L s) {
  if (ccw(l, s.s) * ccw(l, s.t) != 1) return 0;
  return min(distPL(s.s, l), distPL(s.t, l));
}
R distSS(L s, L t) {
  if (ccw(s, t.s) * ccw(s, t.t) <= 0 and ccw(t, s.s) * ccw(t, s.t) <= 0) return 0;
  return min({distPS(s.s, t), distPS(s.t, t), distPS(t.s, s), distPS(t.t, s)});
}
P intxn(L l, L m) {
  assert(sgn(crs(l.vec(), m.vec())));
  return l.s + crs(m.s - l.s, m.vec()) / crs(l.vec(), m.vec()) * l.vec();
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  vector<P> p(n);
  for (auto&& e : p) {
    cin >> e;
  }
  p.resize(n + 2);
  p[n] = p[0];
  p[n + 1] = p[1];
  R res = 1e10;
  for (int i = 0; i < n; ++i) {
    res = min(res, distPL(p[i + 1], {p[i], p[i + 2]}) / 2);
  }
  cout << res << '\n';
}