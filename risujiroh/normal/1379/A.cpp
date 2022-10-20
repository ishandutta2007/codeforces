#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

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
    [&] {
      for (int i = 0; i + 7 <= n; ++i) {
        bool ok = true;
        for (int j = 0; j < 7; ++j) {
          if (s[i + j] != '?' and s[i + j] != "abacaba"[j]) {
            ok = false;
            break;
          }
        }
        if (ok) {
          auto t = s;
          for (int j = 0; j < 7; ++j) {
            t[i + j] = "abacaba"[j];
          }
          for (auto&& e : t) {
            if (e == '?') {
              e = 'z';
            }
          }
          int cnt = 0;
          for (int k = 0; k + 7 <= n; ++k) {
            cnt += t.substr(k, 7) == "abacaba";
          }
          if (cnt == 1) {
            cout << "Yes\n";
            cout << t << '\n';
            return;
          }
        }
      }
      cout << "No\n";
    }();
  }
}