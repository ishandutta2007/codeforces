#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  int q; cin >> q;
  V<> ql(q), qr(q); for (int i = 0; i < q; ++i) cin >> ql[i] >> qr[i], --ql[i];

  V<> res(q);
  VV<> v(n + 1);
  auto rec = [&](const auto& rec, int l, int r, const V<>& idx) -> void {
    if (r - l == 1) {
      for (int i : idx) {
        res[i] = a[l];
      }
      return;
    }
    int m = l + r >> 1;
    V<> idx_l, idx_m, idx_r;
    for (int i : idx) {
      if (qr[i] <= m) idx_l.push_back(i);
      else if (m <= ql[i]) idx_r.push_back(i);
      else idx_m.push_back(i);
    }
    rec(rec, l, m, idx_l);
    rec(rec, m, r, idx_r);
    V<>().swap(v[m]);
    for (int i = m; i < r; ++i) {
      v[i + 1] = v[i];
      int x = a[i];
      for (int e : v[i + 1]) {
        if (x == 0) break;
        x = min(x, x ^ e);
      }
      if (x) v[i + 1].push_back(x);
    }
    for (int i = m - 1; i >= l; --i) {
      v[i] = v[i + 1];
      int x = a[i];
      for (int e : v[i]) {
        if (x == 0) break;
        x = min(x, x ^ e);
      }
      if (x) v[i].push_back(x);
    }
    for (int i : idx_m) {
      auto w = v[ql[i]];
      for (int x : v[qr[i]]) {
        for (int e : w) {
          if (x == 0) break;
          x = min(x, x ^ e);
        }
        if (x) w.push_back(x);
      }
      for (int e : w) {
        res[i] = max(res[i], res[i] ^ e);
      }
    }
  };
  V<> idx(q);
  iota(begin(idx), end(idx), 0);
  rec(rec, 0, n, idx);
  for (int i = 0; i < q; ++i) {
    cout << res[i] << '\n';
  }
}