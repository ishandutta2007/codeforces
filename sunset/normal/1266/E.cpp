#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  long long ans = 0;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ans += a[i];
  }
  vector<int> b(n);
  map<pair<int, int>, int> who;
  int m;
  cin >> m;
  while (m--) {
    int s, t, u;
    cin >> s >> t >> u;
    --s; --u;
    if (who.count(make_pair(s, t))) {
      int v = who[make_pair(s, t)];
      ans -= max(a[v] - b[v], 0);
      --b[v];
      ans += max(a[v] - b[v], 0);
      // who[make_pair(s, t)] = -1;
      who.erase(make_pair(s, t));
    }
    if (u != -1) {
      ans -= max(a[u] - b[u], 0);
      ++b[u];
      ans += max(a[u] - b[u], 0);
      who[make_pair(s, t)] = u;
    }
    cout << ans << "\n";
  }
  return 0;
}