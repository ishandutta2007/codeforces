#include <bits/stdc++.h>

template <class> class GetInverse;
template <int Id> class ModInt {
 public:
  static int64_t mod() { return mod_; }
  static void mod(int64_t mod) {
    __glibcxx_assert(mod >= 1);
    mod_ = mod;
  }

  ModInt() : val_(0) {}
  template <class Int> ModInt(const Int& v) : val_(v % mod()) { val_ = int64_t(val_) < 0 ? val_ + mod_ : val_; }
  int64_t val() const { return val_; }
  ModInt& operator++() { return val_ = ++val_ == mod_ ? 0 : val_, *this; }
  ModInt& operator--() { return --(val_ ? val_ : val_ = mod_), *this; }
  ModInt& operator*=(ModInt o) {
    val_ = val_ * o.val_ - uint64_t((long double)val_ * o.val_ / mod_) * mod_;
    val_ = int64_t(val_) < 0 ? val_ + mod_ : val_ >= mod_ ? val_ - mod_ : val_;
    return *this;
  }
  ModInt& operator/=(ModInt o) { return *this *= GetInverse<ModInt>{}(o); }
  ModInt& operator+=(ModInt o) { return val_ = int64_t(val_ += o.val_ - mod_) < 0 ? val_ + mod_ : val_, *this; }
  ModInt& operator-=(ModInt o) { return val_ = int64_t(val_ -= o.val_) < 0 ? val_ + mod_ : val_, *this; }

  friend ModInt operator++(ModInt& a, int) { return std::exchange(a, ++ModInt(a)); }
  friend ModInt operator--(ModInt& a, int) { return std::exchange(a, --ModInt(a)); }
  friend ModInt operator+(ModInt a) { return a; }
  friend ModInt operator-(ModInt a) { return ModInt{} -= a; }
  friend ModInt operator*(ModInt a, ModInt b) { return ModInt(a) *= b; }
  friend ModInt operator/(ModInt a, ModInt b) { return ModInt(a) /= b; }
  friend ModInt operator+(ModInt a, ModInt b) { return ModInt(a) += b; }
  friend ModInt operator-(ModInt a, ModInt b) { return ModInt(a) -= b; }
  friend bool operator==(ModInt a, ModInt b) { return a.val_ == b.val_; }
  friend bool operator!=(ModInt a, ModInt b) { return a.val_ != b.val_; }

 private:
  static inline uint64_t mod_ = 9223372036854775783;

  uint64_t val_;
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, mod;
  cin >> n >> mod;
  using Mint = ModInt<-1>;
  Mint::mod(mod);
  vector<vector<Mint>> f(n + 1);
  f[0] = {1};
  for (int i = 1; i <= n; ++i) {
    f[i] = f[i - 1];
    f[i].resize(size(f[i - 1]) + (i - 1));
    for (int j = 0; j + i < int(size(f[i])); ++j) f[i][j + i] -= f[i - 1][j];
    for (int j = 1; j < int(size(f[i])); ++j) f[i][j] += f[i][j - 1];
  }
  auto pref = f;
  for (auto&& v : pref) partial_sum(begin(v), end(v), begin(v));
  vector<vector<Mint>> binom(n + 1);
  binom[0] = {1};
  for (int i = 1; i <= n; ++i) {
    binom[i].resize(i + 1);
    for (int j = 0; j <= i; ++j) {
      if (j) binom[i][j] += binom[i - 1][j - 1];
      if (j < i) binom[i][j] += binom[i - 1][j];
    }
  }
  vector<Mint> fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = i * fact[i - 1];
  Mint ans;
  for (int x = 0; x < n - 2; ++x) {
    int y = n - x;
    Mint cur;
    for (int d = 1; d < y; ++d) {
      Mint t;
      for (int i = d + 1; i < int(size(f[y - 1])); ++i) t += f[y - 1][i] * pref[y - 1][i - d - 1];
      t *= y - d;
      cur += t;
    }
    cur *= binom[n][x] * fact[x];
    ans += cur;
  }
  cout << ans.val() << '\n';
}