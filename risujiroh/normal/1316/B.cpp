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
    string s;
    cin >> s;
    string mn = string(1, 'z' + 1);
    int k = -1;
    for (int m = n; m; --m) {
      string cur = s.substr(n - m) + s.substr(0, n - m);
      if (m & 1) {
        reverse(begin(cur) + m, end(cur));
      }
      if (cur < mn) {
        mn = cur;
        k = n - m + 1;
      }
    }
    cout << mn << '\n';
    cout << k << '\n';
  }
}