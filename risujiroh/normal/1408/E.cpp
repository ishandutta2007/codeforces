// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt")
// #define NDEBUG

#include <bits/extc++.h>
#include <x86intrin.h>

struct rep {
  struct iter {
    int i;
    constexpr void operator++() { ++i; }
    constexpr int operator*() const { return i; }
    friend constexpr bool operator!=(iter a, iter b) { return *a != *b; }
  };
  const int l, r;
  constexpr rep(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  constexpr rep(int n) : rep(0, n) {}
  constexpr iter begin() const { return {l}; }
  constexpr iter end() const { return {r}; }
};
struct per {
  struct iter {
    int i;
    constexpr void operator++() { --i; }
    constexpr int operator*() const { return i; }
    friend constexpr bool operator!=(iter a, iter b) { return *a != *b; }
  };
  const int l, r;
  constexpr per(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  constexpr per(int n) : per(0, n) {}
  constexpr iter begin() const { return {r - 1}; }
  constexpr iter end() const { return {l - 1}; }
};
template <class T, class U>
constexpr bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U>
constexpr bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

struct dsu {
  dsu() {}
  explicit dsu(int n) : _cc(n), dat(n, -1) {}

  int size() const { return std::size(dat); }
  int root(int v) {
    assert(0 <= v), assert(v < size());
    return dat[v] < 0 ? v : dat[v] = root(dat[v]);
  }
  std::pair<int, int> unite(int u, int v) {
    assert(0 <= u), assert(u < size());
    assert(0 <= v), assert(v < size());
    u = root(u), v = root(v);
    if (u == v) return {u, -1};
    --_cc;
    if (-dat[u] < -dat[v]) std::swap(u, v);
    dat[u] += dat[v];
    dat[v] = u;
    return {u, v};
  }
  bool same(int u, int v) {
    assert(0 <= u), assert(u < size());
    assert(0 <= v), assert(v < size());
    return root(u) == root(v);
  }
  int size(int v) {
    assert(0 <= v), assert(v < size());
    return -dat[root(v)];
  }
  int cc() const { return _cc; }

 private:
  int _cc;
  std::vector<int> dat;
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int m, n;
  cin >> m >> n;
  vector<int> a(m), b(n);
  for (auto&& e : a) cin >> e;
  for (auto&& e : b) cin >> e;
  vector<array<int, 3>> v;
  int64_t ans{};
  for (int i : rep(m)) {
    int sz;
    cin >> sz;
    while (sz--) {
      int j;
      cin >> j;
      --j;
      v.push_back({a[i] + b[j], i, j});
      ans += v.back()[0];
    }
  }
  sort(begin(v), end(v), greater{});

  dsu d(n);
  vector last(m, -1);
  for (auto [val, i, j] : v) {
    if (last[i] != -1 and d.same(last[i], j)) continue;
    ans -= val;
    if (last[i] != -1) d.unite(last[i], j);
    last[i] = j;
  }
  cout << ans << '\n';
}