#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class Z> bool isprime(Z n) {
  if (n < 2 or (n > 2 and ~n & 1)) return false;
  for (Z i = 3; i * i <= n; i += 2) if (n % i == 0) return false;
  return true;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    bool f = [&]() {
      if (n == 1) {
        return true;
      }
      if (n == 2) {
        return false;
      }
      if (n & 1) {
        return false;
      }
      n /= 2;
      return isprime(n) or (n & (n - 1)) == 0;
    }();
    if (f) {
      cout << "FastestFinger\n";
    } else {
      cout << "Ashishgup\n";
    }
  }
}