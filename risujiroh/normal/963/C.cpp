#include <bits/stdc++.h>
using namespace std;

struct u128 {
  uint64_t u, l;
  u128(uint64_t x = 0) : u(0), l(x) {}
  u128(uint64_t _u, uint64_t _l) : u(_u), l(_l) {}
  u128 operator-() const { return u128() -= *this; }
  u128& operator+=(u128 b) { u += b.u, l += b.l, u += l < b.l; return *this; }
  u128& operator-=(u128 b) { u -= l < b.l, u -= b.u, l -= b.l; return *this; }
  u128& operator*=(u128 b) {
    uint64_t au = l >> 32, al = (unsigned)l, bu = b.l >> 32, bl = (unsigned)b.l;
    u = u * b.l + l * b.u + au * bu, l = al * bl;
    return *this += (u128(au * bl) << 32) + (u128(al * bu) << 32);
  }
  friend int lg(u128 a) { return a.u ? __lg(a.u) + 64 : __lg(a.l); }
  friend pair<u128, u128> divmod(u128 a, u128 b) {
    assert(b.u or b.l);
    if (a < b) return {0, a};
    int s = lg(a) - lg(b);
    b <<= s;
    u128 q = 0, r = a;
    for (int i = 0; i <= s; ++i) {
      q <<= 1;
      if (r >= b) r -= b, q.l |= 1;
      b >>= 1;
    }
    return {q, r};
  }
  u128& operator/=(u128 b) { return *this = divmod(*this, b).first; }
  u128& operator%=(u128 b) { return *this = divmod(*this, b).second; }
  u128& operator<<=(size_t n) {
    if (n >= 64) u = l << (n - 64), l = 0;
    else if (n) u = u << n | l >> (64 - n), l <<= n;
    return *this;
  }
  u128& operator>>=(size_t n) {
    if (n >= 64) l = u >> (n - 64), u = 0;
    else if (n) l = l >> n | u << (64 - n), u >>= n;
    return *this;
  }
  friend u128 operator+(u128 a, u128 b) { return a += b; }
  friend u128 operator-(u128 a, u128 b) { return a -= b; }
  friend u128 operator*(u128 a, u128 b) { return a *= b; }
  friend u128 operator/(u128 a, u128 b) { return a /= b; }
  friend u128 operator%(u128 a, u128 b) { return a %= b; }
  friend u128 operator<<(u128 a, size_t n) { return a <<= n; }
  friend u128 operator>>(u128 a, size_t n) { return a >>= n; }
  friend bool operator<(u128 a, u128 b) {
    return a.u != b.u ? a.u < b.u : a.l < b.l;
  }
  friend bool operator>(u128 a, u128 b) { return b < a; }
  friend bool operator<=(u128 a, u128 b) { return !(a > b); }
  friend bool operator>=(u128 a, u128 b) { return !(a < b); }
  friend bool operator==(u128 a, u128 b) { return a.u == b.u and a.l == b.l; }
  friend bool operator!=(u128 a, u128 b) { return !(a == b); }
  friend string to_string(u128 a) {
    string s;
    do s += '0' + (a % 10).l, a /= 10; while (a != 0);
    return {rbegin(s), rend(s)};
  }
};

template <class Z> vector<Z> divisor(Z n) {
  vector<Z> res;
  Z i;
  for (i = 1; i * i < n; ++i) if (n % i == 0) res.push_back(i), res.push_back(n / i);
  if (i * i == n) res.push_back(i);
  sort(begin(res), end(res));
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> h(n), w(n), c(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i] >> w[i] >> c[i];
  }
  auto vh = h;
  sort(begin(vh), end(vh));
  vh.erase(unique(begin(vh), end(vh)), end(vh));
  auto vw = w;
  sort(begin(vw), end(vw));
  vw.erase(unique(begin(vw), end(vw)), end(vw));
  int a = vh.size(), b = vw.size();
  if ((long long)a * b != n) {
    cout << "0\n";
    exit(0);
  }
  vector<vector<long long>> z(a, vector<long long>(b));
  for (int id = 0; id < n; ++id) {
    int i = lower_bound(begin(vh), end(vh), h[id]) - begin(vh);
    int j = lower_bound(begin(vw), end(vw), w[id]) - begin(vw);
    assert(z[i][j] == 0);
    z[i][j] = c[id];
  }
  long long g = 0;
  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < b; ++j) {
      if (u128(z[0][0]) * z[i][j] != u128(z[0][j]) * z[i][0]) {
        cout << "0\n";
        exit(0);
      }
      g = __gcd(g, z[i][j]);
    }
  }
  cout << divisor(g).size() << '\n';
}