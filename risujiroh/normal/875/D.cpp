#include <bits/stdc++.h>
using namespace std;

template <class T> struct disjoint_sparse_table {
  vector<vector<T>> t;
  disjoint_sparse_table(const vector<T>& v) : t(1, v) {
    for (int k = 1, n = v.size(); 1 << k < n; ++k) {
      t.push_back(v);
      for (int m = 1 << k; m < n; m += 1 << (k + 1)) {
        partial_sum(rend(v) - m, rend(v) - (m - (1 << k)),
                    rend(t[k]) - m, [](T a, T b) { return b * a; });
        partial_sum(begin(v) + m, begin(v) + min(m + (1 << k), n),
                    begin(t[k]) + m, multiplies<>());
      }
    }
  }
  T fold(int l, int r) const {
    assert(l < r);
    if (l == --r) return t[0][l];
    int k = __lg(l ^ r);
    return t[k][l] * t[k][r];
  }
};

struct node {
  int v = 0;
  node operator*(node b) const {
    return {v | b.v};
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  vector<node> v(n);
  for (int i = 0; i < n; ++i) {
    v[i] = {a[i]};
  }
  disjoint_sparse_table dst(v);
  vector<int> ord(n);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int i, int j) {
    return a[i] != a[j] ? a[i] > a[j] : i < j;
  });
  set<int> se;
  se.insert(-1);
  se.insert(n);
  auto res = (long long)n * (n + 1) / 2;
  for (int i : ord) {
    auto it = se.lower_bound(i);
    long long l = -1, r = -1;
    {
      int ng = *prev(it), ok = i;
      while (ok - ng > 1) {
        int mid = (ng + ok) / 2;
        ((dst.fold(mid, i + 1).v | a[i]) == a[i] ? ok : ng) = mid;
      }
      l = ok;
    }
    {
      int ok = i + 1, ng = *it + 1;
      while (ng - ok > 1) {
        int mid = (ok + ng) / 2;
        ((dst.fold(i, mid).v | a[i]) == a[i] ? ok : ng) = mid;
      }
      r = ok;
    }
    res -= (i - l + 1) * (r - i);
    se.insert(i);
  }
  cout << res << '\n';
}