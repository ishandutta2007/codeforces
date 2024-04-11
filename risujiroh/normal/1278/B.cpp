#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int d = abs(a - b);
    [&]{
      if (d & 1) {
        int sum = 0;
        for (int n = 0; ; ++n) {
          sum += n;
          if (n % 4 == 1 or n % 4 == 2) {
            if (sum >= d) {
              cout << n << '\n';
              return;
            }
          }
        }
      } else {
        int sum = 0;
        for (int n = 0; ; ++n) {
          sum += n;
          if (n % 4 == 0 or n % 4 == 3) {
            if (sum >= d) {
              cout << n << '\n';
              return;
            }
          }
        }
      }
    }();
  }
}