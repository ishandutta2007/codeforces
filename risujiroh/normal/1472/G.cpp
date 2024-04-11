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
    int n = scan();
    vector<vector<int>> g(n);
    for (int m = scan(); m--;) {
      int a = scan() - 1;
      int b = scan() - 1;
      g[a].push_back(b);
    }
    vector<int> que{0};
    vector depth(n, -1);
    depth[0] = 0;
    vector<int> order;
    for (int z = 0; z < int(size(que)); ++z) {
      int v = que[z];
      order.push_back(v);
      for (int u : g[v])
        if (depth[u] == -1) {
          depth[u] = depth[v] + 1;
          que.push_back(u);
        }
    }
    reverse(ALL(order));
    vector<int> ans(n);
    for (int v : order) {
      ans[v] = depth[v];
      for (int u : g[v])
        if (depth[u] > depth[v]) {
          chmin(ans[v], ans[u]);
        } else {
          chmin(ans[v], depth[u]);
        }
    }
    for (int v : Rep(n)) cout << ans[v] << " \n"[v + 1 == n];
  }
}