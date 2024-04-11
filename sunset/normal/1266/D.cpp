#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> d(n);
  for (int i = 0; i < m; ++i) {
    int v, u, w;
    cin >> v >> u >> w;
    d[--v] += w;
    d[--u] -= w;
  }
  vector<tuple<int, int, long long>> ans;
  for (int i = 0, j = 0; i < n; ++i) {
    while (d[i] > 0) {
      while (j < n && d[j] >= 0) {
        j++;
      }
      long long take = min(d[i], -d[j]);
      ans.emplace_back(i, j, take);
      d[i] -= take;
      d[j] += take;
    }
  }
  cout << ans.size() << "\n";
  for (auto p : ans) {
    cout << get<0>(p) + 1 << " " << get<1>(p) + 1 << " " << get<2>(p) << "\n";
  }
  return 0;
}