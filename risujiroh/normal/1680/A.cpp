#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (max(l1, l2) <= min(r1, r2)) {
      cout << max(l1, l2) << '\n';
    } else {
      cout << l1 + l2 << '\n';
    }
  }
}