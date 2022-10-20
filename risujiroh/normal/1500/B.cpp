#include <bits/stdc++.h>

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
  int64_t n = scan();
  int64_t m = scan();
  int64_t k = scan<int64_t>();
  vector<int> a(n), b(m);
  for (auto&& e : a) e = scan() - 1;
  for (auto&& e : b) e = scan() - 1;
  if (n < m) {
    swap(n, m);
    swap(a, b);
  }

  vector where(2 * n, -1);
  for (int j : Rep(m)) where[b[j]] = j;

  vector<int> cnt(m);
  for (int i : Rep(n)) {
    if (where[a[i]] == -1) continue;
    auto r = (where[a[i]] - i) % m;
    if (r < 0) r += m;
    ++cnt[r];
  }

  int64_t ans = 0;

  {
    int64_t sum = 0;
    for (int x : Rep(m / gcd(n, m))) {
      sum += n - cnt[x * n % m];
    }
    auto t = (k - 1) / sum;
    k -= sum * t;
    ans += lcm(n, m) * t;
  }

  for (int x : Rep(m / gcd(n, m))) {
    if (n - cnt[x * n % m] < k) {
      k -= n - cnt[x * n % m];
      ans += n;
      continue;
    }
    for (int i : Rep(n)) {
      ++ans;
      k -= a[i] != b[(x * n + i) % m];
      if (k == 0) break;
    }
    break;
  }

  cout << ans << '\n';
}