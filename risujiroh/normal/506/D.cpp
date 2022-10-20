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

  //  private:
  int _cc;
  std::vector<int> dat;
};

struct splitmix64_hash {
  static inline const uint64_t r =
      std::chrono::steady_clock::now().time_since_epoch().count();
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const { return splitmix64(x + r); }
  size_t operator()(std::pair<int, int> p) const {
    return operator()(size_t(p.first) << 32 | p.second);
  }
};
template <class Key, class T>
using hash_map = __gnu_pbds::gp_hash_table<Key, T, splitmix64_hash>;
template <class Key>
using hash_set = hash_map<Key, __gnu_pbds::null_type>;

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  constexpr int th = 300;

  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> edges(m);
  vector<int> cnt(m);
  for (auto&& [a, b, c] : edges) {
    cin >> a >> b >> c;
    --a, --b, --c;
    ++cnt[c];
  }

  vector<int> heavy;
  vector<dsu> d(m);
  for (int c : rep(m))
    if (cnt[c] >= th) {
      heavy.push_back(c);
      d[c] = dsu(n);
    }
  vector<vector<int>> vs(m);
  for (auto [a, b, c] : edges)
    if (cnt[c] >= th)
      d[c].unite(a, b);
    else
      vs[c].push_back(a), vs[c].push_back(b);

  int q;
  cin >> q;
  vector<array<int, 2>> queries(q);
  hash_map<pair<int, int>, int> ans;
  for (auto&& [u, v] : queries) {
    cin >> u >> v;
    --u, --v;
    if (u > v) swap(u, v);
    if (ans.find(pair{u, v}) != end(ans)) continue;
    int cur{};
    for (int c : heavy) cur += d[c].same(u, v);
    ans[{u, v}] = cur;
  }

  vector<vector<pair<int, int>>> es(m);
  for (auto [a, b, c] : edges) es[c].emplace_back(a, b);

  dsu ds(n);
  for (int c : rep(m))
    if (cnt[c] < th) {
      sort(begin(vs[c]), end(vs[c]));
      vs[c].erase(unique(begin(vs[c]), end(vs[c])), end(vs[c]));
      for (auto [u, v] : es[c]) ds.unite(u, v);
      for (int v : vs[c])
        for (int u : vs[c]) {
          if (u == v) break;
          if (ans.find(pair{u, v}) != end(ans)) ans[{u, v}] += ds.same(u, v);
        }
      for (int v : vs[c]) ds.dat[v] = -1;
    }

  for (auto [u, v] : queries) cout << ans[{u, v}] << '\n';
}