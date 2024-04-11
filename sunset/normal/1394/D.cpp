#include <bits/stdc++.h>

using namespace std;

const long long INF = 1ll << 60;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    cin >> v >> u;
    --v; --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += (long long) t[i] * g[i].size();
  }
  vector<long long> up(n, -INF);
  vector<long long> down(n, -INF);
  function<void(int, int)> dfs = [&](int v, int p) {
    long long already = 0;
    int in = 0, out = 0;
    vector<int> son;
    for (int u : g[v]) {
      if (u != p) {
        dfs(u, v);
        if (h[u] < h[v]) {
          already += up[u];
          ++in;
        } else if (h[u] > h[v]) {
          already += down[u];
          ++out;
        } else {
          son.push_back(u);
        }
      }
    }
    sort(son.begin(), son.end(), [&](int a, int b) {
      return down[a] - up[a] < down[b] - up[b];
    });
    vector<long long> pref(son.size() + 1);
    for (int i = 0; i < (int) son.size(); ++i) {
      pref[i + 1] = pref[i] + up[son[i]];
    }
    vector<long long> suff(son.size() + 1);
    for (int i = (int) son.size() - 1; ~i; --i) {
      suff[i] = suff[i + 1] + down[son[i]];
    }
    if (p != -1 || h[v] <= h[p]) {
      if (p != -1) {
        out++;
      }
      for (int i = 0; i <= (int) son.size(); ++i) {
        int uu = in + i;
        int dd = out + son.size() - i;
        up[v] = max(up[v], already + (long long) t[v] * min(uu, dd) + pref[i] + suff[i]);
      }
      if (p != -1) {
        out--;
      }
    }
    if (p != -1 || h[v] >= h[p]) {
      if (p != -1) {
        in++;
      }
      for (int i = 0; i <= (int) son.size(); ++i) {
        int uu = in + i;
        int dd = out + son.size() - i;
        down[v] = max(down[v], already + (long long) t[v] * min(uu, dd) + pref[i] + suff[i]);
      }
      if (p != -1) {
        in--;
      }
    }
  };
  dfs(0, -1);
  cout << ans - max(up[0], down[0]) << "\n";
  return 0;
}