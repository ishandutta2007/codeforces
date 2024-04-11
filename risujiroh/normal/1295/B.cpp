#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    if (x < 0) {
      x = -x;
      for_each(begin(s), end(s), [](char& c) { c ^= 1; });
    }
    vector<int> _a(2 * n + 1);
    auto a = begin(_a) + n;
    int t = 0;
    for (char c : s) {
      ++a[t];
      if (c == '0') {
        ++t;
      } else {
        --t;
      }
    }
    if (t == 0) {
      if (x <= n and a[x]) {
        cout << "-1\n";
      } else {
        cout << "0\n";
      }
    } else {
      if (t > 0) {
        int m = (n + abs(t) - 1) / abs(t) * abs(t);
        if (x > m) {
          x = m - t + x % t;
        }
      }
      long long res = 0;
      for (int st = 0; abs(st) <= 2 * n; st += t) {
        if (-n <= x - st and x - st <= n) {
          res += a[x - st];
        }
      }
      cout << res << '\n';
    }
  }
}