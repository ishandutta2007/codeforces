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
  for (int tt = scan(); tt--;) {
    array<array<int64_t, 2>, 4> points;
    for (int i : Rep(4))
      for (int z : Rep(2)) points[i][z] = scan();

    sort(ALL(points));

    auto f = [&](int64_t len) -> int64_t {
      int64_t res = 0;
      for (int z : Rep(2)) {
        array<int64_t, 4> d;
        for (int i : Rep(4)) {
          int64_t t = 0;
          if (z == 0) {
            if (i & 1) t += len;
          } else {
            if (i & 2) t += len;
          }
          d[i] = points[i][z] - t;
        }
        sort(ALL(d));
        for (auto e : d) res += abs(e - d[1]);
      }
      return res;
    };

    int64_t ans = 1e18;
    do {
      int64_t l = -1, r = 2e9;
      while (r - l > 2) {
        int m = (l + r) / 2;
        if (f(m) > f(m + 1))
          l = m;
        else
          r = m + 1;
      }
      chmin(ans, f(l + 1));
    } while (next_permutation(ALL(points)));
    cout << ans << '\n';
  }
}