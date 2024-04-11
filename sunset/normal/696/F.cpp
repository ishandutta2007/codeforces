#include <bits/stdc++.h>

using namespace std;

using ld = double;

struct pt {
  ld x, y;

  pt(ld x = 0, ld y = 0) : x(x), y(y) {
  }

  pt operator+(const pt& o) const {
    return pt(x + o.x, y + o.y);
  }
  
  pt operator-(const pt& o) const {
    return pt(x - o.x, y - o.y);
  }

  pt operator/(const ld& o) const {
    return pt(x / o, y / o);
  }

  ld operator*(const pt& o) const {
    return x * o.y - y * o.x;
  }

  ld len() const {
    return sqrt(x * x + y * y);
  }
};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pt> p(n * 3 + 1);
  for (int i = 0; i <= n * 3; ++i) {
    if (i < n) {
      cin >> p[i].x >> p[i].y;
    } else {
      p[i] = p[i - n];
    }
  }
  vector<pt> v(n * 3);
  for (int i = 0; i < n * 3; ++i) {
    v[i] = p[i + 1] - p[i];
  }
  auto dist = [&](pt q, int i) {
    return abs((q - p[i]) * v[i]) / v[i].len();
  };
  vector<vector<ld>> radius(n, vector<ld>(n, 1e9));
  vector<vector<pt>> point(n, vector<pt>(n));
  for (int st = 0; st < n; ++st) {
    int md = st;
    for (int ed = st; st == ed || v[st] * v[ed] > 0; ++ed) {
      while (md < ed && dist(p[md + 1], st) < dist(p[md + 1], ed)) {
        ++md;
      }
      if (md == ed) {
        radius[st][ed % n] = 0;
        point[st][ed % n] = p[md];
      } else {
        pt l = p[md], r = p[md + 1], mid = (l + r) / 2;
        for (int tt = 0; tt < 60; ++tt) {
          if (dist(mid, st) < dist(mid, ed)) {
            l = mid;
          } else {
            r = mid;
          }
          mid = (l + r) / 2;
        }
        radius[st][ed % n] = max(dist(mid, st), dist(mid, ed));
        point[st][ed % n] = mid;
      }
    }
  }
  ld ans = 1e9;
  pt foo, bar;
  for (int st = 0; st < n; ++st) {
    for (int ed = 0; ed < n; ++ed) {
      int st2 = (ed + 1) % n;
      int ed2 = (st + n - 1) % n;
      ld r = max(radius[st][ed], radius[st2][ed2]);
      if (r < ans) {
        ans = r;
        foo = point[st][ed];
        bar = point[st2][ed2];
      }
    }
  }
  cout << fixed << setprecision(9);
  cout << ans << "\n";
  cout << foo.x << " " << foo.y << "\n";
  cout << bar.x << " " << bar.y << "\n";
  return 0;
}