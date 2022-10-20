#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


template<class Int> V<Int> sieve(Int a, Int b) {
  a = max<Int>(2, a); V<Int> res; Int q = ceil(sqrt(b));
  V<bool> mem(b - a, true), sub(q - 2, true);
  for (Int i = 2; i < q; ++i) {
    if (sub[i - 2]) {
      for (Int j = max(i, (a + i - 1) / i) * i; j < b; j += i) mem[j - a] = false;
      for (Int j = i * i; j < q; j += i) sub[j - 2] = false;
    }
  }
  for (Int i = a; i < b; ++i) if (mem[i - a]) res.push_back(i);
  return res;
}

template<class Int> map<Int, int> factor(Int n) {
  map<Int, int> res;
  for (Int i = 2; i * i <= n; ++i) while (n % i == 0) ++res[i], n /= i;
  if (n != 1) ++res[n];
  return res;
}

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  auto p = sieve<int>(2, 2e5);
  VV<> vs(p.size());
  V<> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    auto mp = factor(a[i]);
    for (const auto& e : mp) {
      vs[lower_bound(begin(p), end(p), e.first) - begin(p)].push_back(i);
    }
  }
  VV<> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int res = 0;
  for (const auto& v : vs) {
    int m = v.size();
    if (m == 0) continue;
    VV<> h(m);
    for (int i = 0; i < m; ++i) {
      for (int w : g[v[i]]) if (w > v[i] and binary_search(begin(v), end(v), w)) {
        int j = lower_bound(begin(v), end(v), w) - begin(v);
        h[i].push_back(j);
        h[j].push_back(i);
      }
    }
    V<> dist(m, -1);
    V<> vv;
    auto dfs = [&](const auto& dfs, int v, int p, bool f = false) -> void {
      if (f) vv.push_back(v);
      for (int w : h[v]) if (w != p) {
        dist[w] = dist[v] + 1;
        dfs(dfs, w, v, f);
      }
    };
    for (int i = 0; i < m; ++i) if (dist[i] == -1) {
      dist[i] = 0;
      V<>().swap(vv);
      dfs(dfs, i, -1, true);
      int k = vv.size();
      int vd = -1, mx = -1;
      for (int j = 0; j < k; ++j) {
        if (dist[vv[j]] > mx) {
          mx = dist[vv[j]];
          vd = vv[j];
        }
        dist[vv[j]] = -1;
      }
      dist[vd] = 0;
      dfs(dfs, vd, -1);
      int curr = -1;
      for (int j = 0; j < k; ++j) if (dist[vv[j]] > curr) {
        curr = dist[vv[j]];
      }
      res = max(res, curr + 1);
    }
  }
  cout << res << '\n';
}