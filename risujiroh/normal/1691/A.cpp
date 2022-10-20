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
    int o = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      o += a & 1;
    }
    cout << min(o, n - o) << '\n';
  }
}