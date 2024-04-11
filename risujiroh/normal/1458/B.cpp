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

constexpr int Inf = 0x3f3f3f3f;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  vector f(n + 1, vector<int>(100 * n + 1, -Inf));
  vector nf(n + 1, vector<int>(100 * n + 1, -Inf));
  f[0][0] = 0;
  for (int _ = n; _--;) {
    int a = scan();
    int b = scan();
    for (int k : Rep(n + 1))
      for (int i : Rep(100 * n + 1)) {
        if (k < n and i + a <= 100 * n)
          chmax(nf[k + 1][i + a], f[k][i] + 2 * b);
        chmax(nf[k][i], f[k][i] + b);
      }
    swap(f, nf);
  }
  for (int k : Rep(1, n + 1)) {
    double ans = 0;
    for (int i : Rep(100 * n + 1)) chmax(ans, min(2 * i, f[k][i]));
    ans /= 2;
    cout << ans << " \n"[k == n];
  }
}