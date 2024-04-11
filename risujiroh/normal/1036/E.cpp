#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

const double eps = 1e-10;
const double inf = 1e+10;
const double pi = acos(-1.0);
int sgn(double a) { return a < -eps ? -1 : a > eps; }
using P = complex<double>;
namespace std {
  istream& operator>>(istream& i, P& p) { double x, y; i >> x >> y; p = P(x, y); return i; }
  ostream& operator<<(ostream& o, const P& p) { o << real(p) << ' ' << imag(p); return o; }
  bool operator<(const P& p, const P& q) { return sgn(real(p) - real(q)) ? sgn(real(p) - real(q)) < 0 : sgn(imag(p) - imag(q)) < 0; }
  bool operator>(const P& p, const P& q) { return q < p; }
  bool operator<=(const P& p, const P& q) { return !(p > q); }
  bool operator>=(const P& p, const P& q) { return !(p < q); }
}
bool eq(const P& p, const P& q) { return !(p < q) and !(p > q); }
double dot(const P& p, const P& q) { return real(conj(p) * q); }
double cross(const P& p, const P& q) { return imag(conj(p) * q); }

int ccw(P p0, P p1, P p2) {
  p1 -= p0, p2 -= p0;                         //             (1)
  if (sgn(cross(p1, p2)) > 0) return 1;       //
  if (sgn(cross(p1, p2)) < 0) return -1;      // (-2)---p0---(0)---p1---(2)
  if (sgn(dot(p1, p2) < 0)) return -2;        //
  if (sgn(norm(p1) - norm(p2)) < 0) return 2; //             (-1)
  return 0;
}

bool intSS(const P& p1, const P& p2, const P& q1, const P& q2) {
  return ccw(p1, p2, q1) * ccw(p1, p2, q2) <= 0 and ccw(q1, q2, p1) * ccw(q1, q2, p2) <= 0;
}

P intP(P p1, P p2, P q1, P q2) {
  q2 -= q1, p2 -= p1, q1 -= p1;
  return p1 + cross(q1, q2) / cross(p2, q2) * p2;
}

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> x1(n), y1(n), x2(n), y2(n); for (int i = 0; i < n; i++) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
  auto c = [](int x1, int y1, int x2, int y2) {
    int x = abs(x2 - x1), y = abs(y2 - y1);
    if (!x) return y + 1;
    if (!y) return x + 1;
    return __gcd(x, y) + 1;
  };
  lint res = 0;
  for (int i = 0; i < n; i++) res += c(x1[i], y1[i], x2[i], y2[i]);
  map<int, map<int, int> > mp;
  for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
    if (!intSS(P(x1[i], y1[i]), P(x2[i], y2[i]), P(x1[j], y1[j]), P(x2[j], y2[j]))) continue;
    P p = intP(P(x1[i], y1[i]), P(x2[i], y2[i]), P(x1[j], y1[j]), P(x2[j], y2[j]));
    int x = round(real(p)), y = round(imag(p));
    if (eq(p, P(x, y))) mp[x][y]++;
  }
  function<int(int)> d = [](int n) {
    return sqrt(1 + 8 * n) * 0.5;
  };
  for (auto&& i : mp) for (auto&& j : i.second) res -= d(j.second);
  cout << res << '\n';
}