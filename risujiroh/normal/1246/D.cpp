#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  VV<> ch(n);
  for (int v = 1; v < n; ++v) {
    int p; cin >> p;
    ch[p].push_back(v);
  }
  V<> h(n);
  {
    auto dfs = [&](auto& F, int v) -> void {
      for (int u : ch[v]) {
        F(F, u);
        h[v] = max(h[v], h[u] + 1);
      }
      sort(begin(ch[v]), end(ch[v]), [&](int l, int r) { return make_pair(h[l], l) < make_pair(h[r], r); });
    };
    dfs(dfs, 0);
  }
  V<> id(n + 1), inv(n);
  {
    int t = 0;
    auto dfs = [&](auto& F, int v) -> void {
      id[t] = v;
      inv[v] = t++;
      for (int u : ch[v]) {
        F(F, u);
      }
    };
    dfs(dfs, 0);
  }
  V<> res;
  {
    auto dfs = [&](auto& F, int v) -> void {
      int x = id[inv[v] + 1];
      for (int u : ch[v]) {
        F(F, u);
        x = res.back();
      }
      res.push_back(x);
    };
    dfs(dfs, 0);
  }
  for (int i = 0; i < n; ++i) {
    cout << id[i] << " \n"[i == n - 1];
  }
  int k = n - *max_element(begin(h), end(h)) - 1;
  cout << k << '\n';
  for (int i = 0; i < k; ++i) {
    cout << res[i] << " \n"[i == k - 1];
  }
}