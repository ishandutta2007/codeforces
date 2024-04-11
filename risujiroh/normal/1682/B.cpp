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
    int ans = -1;
    for (int i = 0; i < n; ++i) {
      int p;
      cin >> p;
      if (p != i) {
        ans &= p;
      }
    }
    cout << ans << '\n';
  }
}