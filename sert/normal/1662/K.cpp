#include <bits/stdc++.h>
using namespace std;

using ld = double;

struct pt {
  ld x, y;
  explicit pt(ld x = 0, ld y = 0): x(x), y(y) {};
  friend istream& operator>>(istream &fi, pt &p) { fi >> p.x >> p.y; return fi; }
  friend ostream& operator<<(ostream &fo, const pt &p) { fo << p.x << " " << p.y; return fo; }
  ld len() const { return sqrt(x * x + y * y); }
  ld operator%(const pt &p) const { return x * p.x + y * p.y; }
  pt operator-(const pt &p) const { return pt(x - p.x, y - p.y); }
  pt operator+(const pt &p) const { return pt(x + p.x, y + p.y); }
  pt operator*(ld f) const { return pt(x * f, y * f); }
  ld operator*(const pt &a) const { return x * a.y - y * a.x; }
};

pt intersecCircles(const pt &o1, ld r1, const pt &o2, ld r2, const pt &check) {
  ld d = (o1 - o2).len();
  ld base = (r1 * r1 + d * d - r2 * r2) / 2 / d;
  pt b = o1 + (o2 - o1) * (base / d);
  ld h = sqrt(r1 * r1 - base * base);

  pt mv = pt(o2.y - o1.y, o1.x - o2.x);
  pt res = b + mv * (h / d);
  if ((check - res).len() < 1e-9) res = b - mv * (h / d);
  return res;
}

bool isAngleGE120(const pt &p, const pt &a, const pt &b) {
  return ((a - p) % (b - p)) / (a - p).len() / (b - p).len() < -0.5;
}

int sign(ld x) {
  if (x < -1e-9) return -1;
  if (x > 1e-9) return 1;
  return 0;
}

pair<pt, ld> getCircle(const pt &a, const pt &b, const pt &check) {
  ld h = 1.0 / sqrt(3) / 2;
  pt mid = (a + b) * 0.5;
  pt mv = pt(b.y - a.y , a.x - b.x);
  pt o = mid + mv * h;
  if (sign((o - a) * (b - a)) == sign((check - a) * (b - a))) {
    o = mid - mv * h;
  }
  return {o, (a - o).len()};
}

ld f_(const pt &a, const pt &b, const pt &c) {
  if ((a - b).len() < 1e-9 || (a - c).len() < 1e-9 || (c - b).len() < 1e-9) {
    return (a - b).len() + (a - c).len() + (b - c).len();
  }
  if (isAngleGE120(a, b, c)) return (a - b).len() + (a - c).len();
  if (isAngleGE120(b, a, c)) return (b - a).len() + (b - c).len();
  if (isAngleGE120(c, b, a)) return (c - a).len() + (c - b).len();

  pt o1, o2;
  ld r1, r2;
  tie(o1, r1) = getCircle(a, c, b);
  tie(o2, r2) = getCircle(b, a, c);
  pt mid = intersecCircles(o1, r1, o2, r2, a);
//  cout << "mid: " << mid << "\n";
//
//  cout << (o1 - mid).len() << " = " << r1 << "\n";
//  cout << (o2 - mid).len() << " = " << r2 << "\n";
//
//  cout << (a - mid) % (b - mid) / (a - mid).len() / (b - mid).len() << "\n";
//  cout << (c - mid) % (b - mid) / (c - mid).len() / (b - mid).len() << "\n";
//  cout << (a - mid) % (c - mid) / (a - mid).len() / (c - mid).len() << "\n";

  return (a - mid).len() + (b - mid).len() + (c - mid).len();
}

ld f(const pt &a, const pt &b, const pt &c) {
  auto x = f_(a, b, c);
  if (x != x) {
    return (a - b).len() + (a - c).len() + (b - c).len();
    //exit(11);
  }
  return x;

  if ((b - a) * (c - a) > 0) return f_(a, c, b);
  return f_(a, b, c);
}

ld f(const pt &p, const pt &a, const pt &b, const pt &c) {
  return max({f(p, a, b), f(p, b, c), f(p, c, a)});
}

void solve(ld speed = 0.9, int it = 1000) {
  pt a, b, c;
  cin >> a >> b >> c;
//  cout << f(a, b, c) << "\n"; //
//  cout << f(a, c, b) << "\n";
//  cout << f(b, a, c) << "\n";
//  cout << f(b, c, a) << "\n"; //
//  cout << f(c, a, b) << "\n"; //
//  cout << f(c, b, a) << "\n";
//  return;

  vector<pt> mv;
  int sz = 34;
  for (int i = 0; i < sz; i++) {
    ld ang = atan2(0, -1) * 2 * i / sz;
    mv.push_back(pt(cos(ang), sin(ang)) * 50000);
  }

  pt bst(0, 0);
  double best = f(bst, a, b, c);
  while (it--) {
    pt bst_tmp = bst;
    auto best_tmp = best;
    for (const auto &dir : mv) {
      auto cur = bst + dir;
      auto val = f(cur, a, b, c);
      if (val < best_tmp) {
        best_tmp = val;
        bst_tmp = cur;
      }
    }

    bst = bst_tmp;
    best = best_tmp;

    for (auto &p : mv) p = p * speed;
  }

  cout << best << "\n";
}

#ifdef SERT
bool D = true;
#else
bool D = false;
#endif

int main() {
  cout.precision(D ? 10 : 8);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  if (D) {
    //test();
    freopen("../a.in", "r", stdin);
    t = 1;
  }
  //cin >> t;
  while (t--) {
    solve();
  }
}