#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n; cin >> n;
  VI x(n), y(n); for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  VI res(n);
  int tx = 0, ty = 0;
  for (int i = 0; i < n; i++) {
    double tp = hypot(tx + x[i], ty + y[i]);
    double tn = hypot(tx - x[i], ty - x[i]);
    if (tp < tn) {
      tx += x[i];
      ty += y[i];
      res[i] = 1;
    } else {
      tx -= x[i];
      ty -= y[i];
      res[i] = -1;
    }
  }
  if (hypot(tx, ty) > 1.49e6) {
    for (int i = 0; i < n; i++) {
      if (res[i] == -1 and hypot(tx + 2 * x[i], ty + 2 * y[i]) < 1.49e6) {
        res[i] = 1;
        break;
      }
      if (res[i] == 1 and hypot(tx - 2 * x[i], ty - 2 * y[i]) < 1.49e6) {
        res[i] = -1;
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << res[i] << ' ';
  }
  cout << '\n';
  return 0;
}