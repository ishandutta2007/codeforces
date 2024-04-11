#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      int y = cur & ~x;
      cur = x ^ y;
      cout << y << " \n"[i + 1 == n];
    }
  }
}