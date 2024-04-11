#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> b(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
      --b[i];
      g[b[i]].push_back(i);
    }
    mt19937 rng;
    while (true) {
      vector<int> x, y;
      for (int i = 0; i < n; ++i) {
        if (empty(g[i])) {
          y.push_back(i);
          continue;
        }
        int ex = rng() % size(g[i]);
        for (int j = 0; j < int(size(g[i])); ++j)
          if (j != ex) x.push_back(g[i][j]);
      }
      assert(size(x) == size(y));
      shuffle(begin(y), end(y), rng);
      bool ok = true;
      for (int i = 0; i < int(size(x)); ++i) ok &= x[i] != y[i];
      if (ok) {
        for (int i = 0; i < int(size(x)); ++i) b[x[i]] = y[i];
        cout << n - size(x) << '\n';
        for (int i = 0; i < n; ++i) cout << b[i] + 1 << " \n"[i + 1 == n];
        break;
      }
    }
  }
}