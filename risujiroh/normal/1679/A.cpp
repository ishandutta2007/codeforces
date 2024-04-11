#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    using i64 = long long;
    i64 n;
    cin >> n;
    if (n & 1) {
      cout << "-1\n";
      continue;
    }
    n >>= 1;

    if (n == 1) {
      cout << "-1\n";
      continue;
    }

    i64 mx = -1;

    if (n % 3 == 0) {
      mx = n / 3;
    } else if (n % 3 == 2) {
      mx = n / 3 + 1;
    } else {
      mx = n / 3 + 1;
    }

    cout << mx << ' ' << n / 2 << '\n';
  }
}