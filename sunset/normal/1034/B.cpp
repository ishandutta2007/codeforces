#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  if (n > m) {
    swap(n, m);
  }
  if (n == 1) {
    cout << m / 6 * 6 + (max(m % 6 - 3, 0) << 1) << endl;
  } else if (n == 2) {
    if (m == 2) {
      cout << 0 << endl;
    } else if (m == 3) {
      cout << 4 << endl;
    } else if (m == 7) {
      cout << 12 << endl;
    } else {
      cout << (m << 1) << endl;
    }
  } else {
    cout << (long long)n * m / 2 * 2 << endl;
  }
  return 0;
}