#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--) {
    long long p, q, b;
    cin >> p >> q >> b;
    auto g = gcd(p, q);
    p /= g;
    q /= g;
    while (true) {
      auto t = gcd(q, b);
      if (t == 1) break;
      while (q % t == 0) {
        q /= t;
      }
    }
    if (q == 1) {
      cout << "Finite\n";
    } else {
      cout << "Infinite\n";
    }
  }
}