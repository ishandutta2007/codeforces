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

constexpr auto Inf = numeric_limits<int64_t>::max() / 2;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  vector d(n, vector(n, +Inf));
  for (int v : Rep(n)) d[v][v] = 0;
  vector<array<int, 3>> edges;
  for (int m = scan(); m--;) {
    int u = scan() - 1;
    int v = scan() - 1;
    int w = scan();
    chmin(d[u][v], w);
    chmin(d[v][u], w);
    edges.push_back({u, v, w});
  }
  vector l(n, vector<int64_t>(n));
  for (int q = scan(); q--;) {
    int s = scan() - 1;
    int t = scan() - 1;
    int x = scan();
    chmax(l[s][t], x);
    chmax(l[t][s], x);
  }

  for (int k : Rep(n))
    for (int i : Rep(n))
      for (int j : Rep(n)) chmin(d[i][j], d[i][k] + d[k][j]);

  vector mx(n, vector(n, -Inf));
  for (int s : Rep(n))
    for (int v : Rep(n))
      for (int t : Rep(n)) chmax(mx[s][v], l[s][t] - d[v][t]);

  int ans = 0;
  for (auto&& [u, v, w] : edges) {
    bool any = false;
    for (int s : Rep(n))
      if (mx[s][v] >= d[s][u] + w) {
        any = true;
        break;
      }
    for (int s : Rep(n))
      if (mx[s][u] >= d[s][v] + w) {
        any = true;
        break;
      }
    ans += any;
  }
  cout << ans << '\n';
}