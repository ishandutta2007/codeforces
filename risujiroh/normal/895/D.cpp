#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T, class Op = multiplies<T>>
T power(T a, long long n, Op op = Op(), T e = {1}) {
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
};

constexpr long long mod = 1e9 + 7;
using mint = modular<mod>;

vector<mint> fact, inv_fact, minv;
void prepare(int n) {
  fact.resize(n + 1), inv_fact.resize(n + 1), minv.resize(n + 1);
  for (int i = 0; i <= n; ++i) fact[i] = i ? i * fact[i - 1] : 1;
  inv_fact[n] = power(fact[n], mod - 2);
  for (int i = n; i; --i) inv_fact[i - 1] = inv_fact[i] * i;
  for (int i = 1; i <= n; ++i) minv[i] = fact[i - 1] * inv_fact[i];
}
mint binom(int n, int k) {
  if (k < 0 or k > n) return 0;
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}
template<> mint& mint::operator/=(mint r) {
  return *this *= r.v < minv.size() ? minv[r.v] : power(r, mod - 2);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string a, b;
  cin >> a >> b;
  {
    int i = 0;
    while (a[i] == b[i]) {
      ++i;
    }
    a = a.substr(i);
    b = b.substr(i);
  }
  int n = a.size();
  prepare(n);
  vector<int> cnt(26);
  auto fn = [&] {
    mint res = 1;
    int sum = 0;
    for (int e : cnt) {
      res *= inv_fact[e];
      sum += e;
    }
    res *= fact[sum];
    return res;
  };
  for (char c : a) {
    ++cnt[c - 'a'];
  }
  mint res;
  for (int i = a[0] - 'a' + 1; i < b[0] - 'a'; ++i) {
    if (cnt[i] == 0) {
      continue;
    }
    --cnt[i];
    res += fn();
    ++cnt[i];
  }
  for (int m = 1; m < n; ++m) {
    --cnt[a[m - 1] - 'a'];
    mint cur = fn();
    for (int i = a[m] - 'a' + 1; i < 26; ++i) {
      if (cnt[i] == 0) {
        continue;
      }
      cur *= minv[n - m] * cnt[i];
      res += cur;
      cur *= (n - m) * minv[cnt[i]];
    }
  }
  fill(begin(cnt), end(cnt), 0);
  for (char c : a) {
    ++cnt[c - 'a'];
  }
  for (int m = 1; m < n; ++m) {
    if (cnt[b[m - 1] - 'a'] == 0) {
      break;
    }
    DEBUG(m);
    --cnt[b[m - 1] - 'a'];
    DEBUG(cnt);
    mint cur = fn();
    for (int i = 0; i < b[m] - 'a'; ++i) {
      if (cnt[i] == 0) {
        continue;
      }
      cur *= minv[n - m] * cnt[i];
      res += cur;
      cur *= (n - m) * minv[cnt[i]];
    }
  }
  cout << res.v << '\n';
}