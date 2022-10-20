#include <bits/stdc++.h>
using namespace std;

template <class T> struct sparse_table {
  vector<vector<T>> t;
  sparse_table(const vector<T>& v = {}) : t{v} {
    for (int k = 1, n = size(v); 1 << k <= n; ++k) {
      t.emplace_back(n - (1 << k) + 1);
      for (int i = 0; i + (1 << k) <= n; ++i)
        t[k][i] = min(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);
    }
  }
  T fold(int l, int r) const {
    assert(l < r);
    int k = __lg(r - l);
    return min(t[k][l], t[k][r - (1 << k)]);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> h(n);
  for (auto&& e : h) cin >> e;
  h.insert(begin(h), 0);
  h.push_back(0);
  n += 2;
  vector<int> _r(n), _l(n);
  for (int i = 0; i < n; ++i) {
    _r[i] = h[i] + i;
    _l[i] = h[i] - i;
  }
  sparse_table r(_r), l(_l);
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    mx = max(mx, min(r.fold(i, n) - i, l.fold(0, i + 1) + i));
  }
  cout << mx << '\n';
}