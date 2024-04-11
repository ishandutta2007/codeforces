#include <bits/stdc++.h>

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    int max_i = -1;
    int max_j = -1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
        if (max_i == -1 || a[max_i][max_j] < a[i][j]) {
          max_i = i;
          max_j = j;
        }
      }
    }

    cout << (n - min(max_i, n - max_i - 1)) * (m - min(max_j, m - max_j - 1))
         << '\n';
  }
}