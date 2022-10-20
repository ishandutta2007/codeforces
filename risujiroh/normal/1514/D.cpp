#include <bits/stdc++.h>

struct Random : std::mt19937 {
  using std::mt19937::mt19937;
  using std::mt19937::operator();

  static int64_t gen_seed() {
    return std::chrono::steady_clock::now().time_since_epoch().count();
  }

  Random() : std::mt19937(gen_seed()) {}

  template <class Int>
  auto operator()(Int a, Int b)
      -> std::enable_if_t<std::is_integral_v<Int>, Int> {
    return std::uniform_int_distribution<Int>(a, b)(*this);
  }
  template <class Real>
  auto operator()(Real a, Real b)
      -> std::enable_if_t<std::is_floating_point_v<Real>, Real> {
    return std::uniform_real_distribution<Real>(a, b)(*this);
  }
} rng;

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

struct Mo {
  int n;
  vector<pair<int, int>> lr;
  Mo(int _n) : n(_n) {}
  void add(int l, int r) { lr.emplace_back(l, r); }
  template <class AL, class AR, class RL, class RR, class O>
  void run(AL add_left, AR add_right, RL remove_left, RR remove_right, O out) {
    int q = size(lr), bs = n / clamp<int>(sqrt(q * 2 / 3), 1, n);
    vector<int> ord(q);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int i, int j) {
      auto [li, ri] = lr[i];
      auto [lj, rj] = lr[j];
      li /= bs, lj /= bs;
      return li != lj ? li < lj : li & 1 ? ri > rj : ri < rj;
    });
    int l = 0, r = 0;
    for (int i : ord) {
      auto [li, ri] = lr[i];
      while (l > li) add_left(--l);
      while (r < ri) add_right(r++);
      while (l < li) remove_left(l++);
      while (r > ri) remove_right(--r);
      out(i);
    }
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  int q = scan();
  vector<int> a(n);
  for (auto&& e : a) e = scan() - 1;
  Mo mo(n);
  vector<int> l(q), r(q);
  for (int id : Rep(q)) {
    l[id] = scan() - 1;
    r[id] = scan();
    mo.add(l[id], r[id]);
  }

  int x = 0;

  vector<int> freq(n);
  auto add = [&](int i) -> void {
    ++freq[a[i]];
    ++x;
  };
  auto remove = [&](int i) -> void {
    --freq[a[i]];
    --x;
  };

  vector<int> ans(q);
  auto out = [&](int id) -> void {
    int y = 0;
    for (int _ = 30; _--;) {
      int i = rng(l[id], r[id] - 1);
      chmax(y, freq[a[i]]);
    }
    ans[id] = max(2 * y - x, 1);
  };

  mo.run(add, add, remove, remove, out);
  for (auto&& e : ans) cout << e << '\n';
}