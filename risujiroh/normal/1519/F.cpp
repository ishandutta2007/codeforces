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
  int m = scan();
  vector<int> a(n), b(m);
  generate(ALL(a), scan<>);
  generate(ALL(b), scan<>);
  vector c(n, vector<int>(m));
  for (auto&& e : c) generate(ALL(e), scan<>);

  map<vector<int>, int> f;
  f[vector<int>(m)] = 0;
  for (int i : Rep(n)) {
    vector p{1};
    p.insert(end(p), a[i], 0);
    p.insert(end(p), m, 1);
    vector<int> pos;
    map<vector<int>, int> nf;
    do {
      pos.clear();
      for (int z : Rep(size(p)))
        if (p[z]) pos.push_back(z);
      for (auto&& [v, mx] : f) {
        auto nv = v;
        auto nmx = mx;
        bool ok = true;
        for (int j : Rep(m)) {
          nv[j] += pos[j + 1] - pos[j] - 1;
          if (pos[j] + 1 == pos[j + 1]) nmx += c[i][j];
          ok &= nv[j] <= b[j];
        }
        if (ok) chmax(nf[nv], nmx);
      }
    } while (next_permutation(1 + ALL(p) - 1));
    f = move(nf);
  }

  int ans = -Inf;
  for (auto&& [v, mx] : f) chmax(ans, mx);
  if (ans == -Inf) {
    cout << "-1\n";
  } else {
    ans = -ans;
    for (auto&& e : c) ans += accumulate(ALL(e), 0);
    cout << ans << '\n';
  }
}