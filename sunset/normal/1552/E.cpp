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
  vector<int> a(n * m);
  vector<vector<int>> b(n);
  for (int i = 0; i < n * m; ++i) {
    cin >> a[i];
    b[--a[i]].push_back(i);
  }
  vector<int> l(n, -1), r(n, -1);
  for (int i = 0, j = 0; i < n; i = j) {
    j = min(n, i + m - 1);
    for (int k = 1; k <= j - i; ++k) {
      int w = n * m, p = -1;
      for (int z = i; z < j; ++z) {
        if (l[z] == -1 && b[z][k] < w) {
          w = b[z][k];
          p = z;
        }
      }
      l[p] = b[p][k - 1];
      r[p] = b[p][k];
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << l[i] + 1 << " " << r[i] + 1 << "\n";
  }
  return 0;
}