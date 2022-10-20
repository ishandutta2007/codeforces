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
  int n;
  cin >> n;
  vector<string> s(n), t(n);
  map<string, int> mp;
  for (int i : rep(n)) {
    string a, b;
    cin >> a >> b;
    s[i] = a.substr(0, 3);
    t[i] = a.substr(0, 2) + b[0];
    ++mp[s[i]];
  }
  vector<bitset<2000>> g(2 * n);
  for (int i : rep(n)) {
    if (mp[s[i]] > 1) g[2 * i][2 * i + 1] = 1;
    for (int j : rep(n))
      if (i != j) {
        if (s[i] == s[j]) g[2 * i][2 * j + 1] = 1;
        if (s[i] == t[j]) g[2 * i][2 * j] = 1;
        if (t[i] == s[j]) g[2 * i + 1][2 * j + 1] = 1;
        if (t[i] == t[j]) g[2 * i + 1][2 * j] = 1;
      }
  }
  auto comp_id = find_scc(g);
  for (int i : rep(n))
    if (comp_id[2 * i] == comp_id[2 * i + 1]) {
      cout << "NO\n";
      exit(0);
    }
  cout << "YES\n";
  for (int i : rep(n))
    if (comp_id[2 * i] < comp_id[2 * i + 1])
      cout << t[i] << '\n';
    else
      cout << s[i] << '\n';
}