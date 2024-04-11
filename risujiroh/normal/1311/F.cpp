#include <bits/stdc++.h>
using namespace std;

template <class T> struct fenwick {
  const int n;
  vector<T> t;
  fenwick(int _n) : n(_n), t(n + 1) {}
  void add(int i, T a) { for (++i; i <= n; i += i & -i) t[i] += a; }
  T sum(int i) const {
    T s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
  }
  T sum(int l, int r) const { return sum(r) - sum(l); }
  int kth(T k) const {
    int i = 0;
    for (int w = 1 << __lg(n); w; w >>= 1)
      if (i + w <= n and t[i + w] <= k) k -= t[i += w];
    return i;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> x(n);
  for (auto&& e : x) {
    cin >> e;
  }
  vector<int> v(n);
  for (auto&& e : v) {
    cin >> e;
  }
  {
    vector<int> idx(n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](int i, int j) {
      return x[i] < x[j];
    });
    vector<int> nx(n), nv(n);
    for (int t = 0; t < n; ++t) {
      int i = idx[t];
      nx[t] = x[i];
      nv[t] = v[i];
    }
    swap(x, nx);
    swap(v, nv);
  }
  {
    auto vv = v;
    sort(begin(vv), end(vv));
    vv.erase(unique(begin(vv), end(vv)), end(vv));
    for (auto&& e : v) {
      e = lower_bound(begin(vv), end(vv), e) - begin(vv);
    }
  }
  fenwick<int> ftc(n);
  fenwick<long long> fts(n);
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    res += (long long)ftc.sum(v[i] + 1) * x[i] - fts.sum(v[i] + 1);
    ftc.add(v[i], 1);
    fts.add(v[i], x[i]);
  }
  cout << res << '\n';
}