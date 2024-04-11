#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int a;
  cin >> a;
  if (a < 20) {
    if (a == 2 || a == 3 || a == 4 || a == 5 || a == 6 || a == 8 || a == 12) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  } else {
    int foo = a / 10, bar = a % 10;
    if (foo != 2 && foo != 7 && foo != 9 && bar != 1 && bar != 7 && bar != 9) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
  return 0;
}