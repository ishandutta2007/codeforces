#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e5;

struct pt {
  int x, y;

  pt(int x = 0, int y = 0) : x(x), y(y) {
  }

  long long operator*(const pt& o) const {
    return (long long) x * o.y - (long long) y * o.x;
  }

  double len() {
    return sqrt((long long) x * x + (long long) y * y);
  }

  bool operator<(const pt& o) const {
    return x < o.x || (x == o.x && y < o.y);
  }

  pt operator-(const pt& o) const {
    return pt(x - o.x, y - o.y);
  }
};

vector<pt> convex_hull(vector<pt> ps) {
  sort(ps.begin(), ps.end());
  vector<pt> h;
  for (int rot = 0; rot < 2; ++rot) {
    int lim = h.size();
    for (pt p : ps) {
      while ((int) h.size() > lim + 1 && (h[h.size() - 1] - h[h.size() - 2]) * (p - h[h.size() - 2]) <= 0) {
        h.pop_back();
      }
      h.push_back(p);
    }
    h.pop_back();
    reverse(ps.begin(), ps.end());
  }
  return h;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pt> p;
  for (int i = 0; i < n; ++i) {
    int x, y, v;
    cin >> x >> y >> v;
    if (x - v >= 0) {
      p.emplace_back(x - v, y);
    } else {
      p.emplace_back(0, max(0, y - (v - x)));
      p.emplace_back(0, min(MAX, y + (v - x)));
    }
    if (x + v <= MAX) {
      p.emplace_back(x + v, y);
    } else {
      p.emplace_back(MAX, max(0, y - (v + x - MAX)));
      p.emplace_back(MAX, min(MAX, y + (v + x - MAX)));
    }
    if (y - v >= 0) {
      p.emplace_back(x, y - v);
    } else {
      p.emplace_back(max(0, x - (v - y)), 0);
      p.emplace_back(min(MAX, x + (v - y)), 0);
    }
    if (y + v <= MAX) {
      p.emplace_back(x, y + v);
    } else {
      p.emplace_back(max(0, x - (v + y - MAX)), MAX);
      p.emplace_back(min(MAX, x + (v + y - MAX)), MAX);
    }
  }
  p = convex_hull(p);
  int m = p.size();
  double ans = 0;
  int who = -1;
  for (int i = 0; i < m; ++i) {
    pt a = p[i], b = p[(i + 1) % m], c = p[(i + 2) % m];
    double r = (b - a).len() * (c - a).len() * (c - b).len() / ((b - a) * (c - a));
    if (ans < r) {
      ans = r;
      who = i;
    }
  }
  for (int i = 0; i < 3; ++i) {
    cout << p[(who + i) % m].x << " " << p[(who + i) % m].y << "\n";
  }
  return 0;
}