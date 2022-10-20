#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

struct M {
  using T = int;
  static T op(const T& a, const T& b) { return min(a, b); }
  static constexpr T e() { return numeric_limits<T>::max(); }
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

struct M2 {
  using T = int;
  using U = int;
  static void ap(T& a, const U& g) { a = g == id() ? a : g; }
  // static void ap(U& f, const U& g) { f += g; }
  static constexpr U id() { return -1; }
};

template<class M> struct ST2 {
  using T = typename M::T;
  using U = typename M::U;
  int n;
  V<T> t;
  V<U> u;

  ST2(int n) : n(n) {
    t.resize(n);
    u.assign(n, M::id());
  }

  void _ap(int i, const U& f) {
    if (i < n) M::ap(u[i], f);
    else M::ap(t[i - n], f);
  }

  T get(int i) {
    T res = t[i];
    for (i += n; i >>= 1;) M::ap(res, u[i]);
    return res;
  }

  void set(int l, int r, const U& f) {
    stack<int> s;
    for (int i = l + n; i >>= 1;) s.push(i);
    for (int i = r + n - 1; i >>= 1;) s.push(i);
    while (!s.empty()) {
      int i = s.top(); s.pop();
      _ap(2 * i, u[i]);
      _ap(2 * i + 1, u[i]);
      u[i] = M::id();
    }
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) _ap(l++, f);
      if (r & 1) _ap(--r, f);
    }
  }
};

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  V<> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  V<> _a = a;
  bool chk = false; for (int i = 0; i < n; i++) if (a[i] == 0 or a[i] == q) chk = true;
  if (!chk) return cout << "NO" << '\n', 0;
  for (int i = 0; i < n; i++) if (a[i] == 0) a[i] = q + 1;
  VV<> i2a(q + 2); for (int i = 0; i < n; i++) i2a[a[i]].push_back(i);
  for (auto&& v : i2a) sort(v.begin(), v.end());
  ST<M> st(n); for (int i = 0; i < n; i++) st.t[i + n] = a[i]; st.build();
  ST2<M2> st2(n); st2.set(0, n, 0);
  for (int i = 1; i < q + 1; i++) {
    if (i2a[i].size() == 0) continue;
    if (st.get(i2a[i][0], i2a[i].back() + 1) < i) return cout << "NO" << '\n', 0;
    st2.set(i2a[i][0], i2a[i].back() + 1, i);
  }
  for (int i = 0; i < n; i++) a[i] = st2.get(i);
  chk = false; for (int i = 0; i < n; i++) if (a[i] == q) chk = true;
  if (!chk) for (int i = 0; i < n; i++) if (_a[i] == 0) { a[i] = q; chk = true; break; }
  if (!chk) return cout << "NO" << '\n', 0;
  cout << "YES" << '\n';
  for (int i = 1; i < n; i++) if (a[i] == 0) a[i] = a[i - 1];
  for (int i = n - 2; i >= 0; i--) if (a[i] == 0) a[i] = a[i + 1];
  for (int i = 0; i < n; i++) cout << a[i] << ' ';
  cout << '\n';
}