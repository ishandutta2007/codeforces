#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    string p, h;
    cin >> p >> h;
    int n = p.size(), m = h.size();
    sort(begin(p), end(p));
    bool ok = [&] {
      for (int i = 0; i + n <= m; ++i) {
        string s = h.substr(i, n);
        sort(begin(s), end(s));
        if (p == s) {
          return true;
        }
      }
      return false;
    }();
    cout << (ok ? "YES" : "NO") << '\n';
  }
}