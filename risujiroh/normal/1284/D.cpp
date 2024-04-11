#include <bits/stdc++.h>
using namespace std;

uint64_t rng() {
  static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<uint64_t>(0, -1)(mt);
}

template <class T> struct FenwickTree {
  const int n;
  vector<T> t;
  FenwickTree(int _n) : n(_n), t(n + 1) {}
  void add(int i, T a) { for (++i; i <= n; i += i & -i) t[i] ^= a; }
  T sum(int i) const {
    T s = 0;
    for (; i; i -= i & -i) s ^= t[i];
    return s;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<uint64_t> h(n);
  auto fn = [&](vector<int> l, vector<int> r) {
    auto v = l;
    v.insert(end(v), begin(r), end(r));
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
    for (auto&& e : l) {
      e = lower_bound(begin(v), end(v), e) - begin(v);
    }
    for (auto&& e : r) {
      e = lower_bound(begin(v), end(v), e) - begin(v);
    }
    int m = v.size();
    vector<vector<int>> ls(m), rs(m);
    for (int i = 0; i < n; ++i) {
      ls[l[i]].push_back(i);
      rs[r[i]].push_back(i);
    }
    FenwickTree<uint64_t> ft(m);
    vector<uint64_t> res(n);
    for (int x = m; x--; ) {
      for (int i : rs[x]) {
        ft.add(l[i], h[i]);
      }
      for (int i : ls[x]) {
        res[i] = ft.sum(r[i] + 1);
      }
    }
    return res;
  };
  vector<int> la(n), ra(n), lb(n), rb(n);
  for (int i = 0; i < n; ++i) {
    cin >> la[i] >> ra[i] >> lb[i] >> rb[i];
  }
  for (int _ = 2; _--; ) {
    generate(begin(h), end(h), rng);
    if (fn(la, ra) != fn(lb, rb)) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}