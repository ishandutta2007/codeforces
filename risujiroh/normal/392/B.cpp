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
  array<array<int64_t, 3>, 3> t;
  for (int i : Rep(3)) generate(ALL(t[i]), scan<>);
  array<array<int64_t, 3>, 3> f{};
  for (int n = scan(); n--;) {
    array<array<int64_t, 3>, 3> nf;
    for (int i : Rep(3)) {
      for (int j : Rep(3)) {
        if (i == j) continue;
        int k = i ^ j ^ 3;
        nf[i][j] = f[i][k] + t[i][j] + f[k][j];
        chmin(nf[i][j], f[i][j] + t[i][k] + f[j][i] + t[k][j] + f[i][j]);
      }
    }
    f = nf;
    for (int _ = 100; _--;)
      for (int i : Rep(3))
        for (int j : Rep(3)) {
          if (i == j) continue;
          int k = i ^ j ^ 3;
          chmin(f[i][j], f[i][k] + f[k][j]);
        }
  }
  cout << f[0][2] << '\n';
}