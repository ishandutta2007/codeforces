#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int odd = 0;
    for (int _ = 2 * n; _--;) {
      int a;
      cin >> a;
      odd += a & 1;
    }
    cout << (odd == n ? "Yes\n" : "No\n");
  }
}