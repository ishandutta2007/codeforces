#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int x = 1;
  while (x <= n) {
    if (x == n || x + 1 == n) {
      cout << 1 << "\n";
      return 0;
    }
    if (x & 1) {
      x = x * 2 + 2;
    } else {
      x = x * 2 + 1;
    }
  }
  cout << 0 << "\n";
  return 0;
}