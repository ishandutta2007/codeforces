#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  string s, t;
  int n, m;
  cin >> n >> m >> s >> t;
  if (n > m + 1) {
    puts("NO");
  } else {
    int p = -1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '*') {
        p = i;
      }
    }
    if (~p) {
      bool flag = true;
      for (int i = 0; i < p; ++i) {
        if (s[i] != t[i]) {
          flag = false;
          break;
        }
      }
      for (int i = n - 1, j = m - 1; i > p; --i, --j) {
        if (s[i] != t[j]) {
          flag = false;
          break;
        }
      }
      puts(flag ? "YES" : "NO");
    } else {
      puts(s == t ? "YES" : "NO");
    }
  }
  return 0;
}