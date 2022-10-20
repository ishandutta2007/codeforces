#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class Key, class T> struct radix_heap {
  static_assert(is_integral<Key>::value, "");
  array<vector<pair<Key, T>>, sizeof(Key) * 8 + 1> v;
  Key last = 0;
  size_t sz = 0, ptr = 0;
  static int lg(Key a) { return a ? __lg(a) : -1; }
  void emplace(Key key, T val) {
    assert(key >= last);
    v[lg(key ^ last) + 1].emplace_back(key, val);
    ++sz;
  }
  void pull() {
    if (ptr < v[0].size()) return;
    v[0].clear(), ptr = 0;
    int i = 1;
    while (v[i].empty()) ++i;
    last = min_element(begin(v[i]), end(v[i]), [](auto a, auto b) {
      return a.first < b.first;
    })->first;
    for (auto e : v[i]) v[lg(e.first ^ last) + 1].push_back(e);
    v[i].clear();
  }
  pair<Key, T> top() { return pull(), v[0][ptr]; }
  void pop() { pull(), --sz, ++ptr; }
  bool empty() const { return sz == 0; }
};

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

auto chmin = [](auto&& a, auto b) { return b < a ? a = b, 1 : 0; };

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> pos(m);
  for (auto&& e : pos) {
    cin >> e;
  }
  sort(begin(pos), end(pos));
  pos.erase(unique(begin(pos), end(pos)), end(pos));
  m = size(pos);
  int g, r;
  cin >> g >> r;
  auto $ = [&](int v, int t) {
    return v * g + t;
  };
  vector d(m * g, inf<long long>);
  radix_heap<long long, int> rh;
  rh.emplace(d[$(0, 0)] = 0, $(0, 0));
  while (not rh.empty()) {
    auto [dv, v] = rh.top();
    rh.pop();
    if (dv != d[v]) {
      continue;
    }
    int i = v / g, t = v - i * g;
    if (i) {
      if (int nt = t + (pos[i] - pos[i - 1]); nt <= g) {
        int nv = $(i - 1, nt % g);
        if (chmin(d[nv], dv + (nt - t) + (t ? 0 : r))) {
          rh.emplace(d[nv], nv);
        }
      }
    }
    if (i + 1 < m) {
      if (int nt = t + (pos[i + 1] - pos[i]); nt <= g) {
        int nv = $(i + 1, nt % g);
        if (chmin(d[nv], dv + (nt - t) + (t ? 0 : r))) {
          rh.emplace(d[nv], nv);
        }
      }
    }
  }
  auto res = inf<long long>;
  for (int t = 0; t < g; ++t) {
    chmin(res, d[$(m - 1, t)]);
  }
  if (res == inf<long long>) {
    res = -1;
  } else {
    res -= r;
  }
  cout << res << '\n';
}