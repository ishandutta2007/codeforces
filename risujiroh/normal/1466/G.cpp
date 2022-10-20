#include <bits/stdc++.h>

class RollingHash {
 public:
  RollingHash() { h[0] = h[1] = {0}; }
  template <class ForwardIterator>
  RollingHash(ForwardIterator first, ForwardIterator last) {
    int n = std::distance(first, last);
    for (int t : {0, 1}) base[t].reserve(n + 1), h[t].reserve(n + 1);
    for (h[0] = h[1] = {0}; first != last; ++first) push_back(*first);
  }

  template <class T>
  void push_back(const T& a) {
    for (int t : {0, 1}) {
      h[t].push_back((uint64_t(h[t].back()) * base[t][1] + a) % P);
      while (not(size() < int(std::size(base[t]))))
        base[t].push_back(uint64_t(base[t].back()) * base[t][1] % P);
    }
  }
  void pop_back() {
    assert(size());
    for (int t : {0, 1}) h[t].pop_back();
  }

  int size() const { return std::size(h.front()) - 1; }
  int get(int l, int r, int t) const {
    assert(0 <= l), assert(l <= r), assert(r <= size());
    assert(0 <= t), assert(t < 2);
    return (h[t][r] + uint64_t(P - h[t][l]) * base[t][r - l]) % P;
  }
  std::array<int, 2> get(int l, int r) const {
    assert(0 <= l), assert(l <= r), assert(r <= size());
    return {get(l, r, 0), get(l, r, 1)};
  }

  friend int strcmp(const RollingHash& rha, int la, int ra,
                    const RollingHash& rhb, int lb, int rb) {
    assert(0 <= la), assert(la <= ra), assert(ra <= std::size(rha));
    assert(0 <= lb), assert(lb <= rb), assert(rb <= std::size(rhb));
    int ok = 0, ng = std::min(ra - la, rb - lb) + 1;
    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;
      (rha.get(la, la + mid) == rhb.get(lb, lb + mid) ? ok : ng) = mid;
    }
    if (la + ok == ra and lb + ok == rb)
      return 0;
    else if (la + ok == ra)
      return -1;
    else if (lb + ok == rb)
      return +1;
    else
      return rha.get(la + ok, la + ok + 1, 0) -
             rhb.get(lb + ok, lb + ok + 1, 0);
  }

 private:
  static constexpr uint32_t P = 2e9 + 33;
  static inline std::mt19937 mt{
      uint32_t(std::chrono::steady_clock::now().time_since_epoch().count())};
  static inline std::array base{std::vector{1, mt() % P},
                                std::vector{1, mt() % P}};

  std::array<std::vector<uint32_t>, 2> h;
};

template <uint32_t Modulus>
class ModularInt {
  using M = ModularInt;

 public:
  static_assert(int(Modulus) >= 1, "Modulus must be in the range [1, 2^31)");
  static constexpr int modulus() { return Modulus; }
  static M raw(uint32_t v) { return *reinterpret_cast<M*>(&v); }

  ModularInt() : v_(0) {}
  ModularInt(int64_t v) : v_((v %= Modulus) < 0 ? v + Modulus : v) {}

  template <class T>
  explicit operator T() const {
    return v_;
  }
  M& operator++() { return v_ = ++v_ == Modulus ? 0 : v_, *this; }
  M& operator--() { return --(v_ ? v_ : v_ = Modulus), *this; }
  M operator+() const { return *this; }
  M operator-() const { return raw(v_ ? Modulus - v_ : 0); }
  M& operator*=(M o) { return v_ = uint64_t(v_) * o.v_ % Modulus, *this; }
  M& operator/=(M o) {
    auto [inv, gcd] = extgcd(o.v_, Modulus);
    assert(gcd == 1);
    return *this *= inv;
  }
  M& operator+=(M o) {
    return v_ = int(v_ += o.v_ - Modulus) < 0 ? v_ + Modulus : v_, *this;
  }
  M& operator-=(M o) {
    return v_ = int(v_ -= o.v_) < 0 ? v_ + Modulus : v_, *this;
  }

  friend M operator++(M& a, int) { return std::exchange(a, ++M(a)); }
  friend M operator--(M& a, int) { return std::exchange(a, --M(a)); }
  friend M operator*(M a, M b) { return a *= b; }
  friend M operator/(M a, M b) { return a /= b; }
  friend M operator+(M a, M b) { return a += b; }
  friend M operator-(M a, M b) { return a -= b; }
  friend std::istream& operator>>(std::istream& is, M& x) {
    int64_t v;
    return is >> v, x = v, is;
  }
  friend std::ostream& operator<<(std::ostream& os, M x) { return os << x.v_; }
  friend bool operator==(M a, M b) { return a.v_ == b.v_; }
  friend bool operator!=(M a, M b) { return a.v_ != b.v_; }

