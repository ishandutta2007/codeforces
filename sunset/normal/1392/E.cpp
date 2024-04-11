#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<long long>> a(n, vector<long long>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j) {
        cout << " ";
      }
      if (i % 2 == 0) {
        a[i][j] = 1ll << (i + j);
      }
      cout << a[i][j];
    }
    cout << endl;
  }
  int q;
  cin >> q;
  while (q--) {
    long long w;
    cin >> w;
    vector<int> xs;
    vector<int> ys;
    int x = n - 1, y = n - 1;
    for (int t = 0; t < 2 * n - 1; ++t) {
      xs.push_back(x);
      ys.push_back(y);
      w -= a[x][y];
      if (!x) {
        y--;
      } else if (!y) {
        x--;
      } else {
        if (a[x - 1][y]) {
          if (w >= a[x - 1][y]) {
            x--;
          } else {
            y--;
          }
        } else {
          if (w >= a[x][y - 1]) {
            y--;
          } else {
            x--;
          }
        }
      }
    }
    for (int i = 2 * n - 2; ~i; --i) {
      cout << xs[i] + 1 << " " << ys[i] + 1 << endl;
    }
  }
  return 0;
}