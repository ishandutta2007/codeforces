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
  int h = scan();
  int w = scan();
  int q = scan();
  vector<string> s(h);
  generate(ALL(s), scan<string>);

  vector suff(h + 1, vector<int>(w + 1));
  for (int i : Rep(h))
    for (int j : Rep(w)) suff[i][j] = s[i][j] == '1';
  for (int i : Rep(h))
    for (int j : Per(w)) suff[i][j] += suff[i][j + 1];
  for (int j : Rep(w))
    for (int i : Per(h)) suff[i][j] += suff[i + 1][j];

  vector good(h, vector(h + 1, vector(w, vector<bool>(w + 1))));
  for (int li : Rep(h))
    for (int ri : Rep(li + 1, h + 1))
      for (int lj : Rep(w))
        for (int rj : Rep(lj + 1, w + 1)) {
          int sum = 0;
          sum += suff[li][lj];
          sum -= suff[li][rj];
          sum -= suff[ri][lj];
          sum += suff[ri][rj];
          good[li][ri][lj][rj] = sum == 0;
        }

  vector f(h, vector(h + 1, vector(w, vector<int>(w + 1))));
  for (int li : Rep(h))
    for (int ri : Rep(li + 1, h + 1))
      for (int lj : Per(w))
        for (int rj : Rep(lj + 1, w + 1)) {
          f[li][ri][lj][rj] = good[li][ri][lj][rj];
          if (rj - lj == 1) continue;
          f[li][ri][lj][rj] += f[li][ri][lj + 1][rj];
          f[li][ri][lj][rj] += f[li][ri][lj][rj - 1];
          f[li][ri][lj][rj] -= f[li][ri][lj + 1][rj - 1];
        }

  while (q--) {
    int li = scan() - 1;
    int lj = scan() - 1;
    int ri = scan();
    int rj = scan();
    int ans = 0;
    for (int l : Rep(li, ri))
      for (int r : Rep(l + 1, ri + 1)) ans += f[l][r][lj][rj];
    // for (int lx : Rep(li, ri))
    //   for (int rx : Rep(lx + 1, ri + 1))
    //     for (int ly : Rep(lj, rj))
    //       for (int ry : Rep(ly + 1, rj + 1)) ans += good[lx][rx][ly][ry];
    cout << ans << '\n';
  }
}