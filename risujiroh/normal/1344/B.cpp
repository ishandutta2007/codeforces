#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class It> auto rle(It first, It last) {
  vector<pair<decltype(*first), int>> res;
  for (; first != last; ++first) {
    if (res.empty() or res.back().first != *first) {
      res.emplace_back(*first, 1);
    } else {
      ++res.back().second;
    }
  }
  return res;
}

struct dsu {
  int cc;
  vector<int> p, sz;
  dsu(int n = 0) : cc(n), p(n, -1), sz(n, 1) {}
  int root(int v) const {
    while (p[v] != -1) v = p[v];
    return v;
  }
  bool unite(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return false;
    --cc;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
    return true;
  }
  bool same(int u, int v) const { return root(u) == root(v); }
  int size(int v) const { return sz[root(v)]; }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (auto&& e : s) {
    cin >> e;
  }
  vector ok(n, vector(m, true));
  for (int i = 0; i < n; ++i) {
    auto v = rle(begin(s[i]), end(s[i]));
    int cnt = 0;
    for (auto [c, l] : v) {
      cnt += c == '#';
    }
    if (cnt >= 2) {
      cout << "-1\n";
      exit(0);
    }
    if (cnt) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == '.') {
          ok[i][j] = false;
        }
      }
    }
  }
  for (int j = 0; j < m; ++j) {
    string t;
    for (int i = 0; i < n; ++i) {
      t += s[i][j];
    }
    int cnt = 0;
    for (auto [c, l] : rle(begin(t), end(t))) {
      cnt += c == '#';
    }
    if (cnt >= 2) {
      cout << "-1\n";
      exit(0);
    }
    if (cnt) {
      for (int i = 0; i < n; ++i) {
        if (s[i][j] == '.') {
          ok[i][j] = false;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    bool any = false;
    for (int j = 0; j < m; ++j) {
      if (ok[i][j]) {
        any = true;
        break;
      }
    }
    if (not any) {
      cout << "-1\n";
      exit(0);
    }
  }
  for (int j = 0; j < m; ++j) {
    bool any = false;
    for (int i = 0; i < n; ++i) {
      if (ok[i][j]) {
        any = true;
        break;
      }
    }
    if (not any) {
      cout << "-1\n";
      exit(0);
    }
  }
  dsu d(n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] != '#') continue;
      if (i + 1 < n and s[i + 1][j] == '#') {
        d.unite(i * m + j, (i + 1) * m + j);
      }
      if (j + 1 < m and s[i][j + 1] == '#') {
        d.unite(i * m + j, i * m + (j + 1));
      }
    }
  }
  set<int> se;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '#') {
        se.insert(d.root(i * m + j));
      }
    }
  }
  cout << size(se) << '\n';
}