 private:
  static std::array<int, 2> extgcd(int a, int b) {
    std::array x{1, 0};
    while (b) std::swap(x[0] -= a / b * x[1], x[1]), std::swap(a %= b, b);
    return {x[0], a};
  }

  uint32_t v_;
};

#pragma region my_template

struct Rep {
  struct I {
    int i;
    void operator++() { ++i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i < *o; }
  };
  const int l_, r_;
  Rep(int l, int r) : l_(l), r_(r) {}
  Rep(int n) : Rep(0, n) {}
  I begin() const { return {l_}; }
  I end() const { return {r_}; }
};
struct Per {
  struct I {
    int i;
    void operator++() { --i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i > *o; }
  };
  const int l_, r_;
  Per(int l, int r) : l_(l), r_(r) {}
  Per(int n) : Per(0, n) {}
  I begin() const { return {r_ - 1}; }
  I end() const { return {l_ - 1}; }
};

template <class F>
struct Fix : private F {
  Fix(F f) : F(f) {}
  template <class... Args>
  decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

template <class T = int>
T scan() {
  T res;
  std::cin >> res;
  return res;
}

template <class T, class U = T>
bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U = T>
bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

#ifndef LOCAL
#define DUMP(...) void(0)
template <int OnlineJudge, int Local>
constexpr int OjLocal = OnlineJudge;
#endif

using namespace std;

#define ALL(c) begin(c), end(c)

#pragma endregion

using Mint = ModularInt<int(1e9) + 7>;

constexpr int Limit = 1 << 20;

template <>
Mint& Mint::operator/=(Mint o) {
  static auto inv = [] {
    std::vector<Mint> res(Limit + 1);
    res[1] = 1;
    for (int l = 2; l <= Limit;) {
      int q = modulus() / l, r = std::min(modulus() / q, Limit) + 1;
      for (int i = l; i < r; ++i) res[i] = -q * res[modulus() - q * i];
      l = r;
    }
    return res;
  }();
  assert(o.v_);
  int v = o.v_;
  while (v > Limit) *this *= -(modulus() / std::exchange(v, modulus() % v));
  return *this *= inv[v];
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  int q = scan();
  vector s{scan<string>()};
  auto t = "$" + scan<string>();
  n = 1e5;
  t += string(n + 1 - size(t), '$');
  while (int(size(s.back())) < int(1e6))
    s.push_back(s.back() + t[size(s)] + s.back());
  RollingHash rh(ALL(s.back()));

  vector<Mint> p2(Limit + 1);
  p2[0] = 1;
  for (int i : Rep(Limit)) p2[i + 1] = p2[i] * 2;

  vector<Mint> ip2(Limit + 1);
  ip2[0] = 1;
  for (int i : Rep(Limit)) ip2[i + 1] = ip2[i] / 2;

  vector suff(26, vector<Mint>(size(t) + 1));
  for (int z : Rep(26))
    for (int i : Per(size(t)))
      suff[z][i] = (t[i] - 'a' == z ? ip2[i] : 0) + suff[z][i + 1];

  while (q--) {
    int k = scan();
    auto w = scan<string>();
    int ng = -1, ok = size(s);
    while (ok - ng > 1) {
      int mid = (ng + ok) / 2;
      (size(s[mid]) >= size(w) ? ok : ng) = mid;
    }
    if (ok > k) {
      cout << "0\n";
      continue;
    }

    auto rhw = RollingHash(ALL(w));

    Mint ans;
    for (int l : Rep(size(s[ok]) - size(w) + 1))
      ans += rh.get(l, l + size(w)) == rhw.get(0, size(w));
    ans *= ip2[ok];

    if (ok + 1 <= k) {
      for (int pos : Rep(size(w)))
        if (rhw.get(0, pos) == rh.get(size(rh) - pos, size(rh)))
          if (rhw.get(pos + 1, size(w)) == rh.get(0, size(w) - pos - 1)) {
            // for (int i : Rep(ok + 1, k + 1))
            //   if (t[i] == w[pos]) ans += ip2[i];
            ans += suff[w[pos] - 'a'][ok + 1] - suff[w[pos] - 'a'][k + 1];
          }
    }

    ans *= p2[k];
    cout << ans << '\n';
  }
}