#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = size(s);
    sort(begin(s), end(s));
    if (s[0] == s.back()) {
      cout << s << '\n';
      continue;
    }
    bool f = false;
    for (int i = 0; i < n; ++i)
      if ((i == 0 || s[i - 1] != s[i]) && (i + 1 == n || s[i] != s[i + 1])) {
        cout << s[i];
        for (int j = 0; j < n; ++j)
          if (j != i) cout << s[j];
        cout << '\n';
        f = true;
        break;
      }
    if (f) continue;
    int a = count(begin(s), end(s), s[0]);
    if (a <= n / 2 + 1) {
      int r = a;
      if (r-- > 0) cout << s[0];
      if (r-- > 0) cout << s[0];
      for (int i = a; i < n; ++i) {
        cout << s[i];
        if (r-- > 0) cout << s[0];
      }
      cout << '\n';
    } else {
      if (s[a] == s.back()) {
        cout << s[0];
        for (int _ = n - a; _--;) cout << s[a];
        for (int _ = a - 1; _--;) cout << s[0];
        cout << '\n';
      } else {
        int b = count(begin(s), end(s), s[a]);
        swap(s[1], s[a]);
        if (b > 1) swap(s[a + 1], s[a + b]);
        cout << s << '\n';
      }
    }
  }
}