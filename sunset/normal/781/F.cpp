#include <bits/stdc++.h>

using namespace std;

typedef double ld;

const int N = 234567;
const ld eps = 1e-9;

struct point_t {
  ld x, y;

  point_t(ld x = 0, ld y = 0):x(x), y(y) {
  }

  point_t operator + (const point_t &b) const {
    return point_t(x + b.x, y + b.y);
  }

  point_t operator - (const point_t &b) const {
    return point_t(x - b.x, y - b.y);
  }

  ld operator * (const point_t &b) const {
    return x * b.x + y * b.y;
  }

  point_t operator * (const ld &b) const {
    return point_t(x * b, y * b);
  }

  ld operator / (const point_t &b) const {
    if (fabs(b.x) > eps) {
      return x / b.x;
    } else {
      return y / b.y;
    }
  }

  point_t operator / (const ld &b) const {
    return point_t(x / b, y / b);
  }

  bool operator == (const point_t &b) const {
    return fabs(x - b.x) < eps && fabs(y - b.y) < eps;
  }

  point_t unit() {
    return point_t(x / abs(), y / abs());
  }

  ld abs() {
    return sqrt(x * x + y * y);
  }

  ld sqr() {
    return x * x + y * y;
  }
} points[N];

int n, m;
ld c;

point_t prep(point_t p) {
  return point_t(-p.y, p.x);
}

ld distance(point_t a, point_t b) {
  return (a - b).abs();
}

void go(int &x, point_t &p, ld length) {
  if (p == points[x + 1]) {
    ++x;
  }
  while (length > eps) {
    ld dist = min(length, distance(p, points[x + 1]));
    p = p + (points[x + 1] - points[x]).unit() * dist;
    if (p == points[x + 1]) {
      ++x;
    }
    length -= dist;
  }
}

bool check(ld limit) {
  vector<pair<ld, int>> event;
  int x = 0, y = 0;
  point_t px = points[0], py = points[0];
  go(y, py, c);
  ld remain = c;
  while (x != n) {
    ld length = min(remain, min(distance(px, points[x + 1]), distance(py, points[y + 1])));
    point_t s = py - px;
    go(x, px, length);
    go(y, py, length);
    point_t t = py - px;
    ld l = c - remain;
    ld r = c - remain + length;
    if (length > eps) {
      if (s == t) {
        if (s.abs() <= limit) {
          event.emplace_back(l + eps, 1);
          event.emplace_back(r - eps, -1);
        }
      } else {
        if (s.abs() <= limit && t.abs() <= limit) {
          event.emplace_back(l + eps, 1);
          event.emplace_back(r - eps, -1);
        } else {
          point_t v = prep(t - s);
          point_t p = v.unit() * (s * v / v.abs());
          if (p.abs() <= limit) {
            ld dist = sqrt(limit * limit - p.sqr());
            ld left = (p - (t - s).unit() * dist - s) / (t - s);
            ld right = (p + (t - s).unit() * dist - s) / (t - s);
            left = max((ld)0, min((ld)1, left));
            right = max((ld)0, min((ld)1, right));
            event.emplace_back(l + (r - l) * left + eps, 1);
            event.emplace_back(l + (r - l) * right - eps, -1);
          }
        }
      }
    }
    remain -= length;
    if (remain < eps) {
      remain = c;
    }
  }
  sort(event.begin(), event.end());
  int sum = 0;
  for (auto p : event) {
    sum += p.second;
    if (sum == m) {
      return true;
    }
  }
  return false;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    points[i] = points[i + n] = point_t(x, y);
  }
  for (int i = 0; i < n; ++i) {
    c += distance(points[i], points[i + 1]);
  }
  c /= m;
  ld l = 0, r = c;
  for (int tt = 0; tt < 50; ++tt) {
    ld mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%lf\n", r);
  return 0;
}