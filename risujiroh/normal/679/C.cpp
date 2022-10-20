#include <bits/stdc++.h>
using namespace std;

struct dsu {
  int cc;
  vector<int> p, sz, sum;
  dsu(int n = 0) : cc(n), p(n, -1), sz(n, 1), sum(n) {}
  int root(int v) {
    if (p[v] == -1) return v;
    return p[v] = root(p[v]);
  }
  bool unite(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return false;
    --cc;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
    sum[u] += sum[v];
    return true;
  }
  bool same(int u, int v) { return root(u) == root(v); }
  int size(int v) { return sz[root(v)]; }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<string> s(n, string(n, '.'));
  for (auto&& e : s) cin >> e;
  auto $ = [&](int i, int j) {
    return i * n + j;
  };
  auto in = [&](int i, int j) {
    return 0 <= i and i < n and 0 <= j and j < n;
  };
  int res = 0;
  dsu d(n * n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == 'X') continue;
      d.sum[$(i, j)] = 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == 'X') continue;
      if (i and s[i - 1][j] != 'X') {
        d.unite($(i - 1, j), $(i, j));
      }
      if (j and s[i][j - 1] != 'X') {
        d.unite($(i, j - 1), $(i, j));
      }
    }
  }
  bitset<250000> bs;
  for (int li = 0; li + k <= n; ++li) {
    for (int i = li; i < li + k; ++i) {
      for (int j = 0; j < k; ++j) {
        if (s[i][j] == 'X') continue;
        --d.sum[d.root($(i, j))];
      }
    }
    for (int lj = 0; lj + k <= n; ++lj) {
      static vector<int> v;
      v.clear();
      for (int i : {li - 1, li + k}) {
        for (int j = lj; j < lj + k; ++j) {
          if (not in(i, j) or s[i][j] == 'X') continue;
          int r = d.root($(i, j));
          if (bs[r]) continue;
          bs[r] = 1;
          v.push_back(r);
        }
      }
      for (int j : {lj - 1, lj + k}) {
        for (int i = li; i < li + k; ++i) {
          if (not in(i, j) or s[i][j] == 'X') continue;
          int r = d.root($(i, j));
          if (bs[r]) continue;
          bs[r] = 1;
          v.push_back(r);
        }
      }
      int cur = k * k;
      for (int r : v) {
        cur += d.sum[r];
        bs[r] = 0;
      }
      res = max(res, cur);
      if (lj + k == n) break;
      for (int i = li; i < li + k; ++i) {
        if (s[i][lj] == 'X') continue;
        ++d.sum[d.root($(i, lj))];
      }
      for (int i = li; i < li + k; ++i) {
        if (s[i][lj + k] == 'X') continue;
        --d.sum[d.root($(i, lj + k))];
      }
    }
    for (int i = li; i < li + k; ++i) {
      for (int j = n - k; j < n; ++j) {
        if (s[i][j] == 'X') continue;
        ++d.sum[d.root($(i, j))];
      }
    }
  }
  cout << res << '\n';
}