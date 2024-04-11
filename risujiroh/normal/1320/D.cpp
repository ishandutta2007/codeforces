#include <bits/stdc++.h>
using namespace std;

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
  modular(long long a = 0) : v((a %= M) < 0 ? a + M : a) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m r) { if ((v += r.v) >= M) v -= M; return *this; }
  m& operator-=(m r) { if (v < r.v) v += M; v -= r.v; return *this; }
  m& operator*=(m r) { v = (uint64_t)v * r.v % M; return *this; }
  m& operator/=(m r) { return *this *= power(r, M - 2); }
  friend m operator+(m l, m r) { return l += r; }
  friend m operator-(m l, m r) { return l -= r; }
  friend m operator*(m l, m r) { return l *= r; }
  friend m operator/(m l, m r) { return l /= r; }
  friend bool operator==(m l, m r) { return l.v == r.v; }
  friend string to_string(m a) { return to_string(a.v); }
};

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
template <class Z> Z rng(Z l, Z r) {
  return uniform_int_distribution<Z>(l, r - 1)(mt);
}

struct hash_t {
  static constexpr unsigned mod = 2e9 + 33;
  static modular<mod> base[2];
  int len;
  modular<mod> h[2], pb[2], ipb[2];
  hash_t() : len(0), h{0, 0}, pb{1, 1}, ipb{1, 1} {}
  template <class Char> hash_t(Char c) : len(1), h{c, c} {
    for (int k : {0, 1}) pb[k] = base[k], ipb[k] = 1 / pb[k];
  }
  hash_t(pair<int, int> p, int _len) : len(_len), h{p.first, p.second} {
    for (int k : {0, 1}) pb[k] = power(base[k], len), ipb[k] = 1 / pb[k];
  }
  hash_t& operator*=(const hash_t& b) {
    len += b.len;
    for (int k : {0, 1})
      (h[k] *= b.pb[k]) += b.h[k], pb[k] *= b.pb[k], ipb[k] *= b.ipb[k];
    return *this;
  }
  friend hash_t operator*(hash_t a, const hash_t& b) { return a *= b; }
  friend bool operator==(const hash_t& a, const hash_t& b) {
    return a.len == b.len and a.h[0] == b.h[0] and a.h[1] == b.h[1];
  }
  friend bool operator!=(const hash_t& a, const hash_t& b) { return !(a == b); }
  friend hash_t inv(hash_t a) {
    a.len = -a.len;
    for (int k : {0, 1}) a.h[k] *= -a.ipb[k], swap(a.pb[k], a.ipb[k]);
    return a;
  }
  friend string to_string(hash_t a) {
    return "(" + to_string(a.h[0]) + ", " + to_string(a.len) + ")";
  }
};
modular<hash_t::mod> hash_t::base[]{rng<int>(1e9, 2e9), rng<int>(1e9, 2e9)};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> tor(n + 1);
  for (int i = n; i--; ) {
    if (s[i] == '1') {
      tor[i] = 1 + tor[i + 1];
    }
  }
  vector<int> tol(n + 1);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      tol[i + 1] = tol[i] + 1;
    }
  }
  vector<hash_t> cum(n + 1);
  for (int i = n; i--; ) {
    if (s[i] == '0') {
      cum[i] = hash_t('0') * cum[i + 1];
    } else if ((i == 0 or s[i - 1] == '0') and tor[i] & 1) {
      cum[i] = hash_t('1') * cum[i + 1];
    } else {
      cum[i] = cum[i + 1];
    }
  }
  auto f = [&](int l, int r) {
    if (tor[l] >= r - l) {
      if ((r - l) & 1) {
        return hash_t('1');
      } else {
        return hash_t();
      }
    }
    int ml = l + tor[l], mr = r - tol[r];
    auto res = cum[ml] * inv(cum[mr]);
    if ((ml - l) & 1) {
      res = hash_t('1') * res;
    }
    if ((r - mr) & 1) {
      res = res * hash_t('1');
    }
    return res;
  };
  int q;
  cin >> q;
  while (q--) {
    int i, j, len;
    cin >> i >> j >> len;
    --i, --j;
    if (f(i, i + len) == f(j, j + len)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}