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
  int h = scan();
  int w = scan();
  int k = scan();
  if (k & 1) {
    while (h--)
      for (int j : Rep(w)) cout << -1 << " \n"[j + 1 == w];
    exit(0);
  }
  k /= 2;
  vector hori(h, vector<int>(w - 1));
  for (auto&& e : hori) generate(ALL(e), scan<>);
  vector vert(h - 1, vector<int>(w));
  for (auto&& e : vert) generate(ALL(e), scan<>);
  vector f(h, vector<int>(w));
  while (k--) {
    vector nf(h, vector(w, +Inf));
    for (int i : Rep(h))
      for (int j : Rep(w)) {
        if (i + 1 < h) chmin(nf[i][j], vert[i][j] + f[i + 1][j]);
        if (j + 1 < w) chmin(nf[i][j], hori[i][j] + f[i][j + 1]);
        if (i) chmin(nf[i][j], vert[i - 1][j] + f[i - 1][j]);
        if (j) chmin(nf[i][j], hori[i][j - 1] + f[i][j - 1]);
      }
    f = move(nf);
  }
  for (auto&& e : f)
    for (int j : Rep(w)) cout << 2 * e[j] << " \n"[j + 1 == w];
}