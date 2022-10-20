#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct DisjointSparseTable {
  using T = int;
  static T op(const T& x, const T& y) { return min(x, y); }

  const int n;
  VV<T> t;
  template<class Itr> DisjointSparseTable(Itr first, Itr last) :
    n(distance(first, last)), t(__lg(n) + 1, V<T>(first, last)) {
    for (int k = 1; k < (int) t.size(); ++k) {
      for (int i0 = 1 << k; i0 < n; i0 += 1 << (k + 1)) {
        for (int i = i0 + 1; i < min(i0 + (1 << k), n); ++i) {
          t[k][i] = op(t[k][i - 1], t[k][i]);
        }
        for (int i = i0 - 2; i >= i0 - (1 << k); --i) {
          t[k][i] = op(t[k][i], t[k][i + 1]);
        }
      }
    }
  }
  T acc(int l, int r) const {
    assert(l < r);
    if (l == --r) return t[0][l];
    int k = __lg(l ^ r);
    return op(t[k][l], t[k][r]);
  }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  if (2 * *min_element(begin(a), end(a)) >= *max_element(begin(a), end(a))) {
    for (int i = 0; i < n; ++i) {
      cout << -1 << " \n"[i == n - 1];
    }
    return 0;
  }
  for (int i = 0; i < 2 * n; ++i) {
    a.push_back(a[i]);
  }
  V<> b(n);
  DisjointSparseTable dst(begin(a), end(a));
  for (int i = 0; i < n; ++i) {
    int ok = 1, ng = n + 1;
    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;
      (2 * dst.acc(i, i + mid) >= a[i] ? ok : ng) = mid;
    }
    b[i] = ok < n ? ok : 1e9;
  }
  for (int i = 0; i < 2 * n; ++i) {
    b.push_back(b[i]);
  }
  for (int i = 0; i < 3 * n; ++i) {
    b[i] += i;
  }
  DisjointSparseTable st(begin(b), end(b));
  for (int i = 0; i < n; ++i) {
    int res = st.acc(i, i + n) - i;
    cout << res << " \n"[i == n - 1];
  }
}