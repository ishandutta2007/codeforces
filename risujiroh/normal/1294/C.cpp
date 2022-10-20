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
    int _n = n;
    vector<int> res;
    int s = 2;
    for (int _ = 2; _--; ) {
      for (int i = s; i * i <= n; ++i) {
        if (n % i == 0) {
          res.push_back(i);
          n /= i;
          s = i + 1;
          break;
        }
      }
    }
    if (res.size() == 2 and res[0] * res[1] < _n) {
      res.push_back(_n / res[0] / res[1]);
    }
    sort(begin(res), end(res));
    res.erase(unique(begin(res), end(res)), end(res));
    if (res.size() == 3) {
      cout << "YES\n";
      for (int i = 0; i < 3; ++i) {
        cout << res[i] << " \n"[i == 2];
      }
    } else {
      cout << "NO\n";
    }
  }
}