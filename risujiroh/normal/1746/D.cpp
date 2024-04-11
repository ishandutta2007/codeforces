#include <bits/stdc++.h>

using namespace std::literals;

void solve(std::istream& is, std::ostream& os) {
  int n, k;
  is >> n >> k;
  std::vector<std::vector<int>> g(n);
  for (int v = 1; v < n; ++v) {
    int p;
    is >> p;
    --p;
    g[p].push_back(v);
  }
  std::vector<int> s(n);
  for (int& e : s) {
    is >> e;
  }

  using ll = long long;

  std::vector<std::map<int, ll>> memo(n);
  auto dfs = [&](auto self, int v, int x) -> ll {
    int d = int(g[v].size());
    if (d == 0) {
      return ll(x) * s[v];
    }
    if (memo[v].count(x)) {
      return memo[v][x];
    }
    int q = x / d;
    int r = x - q * d;
    if (r) {
      std::vector<ll> v0;
      v0.reserve(d);
      std::vector<ll> v1;
      v1.reserve(d);
      for (int u : g[v]) {
        v0.push_back(self(self, u, q));
        v1.push_back(self(self, u, q + 1));
      }
      std::vector<int> order(d);
      std::iota(order.begin(), order.end(), 0);
      std::sort(order.begin(), order.end(),
                [&](int i, int j) { return v1[j] - v0[j] < v1[i] - v0[i]; });
      ll ret = ll(x) * s[v];
      for (int i = 0; i < d; ++i) {
        ret += (i < r ? v1 : v0)[order[i]];
      }
      return memo[v][x] = ret;
    } else {
      ll ret = ll(x) * s[v];
      for (int u : g[v]) {
        ret += self(self, u, q);
      }
      return memo[v][x] = ret;
    }
  };

  os << dfs(dfs, 0, k) << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  while (T--) {
    solve(std::cin, std::cout);
  }
}