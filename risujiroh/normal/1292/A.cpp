#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<vector<bool>> s(2, vector<bool>(n));
  int x = 0;
  while (q--) {
    int r, c;
    cin >> r >> c;
    --r, --c;
    if (s[r][c]) {
      s[r][c] = false;
      for (int j = max(c - 1, 0); j < min(n, c + 2); ++j) {
        x -= s[r ^ 1][j];
      }
    } else {
      s[r][c] = true;
      for (int j = max(c - 1, 0); j < min(n, c + 2); ++j) {
        x += s[r ^ 1][j];
      }
    }
    cout << (x == 0 ? "Yes\n" : "No\n");
  }
}