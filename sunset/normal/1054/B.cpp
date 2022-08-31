#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  int now = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x <= now) {
      now = max(now, x + 1);
    } else {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}