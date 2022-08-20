#include <bits/stdc++.h>

using namespace std;

struct point_t {
  int x, y, id, color;

  point_t() {
  }

  point_t(int x, int y):x(x), y(y) {
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
  vector<pair<int, int>> answer;
  vector<point_t> p(n);
  bool same = true;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].color);
    p[i].id = i;
    if (p[i].color != p[0].color) {
      same = false;
    }
  }
  if (same) {
    printf("%d\n", n - 1);
    for (int i = 1; i < n; ++i) {
      printf("%d %d\n", 0, i);
    }
    return 0;
  }

  vector<point_t> hull = convex_hull(p);
  int diff = 0;
  for (int i = 0; i < hull.size(); ++i) {
    if (hull[i].color != hull[(i + 1) % hull.size()].color) {
      ++diff;
    }
  }
  if (diff > 2) {
    puts("Impossible");
    return 0;
  }

  auto in_triangle = [&](point_t p, point_t a, point_t b, point_t c) {
    if (p.id == a.id || p.id == b.id || p.id == c.id) {
      return false;
    }
    int ab = (a - p) * (b - p) > 0, bc = (b - p) * (c - p) > 0, ca = (c - p) * (a - p) > 0;
    return ab == bc && bc == ca;
  };

  function<void(vector<point_t>, point_t, point_t, point_t)> solve = [&](vector<point_t> all, point_t a, point_t b, point_t c) {
    if (all.empty()) {
      return;
    }
    int p = -1;
    for (int i = 0; i < all.size(); ++i) {
      if (all[i].color == a.color) {
        p = i;
        break;
      }
    }
    if (~p) {
      point_t d = all[p];
      answer.emplace_back(a.id, d.id);
      vector<point_t> ab, bc, ca;
      for (auto p : all) {
        if (in_triangle(p, a, b, d)) {
          ab.push_back(p);
        }
        if (in_triangle(p, b, c, d)) {
          bc.push_back(p);
        }
        if (in_triangle(p, c, a, d)) {
          ca.push_back(p);
        }
      }
      solve(ab, b, a, d);
      solve(bc, d, b, c);
      solve(ca, c, a, d);
    } else {
      for (auto p : all) {
        answer.emplace_back(p.id, c.id);
      }
    }
  };
  
  if (!diff) {
    for (int i = 1; i < hull.size(); ++i) {
      answer.emplace_back(hull[i - 1].id, hull[i].id);
    }
    int middle = -1;
    for (int i = 0; i < n; ++i) {
      if (p[i].color != hull[0].color) {
        middle = i;
        break;
      }
    }
    for (int i = 0; i < hull.size(); ++i) {
      vector<point_t> all;
      for (int j = 0; j < n; ++j) {
        if (in_triangle(p[j], hull[i], hull[(i + 1) % hull.size()], p[middle])) {
          all.push_back(p[j]);
        }
      }
      solve(all, p[middle], hull[i], hull[(i + 1) % hull.size()]);
    }
  } else {
    int first = 0;
    while (first < hull.size() && hull[first].color == hull[0].color) {
      ++first;
    }
    rotate(hull.begin(), hull.begin() + first, hull.end());
    first = 0;
    while (first < hull.size() && hull[first].color == hull[0].color) {
      ++first;
    }
    for (int i = 1; i < first; ++i) {
      answer.emplace_back(hull[i - 1].id, hull[i].id);
      vector<point_t> all;
      for (int j = 0; j < n; ++j) {
        if (in_triangle(p[j], hull[first], hull[i], hull[i - 1])) {
          all.push_back(p[j]);
        }
      }
      solve(all, hull[first], hull[i], hull[i - 1]);
    }
    for (int i = first + 1; i < hull.size(); ++i) {
      answer.emplace_back(hull[i - 1].id, hull[i].id);
      vector<point_t> all;
      for (int j = 0; j < n; ++j) {
        if (in_triangle(p[j], hull[0], hull[i], hull[i - 1])) {
          all.push_back(p[j]);
        }
      }
      solve(all, hull[0], hull[i], hull[i - 1]);
    }
  }

  printf("%d\n", answer.size());
  for (auto p : answer) {
    printf("%d %d\n", p.first, p.second);
  }
  return 0;
}