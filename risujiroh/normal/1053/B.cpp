#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

struct M {
  using T = int;
  static T op(const T& a, const T& b) { return max(a, b); }
  static constexpr T e() { return numeric_limits<T>::min(); }
};

template<class M> struct ST {
  using T = typename M::T;
  int n;
  V<T> t;

  ST(int n) : n(n) {
    t.assign(2 * n, M::e());
  }

  void build() {
    for (int i = n - 1; i; i--) t[i] = M::op(t[2 * i], t[2 * i + 1]);
  }

  T get(int l, int r) {
    T resl = M::e(), resr = M::e();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) { 
      if (l & 1) resl = M::op(resl, t[l++]); 
      if (r & 1) resr = M::op(t[--r], resr);
    }
    return M::op(resl, resr);
  }

  void set(int i, const T& a) {
    for (t[i += n] = a; i >>= 1;) t[i] = M::op(t[2 * i], t[2 * i + 1]);
  }
};

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n);
  for (int i = 0; i < n; i++) {
    lint b; cin >> b;
    a[i] = __builtin_popcountll(b);
  }
  V<> ca(n + 1);
  for (int i = 0; i < n; i++) ca[i + 1] = ca[i] + a[i];
  V<> p(n + 1);
  for (int i = 0; i < n + 1; i++) p[i] = ca[i] & 1;
  V<> cp(n + 2);
  for (int i = 0; i < n + 1; i++) cp[i + 1] = cp[i] + p[i];
  lint res = 0;
  ST<M> st(n);
  for (int i = 0; i < n; i++) st.t[i + n] = a[i];
  st.build();
  for (int l = 0; l < n; l++) {
    int r;
    for (r = l + 2; r < n + 1; r++) {
      int s = ca[r] - ca[l];
      if (s >= 120) break;
      res += !(s & 1) and 2 * st.get(l, r) <= s;
    }
    if (p[l]) {
      res += cp[n + 1] - cp[r];
    } else {
      res += n + 1 - r - (cp[n + 1] - cp[r]);
    }
  }
  cout << res << '\n';
}