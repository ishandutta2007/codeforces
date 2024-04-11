#include <bits/extc++.h>
using namespace std;

template <class Z> bool isprime(Z n) {
  if (n < 2 or (n > 2 and ~n & 1)) return false;
  for (Z i = 3; i * i <= n; i += 2) if (n % i == 0) return false;
  return true;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  if (isprime(n)) {
    cout << "1\n";
  } else if (n % 2 == 0 or isprime(n - 2)) {
    cout << "2\n";
  } else {
    cout << "3\n";
  }
}