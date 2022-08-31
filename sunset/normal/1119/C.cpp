#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  vector<vector<int>> b(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> b[i][j];
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (a[i][j]) {
        a[i][j] ^= 1;
        a[i][0] ^= 1;
        a[0][j] ^= 1;
        a[0][0] ^= 1;
      }
      if (b[i][j]) {
        b[i][j] ^= 1;
        b[i][0] ^= 1;
        b[0][j] ^= 1;
        b[0][0] ^= 1;
      }
    }
  }
  cout << (a == b ? "Yes" : "No") << "\n";
  return 0;
}