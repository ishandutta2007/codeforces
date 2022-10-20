#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  struct P { int x, y; };
  V<P> p(3);
  for (int i = 0; i < 3; ++i) {
    cin >> p[i].x >> p[i].y;
  }
  sort(begin(p), end(p), [](const auto& lhs, const auto& rhs) { return lhs.x < rhs.x; });
  V<P> res;
  if (p[1].y < min(p[0].y, p[2].y)) {
    if (p[0].y > p[2].y) {
      for (int y = p[0].y; y > p[2].y; --y) {
        res.push_back({p[0].x, y});
      }
    }
    if (p[0].y < p[2].y) {
      for (int y = p[2].y; y > p[0].y; --y) {
        res.push_back({p[2].x, y});
      }
    }
    for (int x = p[0].x; x <= p[2].x; ++x) {
      res.push_back({x, min(p[0].y, p[2].y)});
    }
    for (int y = p[1].y; y < min(p[0].y, p[2].y); ++y) {
      res.push_back({p[1].x, y});
    }
  } else if (p[1].y > max(p[0].y, p[2].y)) {
    if (p[0].y > p[2].y) {
      for (int y = p[2].y; y < p[0].y; ++y) {
        res.push_back({p[2].x, y});
      }
    }
    if (p[0].y < p[2].y) {
      for (int y = p[0].y; y < p[2].y; ++y) {
        res.push_back({p[0].x, y});
      }
    }
    for (int x = p[0].x; x <= p[2].x; ++x) {
      res.push_back({x, max(p[0].y, p[2].y)});
    }
    for (int y = p[1].y; y > max(p[0].y, p[2].y); --y) {
      res.push_back({p[1].x, y});
    }
  } else {
    for (int x = p[0].x; x < p[1].x; ++x) {
      res.push_back({x, p[0].y});
    }
    for (int x = p[2].x; x > p[1].x; --x) {
      res.push_back({x, p[2].y});
    }
    for (int y = min(p[0].y, p[2].y); y <= max(p[0].y, p[2].y); ++y) {
      res.push_back({p[1].x, y});
    }
  }
  int n = res.size();
  cout << n << '\n';
  for (int i = 0; i < n; ++i) {
    cout << res[i].x << ' ' << res[i].y << '\n';
  }
}