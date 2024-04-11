#include <bits/stdc++.h>

#pragma region my_template

struct Rep {
  struct I {
    int i;
    void operator++() { ++i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i < *o; }
  };
  const int l, r;
  Rep(int _l, int _r) : l(_l), r(_r) {}
  Rep(int n) : Rep(0, n) {}
  I begin() const { return {l}; }
  I end() const { return {r}; }
};
struct Per {
  struct I {
    int i;
    void operator++() { --i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i > *o; }
  };
  const int l, r;
  Per(int _l, int _r) : l(_l), r(_r) {}
  Per(int n) : Per(0, n) {}
  I begin() const { return {r - 1}; }
  I end() const { return {l - 1}; }
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
  return std::cin >> res, res;
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

struct Seg {
  int l, r;
  double p;

  friend bool operator<(const Seg& a, const Seg& b) {
    return a.r - a.l < b.r - b.l;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan(), m = scan();
  vector<int> a(n);
  generate(ALL(a), scan<>);
  int off = *max_element(ALL(a)) - m;
  for (auto&& e : a) e -= off;
  vector<Seg> seg(m);
  for (auto&& [l, r, p] : seg) l = scan() - 1, r = scan(), p = scan<double>();
  seg.push_back({0, n, 0}), ++m;
  sort(ALL(seg));
  vector<vector<int>> ch(m + 1);
  vector dp(m, vector<double>(2 * m + 1));
  {
    vector to(n, -1), id(n, -1);
    for (int v : Rep(m)) {
      auto [l, r, p] = seg[v];
      int mx = -1;
      for (int i = l; i < r;)
        if (to[i] != -1) {
          ch[v].push_back(id[i]);
          i = to[i];
        } else {
          chmax(mx, a[i]);
          ++i;
        }
      fill(begin(dp[v]), begin(dp[v]) + (mx + 1), 1);
      to[l] = r;
      id[l] = v;
      for (int u : ch[v])
        for (int i : Rep(2 * m + 1)) dp[v][i] += (1 - dp[v][i]) * dp[u][i];
      for (int i : Per(1, 2 * m + 1)) dp[v][i] += p * (dp[v][i - 1] - dp[v][i]);
    }
  }
  cout << off + accumulate(1 + ALL(dp.back()), double{}) << '\n';
}