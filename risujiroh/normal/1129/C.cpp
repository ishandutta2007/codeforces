#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


template<unsigned P> struct ModInt {
  using M = ModInt;
  unsigned v;
  ModInt() : v(0) {}
  template<class Int> ModInt(Int x) : v(x >= 0 ? x % P : -x % P ? P - -x % P : 0) {}
  constexpr ModInt(unsigned v, int) : v(v) {}
  static constexpr unsigned p() { return P; }
  M operator+() const { return *this; }
  M operator-() const { return {v ? P - v : 0, 0}; }
  explicit operator bool() const noexcept { return v; }
  bool operator!() const noexcept { return !(bool) *this; }
  M operator*(M rhs) const { return M(*this) *= rhs; }
  M operator/(M rhs) const { return M(*this) /= rhs; }
  M operator+(M rhs) const { return M(*this) += rhs; }
  M operator-(M rhs) const { return M(*this) -= rhs; }
  bool operator==(M rhs) const { return v == rhs.v; }
  bool operator!=(M rhs) const { return !(*this == rhs); }
  M& operator*=(M rhs) { v = (unsigned long long) v * rhs.v % P; return *this; }
  M& operator/=(M rhs) { return *this *= rhs.inv(); }
  M& operator+=(M rhs) { v = rhs.v < P - v ? v + rhs.v : v - (P - rhs.v); return *this; }
  M& operator-=(M rhs) { v = rhs.v <= v ? v - rhs.v : v + (P - rhs.v); return *this; }
  M inv() const {
    int a = v, b = P, x = 1, u = 0;
    while (b) {
      int q = a / b;
      swap(a -= q * b, b);
      swap(x -= q * u, u);
    }
    assert(a == 1);
    return x;
  }
  template<class Int> M pow(Int n) const {
    n = n >= 0 ? n % (P - 1) : P - 1 - -n % (P - 1);
    M res = 1;
    for (M a = *this; n; a *= a, n >>= 1) if (n & 1) res *= a;
    return res;
  }
  template<class Int> friend M operator*(Int lhs, M rhs) { return M(lhs) *= rhs; }
  template<class Int> friend M operator/(Int lhs, M rhs) { return M(lhs) /= rhs; }
  template<class Int> friend M operator+(Int lhs, M rhs) { return M(lhs) += rhs; }
  template<class Int> friend M operator-(Int lhs, M rhs) { return M(lhs) -= rhs; }
  friend ostream& operator<<(ostream& os, M rhs) { return os << rhs.v; }
  friend istream& operator>>(istream& is, M& rhs) { lint x; is >> x; rhs = x; return is; }
  template<class Int> friend bool operator==(Int lhs, M rhs) { return M(lhs) == rhs; }
  template<class Int> friend bool operator!=(Int lhs, M rhs) { return !(lhs == rhs); }
};
using Mint = ModInt<(unsigned) 1e9 + 7>;

struct Node;
using Trie = Node*;
struct Node {
  bool ex = false;
  V<Trie> ch;
  Node() : ch(2) {}
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s;
  for (int i = 0; i < n; ++i) {
    char c; cin >> c;
    s += c;
  }
  reverse(begin(s), end(s));
  V<string> t;
  for (int l = 1; l <= 4; ++l) {
    for (int bit = 0; bit < 1 << l; ++bit) {
      string curr;
      for (int i = 0; i < l; ++i) {
        curr += bit & 1 << i ? '1' : '0';
      }
      if (curr == "1100" or curr == "1010" or curr == "0111" or curr == "1111") continue;
      t.push_back(curr);
    }
  }
  int m = t.size();
  assert(m == 26);
  VV<Mint> dp(n, V<Mint>(n));
  for (int l = n - 1; l >= 0; --l) {
    for (int k = 1; k <= 4; ++k) {
      if (l + k > n or count(begin(t), end(t), s.substr(l, k)) == 0) continue;
      dp[l][l + k - 1] += 1;
      for (int r = l + k; r < n; ++r) {
        dp[l][r] += dp[l + k][r];
      }
    }
  }
  Trie tr = new Node();
  Mint res = 0;
  for (int l = n - 1; l >= 0; --l) {
    auto p = tr;
    for (int r = l; r < n; ++r) {
      int i = s[r] - '0';
      if (!p->ch[i]) p->ch[i] = new Node();
      p = p->ch[i];
      if (p->ex) continue;
      p->ex = true;
      res += dp[l][r];
    }
    cout << res << '\n';
  }
}