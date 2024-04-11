#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
    }
    vector<int> idx(n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](int i, int j) {
      return make_pair(x[i], y[i]) < make_pair(x[j], y[j]);
    });
    [&] {
      for (int t = 0; t < n - 1; ++t) {
        if (y[idx[t]] > y[idx[t + 1]]) {
          cout << "NO\n";
          return;
        }
      }
      cout << "YES\n";
      int nx = 0, ny = 0;
      string res;
      for (int i : idx) {
        res += string(x[i] - nx, 'R');
        res += string(y[i] - ny, 'U');
        nx = x[i], ny = y[i];
      }
      cout << res << '\n';
    }();
  }
}