#include <bits/stdc++.h>
using namespace std;

auto chmax = [](auto&& l, auto r) { return exchange(l, l < r ? r : l) < r; };

struct Mo {
  const int n, q, B;
  vector<int> idx, ls, rs;
  Mo(int _n, int _q) : n(_n), q(_q), B(n / sqrt(q)), idx(q) {
    iota(begin(idx), end(idx), 0);
  }
  void add_query(int l, int r) {
    ls.push_back(l);
    rs.push_back(r);
  }
  template<class Add, class Rm, class Out> void run(Add add, Rm rm, Out out) {
    assert((int)ls.size() == q);
    sort(begin(idx), end(idx), [&](int i, int j) {
      return make_pair(ls[i] / B, rs[i]) < make_pair(ls[j] / B, rs[j]);
    });
    int l = 0, r = 0;
    for (int i : idx) {
      while (ls[i] < l) add(--l);
      while (r < rs[i]) add(r++);
      while (l < ls[i]) rm(l++);
      while (rs[i] < r) rm(--r);
      out(i);
    }
  }
};

template <class T> struct FenwickTree {
  const int n;
  vector<T> t;
  FenwickTree(int _n) : n(_n), t(n + 1) {}
  void add(int i, T a) { for (++i; i <= n; i += i & -i) t[i] += a; }
  T sum(int i) const {
    T s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
  }
  T sum(int l, int r) const { return sum(r) - sum(l); }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  vector<vector<int>> idx(n);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    --a[i];
    idx[a[i]].push_back(i);
  }
  for (int x = 0; x < n; ++x) {
    idx[x].push_back(m);
  }
  vector<tuple<int, int, int>> xlr;
  for (int x = 0; x < n; ++x) {
    int k = idx[x].size();
    for (int i = 0; i < k - 1; ++i) {
      xlr.emplace_back(x, idx[x][i] + 1, idx[x][i + 1]);
    }
  }
  Mo mo(m, xlr.size());
  for (auto e : xlr) {
    mo.add_query(get<1>(e), get<2>(e));
  }
  vector<int> res(n), cnt(n);
  iota(begin(res), end(res), 0);
  int sz = 0;
  mo.run([&](int i) {
    sz += cnt[a[i]]++ == 0;
  }, [&](int i) {
    sz -= --cnt[a[i]] == 0;
  }, [&](int j) {
    chmax(res[get<0>(xlr[j])], sz);
  });
  FenwickTree<int> ft(n);
  vector<bool> first(n, true);
  for (int e : a) {
    if (first[e]) {
      chmax(res[e], e + ft.sum(e, n));
    }
    if (ft.sum(e, e + 1) == 0) {
      ft.add(e, 1);
    }
    first[e] = false;
  }
  for (int x = 0; x < n; ++x) {
    if (first[x]) {
      chmax(res[x], x + ft.sum(x, n));
    }
  }
  for (int x = 0; x < n; ++x) {
    cout << (first[x] ? x : 0) + 1 << ' ' << res[x] + 1 << '\n';
  }
}