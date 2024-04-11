#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  while (true) {
    int odd = 0;
    for (int i = 0; i < n; ++i) {
      odd += (x[i] + y[i]) & 1;
    }
    int even = n - odd;
    if (odd and even) {
      cout << odd << '\n';
      bool first = true;
      for (int i = 0; i < n; ++i) {
        if ((x[i] + y[i]) & 1) {
          if (not exchange(first, false)) {
            cout << ' ';
          }
          cout << i + 1;
        }
      }
      cout << '\n';
      return 0;
    }
    if (odd) {
      for (auto&& e : x) {
        ++e;
      }
    }
    for (int i = 0; i < n; ++i) {
      assert(~(x[i] + y[i]) & 1);
      int nx = (y[i] - x[i]) / 2, ny = (x[i] + y[i]) / 2;
      x[i] = nx, y[i] = ny;
    }
  }
}