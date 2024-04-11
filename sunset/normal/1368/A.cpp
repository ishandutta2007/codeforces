#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a < b) {
      swap(a, b);
    }
    int ans = 0;
    while (a <= c) {
      b += a;
      swap(a, b);
      ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}