#include <bits/stdc++.h>

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
  int n = scan();
  int q = scan();
  vector<int> a(n);
  generate(ALL(a), scan<>);

  auto lpf = linear_sieve(1e5).second;

  vector<vector<int>> pos(1e5 + 1);
  {
    for (int i : Rep(n)) {
      auto f = factor(a[i], lpf);
      for (auto&& [p, e] : rle(ALL(f))) pos[p].push_back(i);
    }
  }

  vector to(18, vector<int>(n + 1));
  to[0][n] = n;
  for (int i : Per(n)) {
    auto f = factor(a[i], lpf);
    to[0][i] = to[0][i + 1];
    for (auto&& [p, e] : rle(ALL(f))) {
      auto it = upper_bound(ALL(pos[p]), i);
      if (it != end(pos[p])) chmin(to[0][i], *it);
    }
  }
  for (int k : Rep(1, 18))
    for (int i : Rep(n + 1)) to[k][i] = to[k - 1][to[k - 1][i]];

  while (q--) {
    int l = scan() - 1;
    int r = scan();
    int ans = 1;
    for (int k : Per(18))
      if (to[k][l] < r) {
        l = to[k][l];
        ans += 1 << k;
      }
    cout << ans << '\n';
  }
}