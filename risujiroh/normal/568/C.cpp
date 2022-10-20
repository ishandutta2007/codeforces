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

template <size_t N>
std::vector<int> find_scc(const std::vector<std::bitset<N>>& g) {
  int n = size(g);
  assert(n <= int(N));
  std::vector<int> comp_id(n);
  int cnt{};
  std::stack<int, std::vector<int>> stk;
  std::bitset<N> visited, done;
  std::vector<std::bitset<N>> reachable(n);
  auto dfs = [&](auto&& self, int v) -> void {
    stk.push(v);
    auto prv = visited;
    visited[v] = 1;
    reachable[v][v] = 1;
    while (true) {
      int u = (g[v] & ~visited)._Find_first();
      if (u >= n) break;
      self(self, u);
      reachable[v] |= reachable[u];
    }
    reachable[v] |= g[v] & ~done;
    if ((reachable[v] & prv).none()) {
      while (true) {
        int u = stk.top();
        stk.pop();
        comp_id[u] = cnt;
        done[u] = 1;
        if (u == v) break;
      }
      ++cnt;
    }
  };
  for (int v = 0; v < n; ++v)
    if (visited[v] == 0) dfs(dfs, v);
  for (auto&& e : comp_id) e = cnt - e - 1;
  return comp_id;
}

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  string type;
  cin >> type;
  int n, m;
  cin >> n >> m;
  vector<bitset<400>> base_g(2 * n);
  while (m--) {
    int p1, p2;
    char t1, t2;
    cin >> p1 >> t1 >> p2 >> t2;
    --p1, --p2;
    int u = 2 * p1 + (t1 == 'C');
    int v = 2 * p2 + (t2 == 'C');
    base_g[u][v] = 1;
    base_g[v ^ 1][u ^ 1] = 1;
  }
  string s;
  cin >> s;

  auto feasible = [&](const auto& g) -> bool {
    auto comp_id = find_scc(g);
    for (int i : rep(n))
      if (comp_id[2 * i] == comp_id[2 * i + 1]) return false;
    return true;
  };

  auto can_match = [&](int k) -> bool {
    auto g = base_g;
    for (int i : rep(k)) {
      int v = 2 * i + (type[s[i] - 'a'] == 'C');
      g[v ^ 1][v] = 1;
    }
    for (int i : rep(k, n)) {
      int l = i == k ? s[i] - 'a' + 1 : 0;
      for (char c : {'V', 'C'})
        if (type.substr(l) == string(size(type) - l, c)) {
          int v = 2 * i + (c == 'C');
          g[v ^ 1][v] = 1;
        }
    }
    return feasible(g);
  };

  int mx = n;
  while (mx >= 0 and not can_match(mx)) --mx;
  if (mx == -1) {
    cout << "-1\n";
    exit(0);
  }

  string ans(n, '?');
  auto g = base_g;
  for (int i : rep(mx)) {
    int v = 2 * i + (type[s[i] - 'a'] == 'C');
    g[v ^ 1][v] = 1;
    ans[i] = s[i];
  }
  for (int i : rep(mx, n)) {
    int l = i == mx ? s[i] - 'a' + 1 : 0;
    array<bool, 2> first;
    first.fill(true);
    for (int j : rep(l, size(type)))
      if (exchange(first[type[j] == 'C'], false)) {
        int v = 2 * i + (type[j] == 'C');
        g[v ^ 1][v] = 1;
        if (feasible(g)) {
          ans[i] = 'a' + j;
          break;
        }
        g[v ^ 1][v] = 0;
      }
  }
  cout << ans << '\n';
}