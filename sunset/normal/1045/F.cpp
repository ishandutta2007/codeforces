#include <bits/stdc++.h>

using namespace std;

struct point_t {
  int x, y, id;

  point_t() {
  }

  point_t(int x, int y):x(x), y(y) {
  }

  point_t(int x, int y, int id):x(x), y(y), id(id) {
  }

  bool operator < (const point_t &b) const {
    return x < b.x || (x == b.x && y < b.y);
  }

  point_t operator - (const point_t &b) const {
    return point_t(x - b.x, y - b.y);
  }

  long long operator * (const point_t &b) const {
    return (long long)x * b.y - (long long)y * b.x;
  }
};

vector<point_t> convex_hull(vector<point_t> points) {
  sort(points.begin(), points.end());
  vector<point_t> hull;
  for (int iter = 0; iter < 2; ++iter) {
    int limit = hull.size();
    for (auto p : points) {
      while (hull.size() > limit + 1 && (hull[hull.size() - 1] - hull[hull.size() - 2]) * (p - hull[hull.size() - 2]) <= 0) {
        hull.pop_back();
      }
      hull.push_back(p);
    }
    hull.pop_back();
    reverse(points.begin(), points.end());
  }
  return hull;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<point_t> p(n);
  bool origin = false;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &p[i].x, &p[i].y);
    if (!p[i].x && !p[i].y) {
      origin = true;
    }
    p[i].id = i;
  }
  if (!origin) {
    p.emplace_back(0, 0, n++);
  }
  vector<point_t> hull = convex_hull(p);
  for (auto p : hull) {
    if ((p.x & 1) || (p.y & 1)) {
      puts("Ani");
      return 0;
    }
  }
  {
    vector<bool> ban(n);
    for (int i = 1; i < hull.size(); i += 2) {
      ban[hull[i].id] = true;
    }
    vector<point_t> q;
    for (int i = 0; i < n; ++i) {
      if (!ban[i]) {
        q.push_back(p[i]);
      }
    }
    q = convex_hull(q);
    for (auto p : q) {
      if ((p.x & 1) || (p.y & 1)) {
        puts("Ani");
        return 0;
      }
    }
  }
  {
    vector<bool> ban(n);
    for (int i = 2; i < hull.size(); i += 2) {
      ban[hull[i].id] = true;
    }
    vector<point_t> q;
    for (int i = 0; i < n; ++i) {
      if (!ban[i]) {
        q.push_back(p[i]);
      }
    }
    q = convex_hull(q);
    for (auto p : q) {
      if ((p.x & 1) || (p.y & 1)) {
        puts("Ani");
        return 0;
      }
    }
  }
  puts("Borna");
  return 0;
}