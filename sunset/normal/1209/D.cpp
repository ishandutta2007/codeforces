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
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }
  auto find = [&](int v) {
    while (v != p[v]) {
      v = p[v] = p[p[v]];
    }
    return v;
  };
  int ans = 0;
  while (m--) {
    int v, u;
    cin >> v >> u;
    v = find(--v);
    u = find(--u);
    if (v == u) {
      ++ans;
    } else {
      p[v] = u;
    }
  }
  cout << ans << "\n";
  return 0;
}