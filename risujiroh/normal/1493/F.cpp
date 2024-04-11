#include <bits/stdc++.h>

std::pair<std::vector<int>, std::vector<int>> linear_sieve(int n) {
  std::vector<int> primes, lpf(n + 1);
  for (int d = 2; d <= n; ++d) {
    if (lpf[d] == 0) lpf[d] = d, primes.push_back(d);
    for (int p : primes) {
      if (p * d > n or p > lpf[d]) break;
      lpf[p * d] = p;
    }
  }
  return {primes, lpf};
}
std::vector<int> factor(int n, const std::vector<int>& lpf) {
  assert(n >= 1);
  std::vector<int> res;
  for (; n > 1; n /= res.back()) res.push_back(lpf[n]);
  return res;
}

template <class ForwardIterator,
          class T = typename std::iterator_traits<ForwardIterator>::value_type>
std::vector<std::pair<T, int>> rle(ForwardIterator first,
                                   ForwardIterator last) {
  std::vector<std::pair<T, int>> res;
  int n = 0;
  for (auto it = first; it != last; ++it)
    n += std::next(it) == last or not(*it == *std::next(it));
  res.reserve(n);
  for (; first != last; ++first)
    if (std::empty(res) or not(res.back().first == *first))
      res.emplace_back(*first, 1);
    else
      ++res.back().second;
  return res;
}

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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  auto [primes, lpf] = linear_sieve(1000);
  int h = scan();
  int w = scan();

  auto query = [&](int a, int b, int i0, int j0, int i1, int j1) -> bool {
    cout << '?';
    cout << ' ' << a;
    cout << ' ' << b;
    cout << ' ' << i0 + 1;
    cout << ' ' << j0 + 1;
    cout << ' ' << i1 + 1;
    cout << ' ' << j1 + 1;
    cout << endl;
    return scan();
  };

  int ans = 1, dh = -1;

  {
    auto check = [&](int d) -> bool {
      assert(h % d == 0);
      int n = h / d;
      assert(n >= 2);
      if (n & 1) {
        if (not query(n / 2 * d, w, 0, 0, n / 2 * d, 0)) return false;
        if (not query(n / 2 * d, w, 0, 0, (n / 2 + 1) * d, 0)) return false;
      } else {
        if (not query(n / 2 * d, w, 0, 0, n / 2 * d, 0)) return false;
        if (n > 2 and not query((n / 2 - 1) * d, w, 0, 0, (n / 2 - 1) * d, 0))
          return false;
      }
      return true;
    };

    auto f = factor(h, lpf);
    int d = h;
    for (auto&& [p, e] : rle(ALL(f)))
      while (d % p == 0 and check(d / p)) d /= p;

    auto t = factor(h / d, lpf);
    for (auto&& [p, e] : rle(ALL(t))) ans *= e + 1;

    dh = d;
  }

  {
    auto check = [&](int d) -> bool {
      assert(w % d == 0);
      int n = w / d;
      assert(n >= 2);
      if (dh == h) {
        if (n & 1) {
          if (not query(h, n / 2 * d, 0, 0, 0, n / 2 * d)) return false;
          if (not query(h, n / 2 * d, 0, 0, 0, (n / 2 + 1) * d)) return false;
        } else {
          if (not query(h, n / 2 * d, 0, 0, 0, n / 2 * d)) return false;
          if (n > 2 and not query(h, (n / 2 - 1) * d, 0, 0, 0, (n / 2 - 1) * d))
            return false;
        }
      } else {
        if (not query(dh, (n - 1) * d, 0, 0, dh, d)) return false;
      }
      return true;
    };

    auto f = factor(w, lpf);
    int d = w;
    for (auto&& [p, e] : rle(ALL(f)))
      while (d % p == 0 and check(d / p)) d /= p;

    auto t = factor(w / d, lpf);
    for (auto&& [p, e] : rle(ALL(t))) ans *= e + 1;
  }

  cout << "! " << ans << endl;
}