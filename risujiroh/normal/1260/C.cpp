#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    long long r, b, k;
    cin >> r >> b >> k;
    if (r > b) {
      swap(r, b);
    }
    int d = __gcd(r, b);
    r /= d, b /= d;
    if (r * (k - 1) + 1 <= b - 1) {
      cout << "REBEL\n";
    } else {
      cout << "OBEY\n";
    }
  }
}