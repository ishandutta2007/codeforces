#include <bits/stdc++.h>
using namespace std;

template <class T, class Op = function<T(T, T)>> struct segtree {
  const Op op;
  const T e = T();
  const int n = 0;
  vector<T> t;
  T& operator[](int i) { return t[n + i]; }
  void build() { for (int i = n; i--; ) t[i] = op(t[2 * i], t[2 * i + 1]); }
  T fold(int l, int r) const {
    T a = e, b = e;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) a = op(a, t[l++]);
      if (r & 1) b = op(t[--r], b);
    }
    return op(a, b);
  }
  void set(int i, T a) {
    t[i += n] = a;
    while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
};
template <class T, class Op> auto make_segtree(int n, Op op, T e) {
  return segtree<T, Op>{op, e, n, vector<T>(2 * n, e)};
}

template <class T, class Op = multiplies<T>>
T power(T a, long long n, Op op = multiplies<T>(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

template <unsigned M> struct modular {
  using m = modular;
  unsigned v;
  modular(long long x = 0) : v((x %= M) < 0 ? x + M : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) { if ((v += b.v) >= M) v -= M; return *this; }
  m& operator-=(m b) { if (v < b.v) v += M; v -= b.v; return *this; }
  m& operator*=(m b) { v = (uint64_t)v * b.v % M; return *this; }
  m& operator/=(m b) { return *this *= power(b, M - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
  friend string to_string(m a) { return to_string(a.v); }
};

constexpr long long mod = 1e9 + 7;
using mint = modular<mod>;

#ifndef LOCAL
template<> mint& mint::operator*=(mint b) {
  auto x = (uint64_t)v * b.v;
  unsigned xu = x >> 32, xl = x, d;
  asm("divl %4; \n\t" : "=a" (d), "=d" (v) : "d" (xu), "a" (xl), "r" (mod));
  return *this;
}
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto&& e : p) {
    cin >> e;
  }
  map<int, int> cnt;
  for (auto e : p) {
    ++cnt[e];
  }
  auto mx = cnt;
  int q;
  cin >> q;
  vector<pair<int, int>> qs(q);
  auto np = p;
  for (int id = 0; id < q; ++id) {
    int i, x;
    cin >> i >> x;
    --i;
    qs[id] = {i, x};
    --cnt[np[i]];
    mx[x] = max(mx[x], ++cnt[x]);
    np[i] = x;
  }
  vector<int> v;
  for (auto e : mx) {
    for (int _ = e.second; _--; ) {
      v.push_back(e.first);
    }
  }
  auto zip = [&](int x) {
    return lower_bound(begin(v), end(v), x) - begin(v);
  };
  int m = v.size();
  vector<mint> p2(m + 1);
  for (int i = 0; i <= m; ++i) {
    p2[i] = i ? 2 * p2[i - 1] : 1;
  }
  vector<mint> ip2(m + 1);
  ip2[m] = 1 / p2[m];
  for (int i = m; i--; ) {
    ip2[i] = 2 * ip2[i + 1];
  }
  struct node {
    mint val, lsum, rsum;
    int len;
  };
  auto st = make_segtree<node>(m, [&](const node& a, const node& b) {
    node c;
    c.val = a.val + b.val + a.lsum * ip2[a.len] * b.rsum;
    c.lsum = a.lsum + p2[a.len] * b.lsum;
    c.rsum = a.rsum + ip2[a.len] * b.rsum;
    c.len = a.len + b.len;
    return c;
  }, {0, 0, 0, 0});
  set<int> used, unused;
  for (int j = 0; j < m; ++j) {
    unused.insert(j);
  }
  for (auto e : p) {
    int j = *unused.lower_bound(zip(e));
    st[j] = {0, e, e, 1};
    used.insert(j);
    unused.erase(j);
  }
  st.build();
  cout << (st.fold(0, m).val * ip2[1]).v << '\n';
  for (auto e : qs) {
    {
      int j = *used.lower_bound(zip(p[e.first]));
      st.set(j, st.e);
      used.erase(j);
      unused.insert(j);
    }
    {
      int j = *unused.lower_bound(zip(e.second));
      st.set(j, {0, e.second, e.second, 1});
      used.insert(j);
      unused.erase(j);
    }
    p[e.first] = e.second;
    cout << (st.fold(0, m).val * ip2[1]).v << '\n';
  }
}