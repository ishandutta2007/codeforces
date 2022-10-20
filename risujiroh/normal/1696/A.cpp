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
    int n, z;
    cin >> n >> z;
    int ans = 0;
    while (n--) {
      int a;
      cin >> a;
      ans = max(ans, a | z);
    }
    cout << ans << '\n';
  }
}