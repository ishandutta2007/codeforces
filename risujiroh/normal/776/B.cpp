#include <bits/stdc++.h>
using namespace std;

template <class Z> bool isprime(Z n) {
  if (n < 2 or (n > 2 and ~n & 1)) return false;
  for (Z i = 3; i * i <= n; i += 2) if (n % i == 0) return false;
  return true;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  if (n < 3) {
    cout << "1\n";
    for (int i = 2; i <= n + 1; ++i) {
      cout << 1 << " \n"[i == n + 1];
    }
  } else {
    cout << "2\n";
    for (int i = 2; i <= n + 1; ++i) {
      cout << isprime(i) + 1 << " \n"[i == n + 1];
    }
  }
}