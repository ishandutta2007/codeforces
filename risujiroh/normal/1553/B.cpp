#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s >> t;
    int n = size(s);
    bool can = [&]() -> bool {
      for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j) {
          string cur = s.substr(i, j - i + 1);
          for (int k = j; k--;) {
            if (size(cur) == size(t)) break;
            cur += s[k];
          }
          if (cur == t) return true;
        }
      return false;
    }();
    cout << (can ? "YES\n" : "NO\n");
  }
}