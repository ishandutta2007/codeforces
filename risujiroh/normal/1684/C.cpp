#include <bits/stdc++.h>

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    vector<vector<int>> b(n);
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
      for (int& e : a[i]) cin >> e;
      b[i] = a[i];
      sort(begin(b[i]), end(b[i]));
      if (a[i] != b[i] && empty(pos)) {
        for (int j = 0; j < m; ++j) {
          if (a[i][j] != b[i][j]) {
            pos.push_back(j);
          }
        }
      }
    }
    if (empty(pos)) {
      cout << "1 1\n";
    } else if (size(pos) == 2) {
      for (int i = 0; i < n; ++i) {
        swap(a[i][pos[0]], a[i][pos[1]]);
      }
      if (a == b) {
        cout << pos[0] + 1 << ' ' << pos[1] + 1 << '\n';
      } else {
        cout << "-1\n";
      }
    } else {
      cout << "-1\n";
    }
  }
}