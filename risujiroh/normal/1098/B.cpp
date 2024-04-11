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
  map<char, int> c2i{{'A', 0}, {'G', 1}, {'C', 2}, {'T', 3}};
  array<char, 4> i2c{'A', 'G', 'C', 'T'};
  int n, m; cin >> n >> m;
  VV<> a; assign(a, n, m, 0);
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    char c; cin >> c;
    a[i][j] = c2i[c];
  }
  auto row = [&](int i, int x, int y, bool f = false) -> int {
    int res = m, curr = 0;
    for (int j = 0; j < m; ++j) {
      curr += a[i][j] != (j & 1 ? y : x);
    }
    res = min(res, curr);
    if (f) return res;
    curr = 0;
    for (int j = 0; j < m; ++j) {
      curr += a[i][j] != (j & 1 ? x : y);
    }
    res = min(res, curr);
    return res;
  };
  auto col = [&](int j, int x, int y, bool f = false) -> int {
    int res = n, curr = 0;
    for (int i = 0; i < n; ++i) {
      curr += a[i][j] != (i & 1 ? y : x);
    }
    res = min(res, curr);
    if (f) return res;
    curr = 0;
    for (int i = 0; i < n; ++i) {
      curr += a[i][j] != (i & 1 ? x : y);
    }
    res = min(res, curr);
    return res;
  };
  int mn = n * m;
  for (int x = 0; x < 4; ++x) for (int y = x + 1; y < 4; ++y) {
    set<int> s{x, y};
    int z = 0, w = 0;
    while (s.count(z)) ++z;
    s.insert(z);
    while (s.count(w)) ++w;
    int curr = 0;
    for (int i = 0; i < n; ++i) {
      curr += i & 1 ? row(i, z, w) : row(i, x, y);
    }
    mn = min(mn, curr);
    curr = 0;
    for (int j = 0; j < m; ++j) {
      curr += j & 1 ? col(j, z, w) : col(j, x, y);
    }
    mn = min(mn, curr);
  }
  for (int x = 0; x < 4; ++x) for (int y = x + 1; y < 4; ++y) {
    set<int> s{x, y};
    int z = 0, w = 0;
    while (s.count(z)) ++z;
    s.insert(z);
    while (s.count(w)) ++w;
    int curr = 0;
    for (int i = 0; i < n; ++i) {
      curr += i & 1 ? row(i, z, w) : row(i, x, y);
    }
    if (curr == mn) {
      VV<> res; assign(res, n, m, 0);
      for (int i = 0; i < n; ++i) {
        int u = i & 1 ? z : x, v = i & 1 ? w : y;
        int uv = row(i, u, v, true), vu = row(i, v, u, true);
        if (uv < vu) {
          for (int j = 0; j < m; ++j) {
            res[i][j] = j & 1 ? v : u;
          }
        } else {
          for (int j = 0; j < m; ++j) {
            res[i][j] = j & 1 ? u : v;
          }
        }
      }
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          cout << i2c[res[i][j]];
        }
        cout << '\n';
      }
      return 0;
    }
    curr = 0;
    for (int j = 0; j < m; ++j) {
      curr += j & 1 ? col(j, z, w) : col(j, x, y);
    }
    if (curr == mn) {
      VV<> res; assign(res, n, m, 0);
      for (int j = 0; j < m; ++j) {
        int u = j & 1 ? z : x, v = j & 1 ? w : y;
        int uv = col(j, u, v, true), vu = col(j, v, u, true);
        if (uv < vu) {
          for (int i = 0; i < n; ++i) {
            res[i][j] = i & 1 ? v : u;
          }
        } else {
          for (int i = 0; i < n; ++i) {
            res[i][j] = i & 1 ? u : v;
          }
        }
      }
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          cout << i2c[res[i][j]];
        }
        cout << '\n';
      }
      return 0;
    }
  }
}