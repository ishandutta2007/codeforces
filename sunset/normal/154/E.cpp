#include <bits/stdc++.h>

using namespace std;

typedef double ld;

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

  bool operator < (const point_t &b) const {
    return x < b.x || (x == b.x && y < b.y);
  }

  ld operator * (const point_t &b) const {
    return x * b.y - y * b.x;
  }

  point_t unit() {
    return point_t(x / abs(), y / abs());
  }

  point_t perp() {
    return point_t(-y, x);
  }
  
  ld abs() {
    return sqrt(x * x + y * y);
  }

  ld sqr() {
    return x * x + y * y;
  }
};

vector<point_t> convex_hull(vector<point_t> points, ld radius) {
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

bool check(point_t p, point_t q, point_t r, ld radius) {
  point_t c = (p + q) / 2 + (q - p).perp().unit() * sqrt(radius * radius - (q - p).sqr() / 4);
  return (c - r).sqr() < radius * radius;
}

vector<point_t> check_circle(vector<point_t> points, ld radius) {
  int n = points.size();
  if (n <= 2) {
    return points;
  }
  vector<int> prev(n), next(n);
  for (int i = 0; i < n; ++i) {
    prev[i] = i - 1;
    next[i] = i + 1;
  }
  prev[0] = n - 1;
  next[n - 1] = 0;
  queue<int> q;
  vector<bool> ban(n);

  auto erase = [&](int x) {
    prev[next[x]] = prev[x];
    next[prev[x]] = next[x];
  };

  for (int i = 0; i < n; ++i) {
    if (check(points[prev[i]], points[next[i]], points[i], radius)) {
      ban[i] = true;
      q.push(i);
    }
  }

  while (!q.empty()) {
    int x = q.front();
    q.pop();
    erase(x);
    if (!ban[prev[x]] && check(points[prev[prev[x]]], points[next[x]], points[prev[x]], radius)) {
      ban[prev[x]] = true;
      q.push(prev[x]);
    }
    if (!ban[next[x]] && check(points[prev[x]], points[next[next[x]]], points[next[x]], radius)) {
      ban[next[x]] = true;
      q.push(next[x]);
    }
  }

  vector<point_t> result;
  for (int i = 0; i < n; ++i) {
    if (!ban[i]) {
      result.push_back(points[i]);
    }
  }
  return result;
}

ld solve(point_t p, point_t q, ld radius) {
  ld angle = asin((q - p).abs() / 2 / radius);
  return radius * radius * angle - radius * radius * sin(angle * 2) / 2;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, radius;
  cin >> n >> radius;
  vector<point_t> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].x >> p[i].y;
  }
  p = convex_hull(p, radius);
  p = check_circle(p, radius);
  n = p.size();
  ld answer = 0;
  for (int i = 0; i < n; ++i) {
    answer += p[i] * p[(i + 1) % n] / 2;
    answer += solve(p[i], p[(i + 1) % n], radius);
  }
  cout << fixed << setprecision(9) << answer << endl;
  return 0;
}