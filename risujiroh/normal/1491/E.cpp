#include <bits/stdc++.h>

struct Random : std::mt19937 {
  using std::mt19937::mt19937;
  using std::mt19937::operator();

  static int64_t gen_seed() {
    return std::chrono::steady_clock::now().time_since_epoch().count();
  }

  Random() : std::mt19937(gen_seed()) {}

  template <class Int>
  auto operator()(Int a, Int b)
      -> std::enable_if_t<std::is_integral_v<Int>, Int> {
    return std::uniform_int_distribution<Int>(a, b)(*this);
  }
  template <class Real>
  auto operator()(Real a, Real b)
      -> std::enable_if_t<std::is_floating_point_v<Real>, Real> {
    return std::uniform_real_distribution<Real>(a, b)(*this);
  }
} rng;

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
  int n = scan();
  vector<array<int, 2>> edges(n - 1);
  vector<vector<int>> g(n);
  for (int id : Rep(n - 1)) {
    auto&& [u, v] = edges[id];
    u = scan() - 1;
    v = scan() - 1;
    g[u].push_back(id);
    g[v].push_back(id);
  }
  auto other = [&](int id, int v) -> int {
    assert(id != -1);
    return v ^ edges[id][0] ^ edges[id][1];
  };

  vector f{1, 2};
  while (f.back() < n) f.push_back(f[size(f) - 2] + f.back());

  vector alive(n - 1, true);

  vector<int> sub(n), prv(n);

  auto solve = Fix([&](auto self, int root, int sz) -> bool {
    if (not binary_search(ALL(f), sz)) return false;
    if (sz < 5) return true;
    int f2 = lower_bound(ALL(f), sz)[-2];
    int f1 = lower_bound(ALL(f), sz)[-1];
    int r = -1;
    Fix([&](auto dfs, int v, int pe) -> void {
      sub[v] = 1;
      prv[v] = pe;
      for (int id : g[v])
        if (alive[id] and id != pe) {
          int u = other(id, v);
          dfs(u, id);
          sub[v] += sub[u];
        }
      if (sub[v] == f2 or sub[v] == f1) r = v;
    })(root, -1);
    if (r == -1) return false;
    if (sub[r] == f2 or sub[r] == f1) {
      alive[prv[r]] = false;
      int t = other(prv[r], r);
      int sr = sub[r];
      int st = sz - sub[r];
      return self(r, sr) and self(t, st);
    }
    return false;
  });

  vector<int> ids(n - 1);
  iota(ALL(ids), 0);
  cout << (solve(0, n) ? "YES\n" : "NO\n");
}