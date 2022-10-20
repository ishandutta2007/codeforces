#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

struct stopwatch {
  clock_t t = clock();
  void restart() { t = clock(); }
  int elapsed() const { return (clock() - t) * 1000 / CLOCKS_PER_SEC; }
  void operator()(string s = "Time") const {
    cerr << s + ": " << elapsed() << " ms\n";
  }
} sw;

mt19937 mt_engine(chrono::steady_clock::now().time_since_epoch().count());
template <class T> enable_if_t<is_integral_v<T>, T> rng(T l, T r) {
  return uniform_int_distribution<T>(l, r - 1)(mt_engine);
}
template <class T> enable_if_t<is_floating_point_v<T>, T> rng(T l, T r) {
  return uniform_real_distribution<T>(l, r)(mt_engine);
}

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

auto chmin = [](auto&& a, auto b) { return b < a ? a = b, 1 : 0; };
auto chmax = [](auto&& a, auto b) { return a < b ? a = b, 1 : 0; };

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
  }
  vector d(n, vector(n, inf<int>));
  vector<int> que(n);
  for (int s = 0; s < n; ++s) {
    d[s][s] = 0;
    que[0] = s;
    for (int bg = 0, ed = 1; bg < ed; ) {
      int v = que[bg++];
      for (int to : g[v]) {
        if (chmin(d[s][to], d[s][v] + 1)) {
          que[ed++] = to;
        }
      }
    }
  }
  int mx = 0;
  vector<int> res;
  int iter = 0;
  while (sw.elapsed() < 4900) {
    ++iter;
    vector<vector<int>> vs(4);
    for (int v = 0; v < n; ++v) {
      vs[rng(0, 4)].push_back(v);
    }
    vector<int> dp(n, -inf<int>), nxt(n, -1);
    for (int t = 4; t--; ) {
      for (int i = 0; i < (int)size(vs[t]); ++i) {
        int v = vs[t][i];
        if (t == 3) {
          dp[v] = 0;
          continue;
        }
        for (int j = 0, sz = size(vs[t + 1]); j < sz; ++j) {
          int to = vs[t + 1][j];
          if (d[v][to] != inf<int> and chmax(dp[v], d[v][to] + dp[to])) {
            nxt[v] = to;
          }
        }
      }
    }
    int v = -1;
    for (int i = 0; i < (int)size(vs[0]); ++i) {
      if (dp[vs[0][i]] < 3) continue;
      if (v == -1 or dp[vs[0][i]] > dp[v]) {
        v = vs[0][i];
      }
    }
    if (v != -1 and chmax(mx, dp[v])) {
      res.clear();
      while (size(res) < 4) {
        res.push_back(v);
        v = nxt[v];
      }
    }
  }
  for (int i = 0; i < 4; ++i) {
    cout << res[i] + 1 << " \n"[i == 3];
  }
}