#include <bits/stdc++.h>

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    if (n & 1) {
      int i = n / 2;
      int j = i - 1;
      while (i < n && 0 <= j && s[i] == s[j]) {
        ++i;
        --j;
        ++ans;
      }
      ans *= 2;
      ++ans;
    } else {
      int i = n / 2;
      int j = i;
      while (i < n && 0 <= j && s[i] == s[j]) {
        ++i;
        --j;
        ++ans;
      }
      ans *= 2;
    }
    cout << ans << '\n';
  }
}