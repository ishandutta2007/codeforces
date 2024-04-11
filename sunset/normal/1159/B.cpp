#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int ans = 1 << 30;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ans = min(ans, a / max(i, n - i - 1));
  }
  cout << ans << "\n";
  return 0;
}