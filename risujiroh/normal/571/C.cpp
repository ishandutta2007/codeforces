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

struct bipartite_matching {
  bipartite_matching(int h = 0, int w = 0) : g(h), r(h, -1), c(w, -1), vis(h) {}

  void add(int i, int j) {
    assert(0 <= i), assert(i < int(size(r)));
    assert(0 <= j), assert(j < int(size(c)));
    g[i].push_back(j);
  }
  std::vector<std::pair<int, int>> run() {
    for (bool updated = true; ++t, std::exchange(updated, false);)
      for (int i = size(r); i--;)
        if (r[i] == -1) updated |= dfs(i);
    std::vector<std::pair<int, int>> res;
    for (int i = 0; i < int(size(r)); ++i)
      if (r[i] != -1) res.emplace_back(i, r[i]);
    return res;
  }

 private:
  int t = 0;
  std::vector<std::vector<int>> g;
  std::vector<int> r, c, vis;

  bool dfs(int i) {
    if (std::exchange(vis[i], t) == t) return false;
    for (int j : g[i])
      if (c[j] == -1) return r[i] = j, c[j] = i, true;
    for (int j : g[i])
      if (dfs(c[j])) return r[i] = j, c[j] = i, true;
    return false;
  }
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> clause(n);
  vector<vector<array<int, 2>>> where(m);
  for (int i : rep(n)) {
    int k;
    cin >> k;
    clause[i].resize(k);
    for (auto&& e : clause[i]) {
      cin >> e;
      if (e > 0) {
        --e;
        where[e].push_back({i, +1});
      } else {
        e = -e;
        --e;
        where[e].push_back({i, -1});
      }
    }
  }
  vector good(n, false);
  vector<pair<int, int>> es(m, {-1, -1});
  for (int j : rep(m)) {
    assert(size(where[j]) <= 2);
    if (size(where[j]) == 2 and where[j][0][1] != where[j][1][1]) {
      es[j] = es.emplace_back(where[j][0][0], where[j][1][0]);
    } else {
      for (auto [i, t] : where[j]) {
        good[i] = true;
      }
    }
  }
  vector<int> vs;
  for (int v : rep(n)) {
    if (good[v]) continue;
    vs.push_back(v);
  }
  auto zip = [&](int v) -> int {
    return lower_bound(begin(vs), end(vs), v) - begin(vs);
  };

  bipartite_matching bm(size(vs), m);
  for (int j : rep(m)) {
    if (es[j].first == -1) continue;
    int u = zip(es[j].first);
    int v = zip(es[j].second);
    if (not good[es[j].first]) bm.add(u, j);
    if (not good[es[j].second]) bm.add(v, j);
  }
  auto matching = bm.run();
  if (size(matching) < size(vs)) {
    cout << "NO\n";
    exit(0);
  }
  cout << "YES\n";

  vector<int> j2v(m, -1);
  for (auto [v, j] : matching) {
    j2v[j] = v;
  }

  for (int j : rep(m)) {
    if (size(where[j]) == 2 and where[j][0][1] != where[j][1][1]) {
      if (j2v[j] == -1) {
        cout << 0;
        continue;
      }
      int i = vs[j2v[j]];
      int x = where[j][1][0] == i;
      assert(where[j][x][0] == i);
      cout << (where[j][x][1] > 0);
    } else {
      cout << (empty(where[j]) or where[j][0][1] > 0);
    }
  }
  cout << '\n';
}