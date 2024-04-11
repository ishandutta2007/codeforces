#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

template<class T> struct BIT {
  int n, h;
  V<T> t;

  BIT(int n) : n(n), h(__lg(n) + 1) { t.assign(n + 1, (T) 0); }

  void add(int x, T a) {
    for (int i = x + 1; i < n + 1; i += i & -i) t[i] += a;
  }

  int lower_bound(T s) {
    if (s <= 0) return 0;
    int res = 0;
    for (int k = 1 << h - 1; k; k >>= 1) if (res + k < n + 1 and t[res + k] < s) s -= t[res += k];
    return res + 1;
  }

  T sum(int x) {
    T res = 0;
    for (int i = x; i; i -= i & -i) res += t[i];
    return res;
  }

  T sum(int l, int r) {
    return sum(r) - sum(l);
  }
};

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  lint t; cin >> t;
  V<lint> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  V<lint> c(n + 1);
  for (int i = 0; i < n; i++) c[i + 1] = c[i] + a[i];
  V<lint> d = c;
  sort(d.begin(), d.end());
  lint res = 0;
  BIT<int> bit(n + 1);
  for (int i = 0; i < n; i++) {
    bit.add(lower_bound(d.begin(), d.end(), c[i]) - d.begin(), 1);
    res += bit.sum(upper_bound(d.begin(), d.end(), c[i + 1] - t) - d.begin(), n + 1);
  }
  cout << res << '\n';
}