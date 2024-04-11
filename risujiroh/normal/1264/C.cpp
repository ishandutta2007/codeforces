#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;
struct Mint {
  int v;
  Mint(long long a = 0) : v((a %= mod) < 0 ? a + mod : a) {}
  Mint& operator*=(Mint r) { v = (long long)v * r.v % mod; return *this; }
  Mint& operator/=(Mint r) { return *this *= r.inv(); }
  Mint& operator+=(Mint r) { if ((v += r.v) >= mod) v -= mod; return *this; }
  Mint& operator-=(Mint r) { if ((v -= r.v) < 0) v += mod; return *this; }
  friend Mint operator*(Mint l, Mint r) { return l *= r; }
  friend Mint operator/(Mint l, Mint r) { return l /= r; }
  friend Mint operator+(Mint l, Mint r) { return l += r; }
  friend Mint operator-(Mint l, Mint r) { return l -= r; }
  Mint pow(long long n) const {
    Mint res = 1;
    for (Mint t = *this; n; t *= t, n >>= 1) if (n & 1) res *= t;
    return res;
  }
  Mint inv() const { return pow(mod - 2); }
  friend string to_string(Mint a) { return to_string(a.v); }
};

bool operator==(Mint l, Mint r) { return l.v == r.v; }

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
  T acc(int l, int r) {
    push(l, r);
    T a = E(), b = E();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) a = Op(a, t[l++]);
      if (r & 1) b = Op(t[--r], b);
    }
    return Op(a, b);
  }
  T get(int i) { return acc(i, i + 1); }
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

Mint add(Mint a, Mint b) { return a + b; }
Mint zero() { return 0; }
Mint mul(Mint a, Mint b) { return a * b; }
Mint one() { return 1; }

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<Mint> a(n);
  for (auto&& e : a) {
    Mint p;
    cin >> p.v;
    e = 100 / p;
  }
  SegmentTree<Mint, add, zero, Mint, mul, mul, one> st(n);
  Mint prod = 1;
  for (int i = n - 1; i >= 0; --i) {
    prod *= a[i];
    st[i] = prod;
  }
  st.build();
  set<int> se{0, n};
  while (q--) {
    int u;
    cin >> u;
    --u;
    if (se.count(u)) {
      int i = *prev(se.lower_bound(u));
      st.act(i, u, st.get(u));
      se.erase(u);
    } else {
      int i = *prev(se.lower_bound(u));
      st.act(i, u, st.get(u).inv());
      se.insert(u);
    }
    cout << st.acc(0, n).v << '\n';
  }
}