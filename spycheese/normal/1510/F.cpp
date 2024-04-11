#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;
const double DINF = numeric_limits<double>::infinity();
const double PI = acos(-1.0);

struct Vec2 {
  ll x, y;

  Vec2 operator + (Vec2 const& b) const { return {x + b.x, y + b.y}; }
  Vec2 operator - (Vec2 const& b) const { return {x - b.x, y - b.y}; }
};
ll dot(Vec2 const& a, Vec2 const& b) { return a.x * b.x + a.y * b.y; }
ll cross(Vec2 const& a, Vec2 const& b) { return a.x * b.y - a.y * b.x; }
ll length2(Vec2 const& a) { return dot(a, a); }
double length(Vec2 const& a) { return sqrt(double(length2(a))); }

struct DVec2 {
  double x, y;

  DVec2 operator + (DVec2 const& b) const { return {x + b.x, y + b.y}; }
  DVec2 operator - (DVec2 const& b) const { return {x - b.x, y - b.y}; }
};
double dot(DVec2 const& a, DVec2 const& b) { return a.x * b.x + a.y * b.y; }
double cross(DVec2 const& a, DVec2 const& b) { return a.x * b.y - a.y * b.x; }
double length2(DVec2 const& a) { return dot(a, a); }
double length(DVec2 const& a) { return sqrt(double(length2(a))); }

int n;
double totalL;
vector<Vec2> ps;
set<ipair> vis;
vector<double> per;
double ans = 0;

double calc(int i1, int i2) {
  if (i1 == i2) return 0;
  double l;
  if (i2 > i1)
    l = per[i1] + (per[n] - per[i2]);
  else
    l = per[i1] - per[i2];
  l = totalL - l;
  double d = length(ps[i1] - ps[i2]);
  if (d >= l) assert(0);

  double rx = l / 2;
  double ry = sqrt(max<double>(0, rx * rx - (d * d) / 4));

  DVec2 w1 = {
    (double)dot(ps[i1] - ps[i2], ps[i1] - ps[(i1 + n - 1) % n]),
    (double)cross(ps[i1] - ps[i2], ps[i1] - ps[(i1 + n - 1) % n])
  };
  DVec2 u1 = {
    (double)dot(ps[i1] - ps[i2], ps[(i1 + 1) % n] - ps[i1]),
    (double)cross(ps[i1] - ps[i2], ps[(i1 + 1) % n] - ps[i1])
  };

  DVec2 w2 = {
    (double)dot(ps[i1] - ps[i2], ps[i2] - ps[(i2 + 1) % n]),
    (double)cross(ps[i1] - ps[i2], ps[i2] - ps[(i2 + 1) % n])
  };
  DVec2 u2 = {
    (double)dot(ps[i1] - ps[i2], ps[(i2 + n - 1) % n] - ps[i2]),
    (double)cross(ps[i1] - ps[i2], ps[(i2 + n - 1) % n] - ps[i2])
  };

  DVec2 o = {
    (double)-dot(ps[i1] - ps[i2], ps[i1] + ps[i2]) * 0.5 / length(ps[i1] - ps[i2]),
    (double)-cross(ps[i1] - ps[i2], ps[i1] + ps[i2]) * 0.5 / length(ps[i1] - ps[i2]),
  };

  w1.x /= rx; w1.y /= ry;
  w2.x /= rx; w2.y /= ry;
  u1.x /= rx; u1.y /= ry;
  u2.x /= rx; u2.y /= ry;
  o.x /= rx; o.y /= ry;

  double px = d / 2 / rx;

  double res = 0;

  auto its = [](DVec2 const& p, DVec2 const& v) -> DVec2 {
    double a = length2(v);
    double b2 = dot(p, v);
    double c = length2(p) - 1;
    double d = b2 * b2 - a * c;
    d = sqrt(max<double>(d, 0));
    double t = max((-b2 + d) / a, (-b2 - d) / a);
    return {p.x + t * v.x, p.y + t * v.y};
  };

  DVec2 al = its({px, 0}, u1);
  DVec2 ar = its({px, 0}, w1);
  DVec2 bl = its({-px, 0}, w2);
  DVec2 br = its({-px, 0}, u2);

  DVec2 pl = (al.x < bl.x ? bl : al);
  DVec2 pr = (ar.x < br.x ? ar : br);
  if (pl.x >= pr.x) return 0;

  res += cross(pr - o, pl - o) / 2;

  double ang = acos(pl.x) - acos(pr.x);
  res += ang / 2;
  res -= cross(pr, pl) / 2;

  return res * rx * ry;
}

void go(int v1, int v2) {
  if (vis.count({v1, v2})) return;
  vis.insert({v1, v2});
  double cur = calc(v1, v2);
  ans += cur;
  if (cur != 0.0)
    for (int i = -2; i <= 2; ++i)
      for (int j = -2; j <= 2; ++j)
        go((v1 + i + n) % n, (v2 + j + n) % n);
}

int main() {
  cin >> n >> totalL;
  ps.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> ps[i].x >> ps[i].y;

  per.push_back(0);
  for (int i = 0; i < n; ++i)
    per.push_back(per.back() + length(ps[i] - ps[(i + 1) % n]));

  for (int i = 0; i < n; ++i)
    go(0, i);
  printf("%.10f\n", ans);
}