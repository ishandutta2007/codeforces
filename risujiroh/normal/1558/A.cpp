#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    if (b > a) swap(a, b);
    int n = a + b;
    if (n & 1) {
      int lo = a - (n + 1) / 2;
      int hi = b + (n + 1) / 2;
      cout << hi - lo + 1 << '\n';
      for (int i = lo; i <= hi; ++i) {
        cout << i << " \n"[i == hi];
      }
    } else {
      int lo = a - n / 2;
      int hi = b + n / 2;
      cout << (hi - lo) / 2 + 1 << '\n';
      for (int i = lo; i <= hi; i += 2) {
        cout << i << " \n"[i == hi];
      }
    }
  }
}