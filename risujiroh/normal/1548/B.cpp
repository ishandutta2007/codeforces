#include <bits/stdc++.h>

using namespace std;

template <class T> struct foldable_deque {
  vector<T> l, r, cuml = {T()}, cumr = {T()};
  T fold() const { return cuml.back() * cumr.back(); }
  void build(vector<T> v) {
    l = r = {}, cuml = cumr = {T()};
    int n = v.size();
    for (int i = n / 2; i < n; ++i) push_back(v[i]);
    for (int i = n / 2; i--;) push_front(v[i]);
  }
  void push_front(T a) { l.push_back(a), cuml.push_back(a * cuml.back()); }
  void push_back(T a) { r.push_back(a), cumr.push_back(cumr.back() * a); }
  void pop_front() {
    if (l.empty())
      build({begin(r) + 1, end(r)});
    else
      l.pop_back(), cuml.pop_back();
  }
  void pop_back() {
    if (r.empty())
      build({rbegin(l), rend(l) - 1});
    else
      r.pop_back(), cumr.pop_back();
  }
};

struct Gcd {
  int64_t v = 0;
  friend Gcd operator*(Gcd a, Gcd b) { return {std::gcd(a.v, b.v)}; }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (auto&& e : a) cin >> e;
    foldable_deque<Gcd> f;
    int ans = 0;
    for (int i = 0, j = 0; i < n; ++i) {
      j = max(j, i);
      while (j + 1 < n) {
        f.push_back({a[j + 1] - a[j]});
        if (f.fold().v == 1) {
          f.pop_back();
          break;
        }
        ++j;
      }
      ans = max(ans, j - i + 1);
      if (i < j) f.pop_front();
    }
    cout << ans << '\n';
  }
}