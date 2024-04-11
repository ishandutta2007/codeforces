#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int T;
  cin >> T;
  while (T--) {
    long long a, b;
    cin >> a >> b;
    if (a == b + 1) {
      long long c = a + b;
      bool prime = true;
      for (int i = 2; (long long)i * i <= c; ++i) {
        if (c % i == 0) {
          prime = false;
          break;
        }
      }
      puts(prime ? "YES" : "NO");
    } else {
      puts("NO");
    }
  }
  return 0;
}