#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld pi = acos(-1);

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

  point_t operator * (const ld &b) const {
    return point_t(x * b, y * b);
  }

  point_t operator / (const ld &b) const {
    return point_t(x / b, y / b);
  }

  ld operator * (const point_t &b) const {
    return x * b.y - y * b.x;
  }
};

point_t intersect(point_t p0, point_t v0, point_t p1, point_t v1) {
  return p0 + v0 * ((p1 - p0) * v1 / (v0 * v1));
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector<point_t> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].x >> p[i].y;
  }
  reverse(p.begin(), p.end());
  p.push_back(p[0]);
  vector<ld> sum(n + 1);
  for (int i = 0; i < n; ++i) {
    sum[i + 1] = sum[i] + p[i] * p[i + 1];
  }
  while (m--) {
    point_t q;
    cin >> q.x >> q.y;

    auto check = [&](ld angle) {
      point_t v(cos(angle), sin(angle));
      int left, right;

      auto query = [&](bool sign, bool left) {
        int l = 1, r = n - 1, result = -1;
        while (l <= r) {
          int mid = l + r >> 1;
          if ((v * (p[mid] - q) <= 0) == sign) {
            result = mid;
            if (left) {
              r = mid - 1;
            } else {
              l = mid + 1;
            }
          } else {
            if ((p[0] - q) * (p[mid] - q) > 0) {
              l = mid + 1;
            } else {
              r = mid - 1;
            }
          }
        }
        return result;
      };

      if (v * (p[0] - q) > 0) {
        left = query(true, true);
        right = query(true, false);
      } else {
        left = query(false, true);
        right = query(false, false);
      }
      ld area = sum[right] - sum[left];
      point_t x = intersect(q, v, p[left - 1], p[left] - p[left - 1]);
      point_t y = intersect(q, v, p[right], p[right + 1] - p[right]);
      area += x * p[left];
      area += p[right] * y;
      area += y * x;
      if (v * (p[0] - q) > 0) {
        return area * 2 - sum[n];
      } else {
        return sum[n] - area * 2;
      }
    };

    bool sign = check(0) < check(pi);
    ld l = 0, r = pi;
    for (int tt = 0; tt < 50; ++tt) {
      ld mid = (l + r) / 2;
      if ((check(mid) >= 0) == sign) {
        r = mid;
      } else {
        l = mid;
      }
    }
    printf("%.20lf\n", (double)l);
  }
  return 0;
}