#include <bits/stdc++.h>
using namespace std;

template<class T, T Op(T, T), T E(), class U, T Ap(T, U), U Cp(U, U), U Id()>
struct SegmentTree {
  const int n;
  vector<T> t;
  vector<U> u;
  SegmentTree(int _n) : n(_n), t(2 * n, E()), u(n, Id()) {}
  T& operator[](int i) { return t[i + n]; }
  void build() {
    for (int i = n - 1; i >= 1; --i) t[i] = Op(t[2 * i], t[2 * i + 1]);
  }
  void push() { for (int i = 1; i < n; ++i) push(i); }
  void apply(int i, U f) {
    t[i] = Ap(t[i], f);
    if (i < n) u[i] = Cp(u[i], f);
  }
  void push(int i) {
    if (u[i] == Id()) return;
    apply(2 * i, u[i]);
    apply(2 * i + 1, u[i]);
    u[i] = Id();
  }
  void push(int l, int r) {
    for (int hl = __lg(l + n), hr = __lg(r - 1 + n); hr > 0; --hl, --hr) {
      int al = (l + n) >> hl, ar = (r - 1 + n) >> hr;
      if (al < n) push(al);
      if (ar != al) push(ar);
    }
  }
  T fold(int l, int r) {
    push(l, r);
    T a = E(), b = E();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) a = Op(a, t[l++]);
      if (r & 1) b = Op(t[--r], b);
    }
    return Op(a, b);
  }
  T get(int i) { return fold(i, i + 1); }
  void act(int l, int r, U f) {
    push(l, r);
    for (int i = l + n, j = r + n; i < j; i >>= 1, j >>= 1) {
      if (i & 1) apply(i++, f);
      if (j & 1) apply(--j, f);
    }
    l = (l + n) >> __builtin_ctz(l + n);
    while (l >>= 1) t[l] = Op(t[2 * l], t[2 * l + 1]);
    r = (r + n) >> __builtin_ctz(r + n);
    while (r >>= 1) t[r] = Op(t[2 * r], t[2 * r + 1]);
  }
  void set(int i, T a) {
    push(i, i + 1);
    t[i += n] = a;
    while (i >>= 1) t[i] = Op(t[2 * i], t[2 * i + 1]);
  }
};

using P = pair<int, int>;
P _minmax(P a, P b) { return {min(a.first, b.first), max(a.second, b.second)}; }
P e() { return {0x3f3f3f3f, -0x3f3f3f3f}; }
P add(P a, int f) { return {a.first + f, a.second + f}; }
int add(int a, int b) { return a + b; }
int zero() { return 0; }

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  SegmentTree<P, _minmax, e, int, add, add, zero> st(n + 10);
  fill(begin(st.t), end(st.t), P{0, 0});
  int p = 0;
  string s(n + 10, ' ');
  auto f = [](char c) {
    if (c == '(') {
      return 1;
    }
    if (c == ')') {
      return -1;
    }
    return 0;
  };
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    if (c == 'L') {
      p = max(p - 1, 0);
    } else if (c == 'R') {
      ++p;
    } else {
      int d = f(c) - f(s[p]);
      s[p] = c;
      st.act(p + 1, n + 1, d);
    }
    if (st.get(n).first or st.fold(0, n + 1).first < 0) {
      cout << -1;
    } else {
      cout << st.fold(0, n).second;
    }
    cout << " \n"[i == n - 1];
  }
}