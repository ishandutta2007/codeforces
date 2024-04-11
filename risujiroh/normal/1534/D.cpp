#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  auto query = [&](int r) -> vector<int> {
    cout << "? " << r + 1 << endl;
    vector<int> res(n);
    for (auto&& e : res) cin >> e;
    return res;
  };
  vector<vector<int>> d(n);
  d[0] = query(0);
  array<int, 2> cnt{};
  for (auto&& e : d[0]) ++cnt[e & 1];
  int p = min_element(begin(cnt), end(cnt)) - begin(cnt);
  for (int v = 1; v < n; ++v)
    if ((d[0][v] & 1) == p) d[v] = query(v);
  cout << "!\n";
  for (int v = 0; v < n; ++v)
    if ((d[0][v] & 1) == p)
      for (int u = 0; u < n; ++u)
        if (d[v][u] == 1) cout << v + 1 << ' ' << u + 1 << '\n';
  cout << endl;
}