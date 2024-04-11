#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, a, b;
    cin >> n >> a >> b;
    if (a == 1) {
      cout << ((n - 1) % b == 0 ? "Yes\n" : "No\n");
    } else {
      bool ok = false;
      for (int64_t base = 1; base <= n; base *= a) ok |= (n - base) % b == 0;
      cout << (ok ? "Yes\n" : "No\n");
    }
  }
}