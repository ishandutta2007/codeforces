#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<set<int>> se(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    se[u].insert(v);
    se[v].insert(u);
  }
  auto check = [&](int i) { return empty(se[i]) || *rbegin(se[i]) < i; };
  int ans = 0;
  for (int i = 0; i < n; ++i) ans += check(i);
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      ans -= check(u);
      ans -= check(v);
      se[u].insert(v);
      se[v].insert(u);
      ans += check(u);
      ans += check(v);
    } else if (t == 2) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      ans -= check(u);
      ans -= check(v);
      se[u].erase(v);
      se[v].erase(u);
      ans += check(u);
      ans += check(v);
    } else if (t == 3) {
      cout << ans << '\n';
    } else
      assert(false);
  }
}