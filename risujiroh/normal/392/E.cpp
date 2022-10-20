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

constexpr auto Inf = numeric_limits<int>::max() / 2;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  vector<int> v(n), w(n);
  generate(ALL(v), scan<>);
  generate(ALL(w), scan<>);

  vector f(n + 1, vector(n + 1, -Inf));
  vector g(n + 1, vector(n + 1, -Inf));

  for (int r : Rep(n + 1))
    for (int l : Per(r + 1)) {
      if (r - l == 0) {
        f[l][r] = 0;
        continue;
      }

      if (r - l == 1) {
        g[l][r] = 0;
      } else if (w[l] < w[r - 1]) {
        for (int i : Rep(l + 1, r))
          if (w[l] + 1 == w[i]) chmax(g[l][r], f[l + 1][i] + g[i][r]);
      } else if (w[l] > w[r - 1]) {
        for (int i : Rep(l + 1, r))
          if (w[l] - 1 == w[i]) chmax(g[l][r], f[l + 1][i] + g[i][r]);
      }

      for (int m : Rep(l + 1, r)) chmax(f[l][r], f[l][m] + f[m][r]);
      for (int i : Rep(l, r))
        if (w[l] <= w[i] and g[l][i + 1] != -Inf)
          if (w[i] >= w[r - 1] and g[i][r] != -Inf)
            if (int t = 2 * w[i] - w[l] - w[r - 1]; t < n)
              chmax(f[l][r], g[l][i + 1] + g[i][r] + v[t]);
    }

  vector mx(n + 1, -Inf);
  mx[0] = 0;
  for (int r : Rep(1, n + 1)) {
    mx[r] = mx[r - 1];
    for (int l : Per(r)) chmax(mx[r], mx[l] + f[l][r]);
  }
  cout << mx[n] << '\n';
}