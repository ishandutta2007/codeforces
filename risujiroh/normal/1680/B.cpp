#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    int min_i = n;
    int min_j = m;
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == 'R') {
          min_i = min(min_i, i);
          min_j = min(min_j, j);
        }
      }
    }
    cout << (s[min_i][min_j] == 'R' ? "YES\n" : "NO\n");
  }
}