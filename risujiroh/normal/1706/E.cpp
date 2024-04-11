#include <bits/stdc++.h>

void solve(std::istream&, std::ostream&);

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    solve(std::cin, std::cout);
  }
}

void solve(std::istream& is, std::ostream& os) {
  int n, m, q;
  is >> n >> m >> q;

  std::vector<int> pv(n, -1);
  std::vector<int> pe(n, -1);

  auto root = [&](int v) -> int {
    while (0 <= pv[v]) {
      v = pv[v];
    }
    return v;
  };

  for (int e = 0; e < m; ++e) {
    int u, v;
    is >> u >> v;
    --u;
    --v;

    u = root(u);
    v = root(v);

    if (u == v) {
      continue;
    }

    if (-pv[u] < -pv[v]) {
      std::swap(u, v);
    }

    pv[u] += pv[v];
    pv[v] = u;
    pe[v] = e;
  }

  std::vector<int> depth(n, -1);
  {
    auto calc_depth = [&](auto self, int v) -> void {
      if (depth[v] == -1) {
        self(self, pv[v]);
        depth[v] = depth[pv[v]] + 1;
      }
    };

    depth[root(0)] = 0;
    for (int v = 0; v < n; ++v) {
      calc_depth(calc_depth, v);
    }
  }

  auto get_max = [&](int u, int v) -> int {
    int ret = -1;
    while (u != v) {
      if (depth[v] < depth[u]) {
        std::swap(u, v);
      }
      ret = std::max(ret, pe[v]);
      v = pv[v];
    }
    return ret;
  };

  std::vector<int> seg(2 * n, -1);
  for (int v = 0; v + 1 < n; ++v) {
    seg[n + v] = get_max(v, v + 1);
  }
  for (int i = n; 1 < i--;) {
    seg[i] = std::max(seg[2 * i], seg[2 * i + 1]);
  }

  while (q--) {
    int l, r;
    is >> l >> r;
    --l;
    --r;

    int ans = -1;

    l += n;
    r += n;
    while (l < r) {
      if (l & 1) {
        ans = std::max(ans, seg[l]);
        ++l;
      }
      if (r & 1) {
        --r;
        ans = std::max(ans, seg[r]);
      }
      l >>= 1;
      r >>= 1;
    }

    os << ans + 1 << " \n"[q == 0];
  }
}