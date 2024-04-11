#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

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
  int h, w, q;
  cin >> h >> w >> q;
  vector<string> s(h);
  for (auto&& e : s) {
    cin >> e;
  }
  auto $ = [&](int i, int j) {
    return i * w + j;
  };
  auto in = [&](int i, int j) {
    return 0 <= i and i < h and 0 <= j and j < w;
  };
  array<int, 4> di{1, 0, -1, 0};
  array<int, 4> dj{0, 1, 0, -1};
  dsu d(h * w);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (i and s[i - 1][j] == s[i][j]) {
        d.unite($(i - 1, j), $(i, j));
      }
      if (j and s[i][j - 1] == s[i][j]) {
        d.unite($(i, j - 1), $(i, j));
      }
    }
  }
  vector dist(h, vector(w, -1));
  queue<pair<int, int>> que;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (d.size($(i, j)) >= 2) {
        dist[i][j] = 0;
        que.emplace(i, j);
      }
    }
  }
  while (not empty(que)) {
    auto [i, j] = que.front();
    que.pop();
    for (int k = 0; k < 4; ++k) {
      int ni = i + di[k], nj = j + dj[k];
      if (not in(ni, nj) or dist[ni][nj] != -1) continue;
      dist[ni][nj] = dist[i][j] + 1;
      que.emplace(ni, nj);
    }
  }
  for (int i = 0; i < h; ++i) {
    DEBUG(i, dist[i]);
  }
  while (q--) {
    int i, j;
    long long p;
    cin >> i >> j >> p;
    --i, --j;
    if (dist[i][j] == -1) {
      cout << s[i][j] << '\n';
      continue;
    }
    if (p <= dist[i][j]) {
      cout << s[i][j] << '\n';
    } else {
      int x = (p - dist[i][j]) & 1;
      cout << (char)(s[i][j] ^ x) << '\n';
    }
  }
}