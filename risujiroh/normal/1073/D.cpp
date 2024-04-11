#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V  = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


template<class T> struct BIT {
  int n, h;
  V<T> t;

  BIT(int n) : n(n), h(__lg(n) + 1), t(n + 1, (T) 0) {}

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
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  lint t; cin >> t;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  BIT<lint> bit(n);
  for (int i = 0; i < n; ++i) bit.add(i, a[i]);
  lint res = 0;
  int m = n;
  while (m > 0) {
    lint s = bit.sum(n);
    if (t >= s) {
      res += t / s * m;
      t %= s;
    }
    while (s > 0 and s > t) {
      int i = bit.lower_bound(t + 1) - 1;
      bit.add(i, -a[i]);
      --m;
      s = bit.sum(n);
    }
  }
  cout << res << '\n';
}