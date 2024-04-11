#include <bits/extc++.h>

template <uint32_t Modulus>
struct modular {
  static_assert(int(Modulus) > 0, "Modulus must be in the range [1, 2^31)");
  static constexpr int modulus() { return Modulus; }

  modular() : v(0) {}
  modular(int64_t x) : v(x % Modulus) {
    if (int(v) < 0) v += Modulus;
  }

  explicit operator int() const { return v; }
  modular& operator++() { return ++v == Modulus ? v = 0 : 0, *this; }
  modular& operator--() { return --(v ? v : v = Modulus), *this; }
  modular operator+() const { return *this; }
  modular operator-() const {
    modular res;
    res.v = v ? Modulus - v : 0;
    return res;
  }
  modular& operator*=(modular b) {
    v = uint64_t(v) * b.v % Modulus;
    return *this;
  }
  modular& operator/=(modular b) {
    auto [x, gcd] = extgcd(b.v, Modulus);
    assert(gcd == 1);
    return *this *= x;
  }
  modular& operator+=(modular b) {
    v += b.v - Modulus;
    if (int(v) < 0) v += Modulus;
    return *this;
  }
  modular& operator-=(modular b) {
    v -= b.v;
    if (int(v) < 0) v += Modulus;
    return *this;
  }

  friend modular operator++(modular& a, int) {
    return std::exchange(a, ++modular(a));
  }
  friend modular operator--(modular& a, int) {
    return std::exchange(a, --modular(a));
  }
  friend modular operator*(modular a, modular b) { return a *= b; }
  friend modular operator/(modular a, modular b) { return a /= b; }
  friend modular operator+(modular a, modular b) { return a += b; }
  friend modular operator-(modular a, modular b) { return a -= b; }
  friend std::istream& operator>>(std::istream& is, modular& b) {
    int64_t x;
    return is >> x, b = x, is;
  }
  friend std::ostream& operator<<(std::ostream& os, modular b) {
    return os << b.v;
  }
  friend bool operator==(modular a, modular b) { return a.v == b.v; }
  friend bool operator!=(modular a, modular b) { return a.v != b.v; }

 private:
  static std::pair<int, int> extgcd(int a, int b) {
    std::array x{1, 0};
    while (b) {
      int q = a / b;
      std::swap(x[0] -= q * x[1], x[1]);
      std::swap(a -= q * b, b);
    }
    return {x[0], a};
  }

  uint32_t v;
};

template <class F>
struct y_combinator : private F {
  y_combinator(F f) : F(f) {}
  template <class... Args>
  decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> v(n), w(n);
  for (int i = 0; i < n; ++i) cin >> v[i] >> w[i];
  int q;
  cin >> q;

  int cnt = 0;
  vector ls(n + q, -1), rs(n + q, -1);
  auto add = [&](int i) -> void {
    assert(ls[i] == -1);
    ls[i] = cnt;
  };
  auto remove = [&](int i) -> void {
    assert(rs[i] == -1);
    rs[i] = cnt;
  };

  for (int i = 0; i < n; ++i) add(i);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int nv, nw;
      cin >> nv >> nw;
      v.push_back(nv);
      w.push_back(nw);
      add(n++);
    } else if (type == 2) {
      int x;
      cin >> x;
      --x;
      remove(x);
    } else if (type == 3) {
      ++cnt;
    } else
      assert(false);
  }
  for (int i = 0; i < n; ++i)
    if (rs[i] == -1) remove(i);

  vector<vector<int>> seg(2 * cnt);
  for (int i = 0; i < n; ++i) {
    for (int l = cnt + ls[i], r = cnt + rs[i]; l < r; l >>= 1, r >>= 1) {
      if (l & 1) seg[l++].push_back(i);
      if (r & 1) seg[--r].push_back(i);
    }
  }

  using mint = modular<int(1e9) + 7>;
  const mint base = 1e7 + 19;

  vector<mint> ans(cnt);
  vector dp(1, vector(m + 1, 0));
  y_combinator([&](auto&& self, int i) -> void {
    for (int x : seg[i]) {
      auto ndp = dp.back();
      for (int j = w[x]; j <= m; ++j)
        ndp[j] = max(ndp[j], dp.back()[j - w[x]] + v[x]);
      dp.push_back(move(ndp));
    }
    if (i >= cnt) {
      for (int j = m; j; --j) {
        ans[i - cnt] *= base;
        ans[i - cnt] += dp.back()[j];
      }
    } else {
      self(2 * i);
      self(2 * i + 1);
    }
    for ([[maybe_unused]] int x : seg[i]) dp.pop_back();
  })(1);

  for (auto&& e : ans) cout << e << '\n';
}