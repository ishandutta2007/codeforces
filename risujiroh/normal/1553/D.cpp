#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s >> t;
    reverse(begin(s), end(s));
    reverse(begin(t), end(t));
    int pos = 0;
    bool ok = true;
    for (char c : t) {
      while (pos < int(size(s)) && s[pos] != c) pos += 2;
      if (pos >= int(size(s))) {
        ok = false;
        break;
      }
      ++pos;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}