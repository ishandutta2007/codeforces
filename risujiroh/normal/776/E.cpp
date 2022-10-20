#include <bits/stdc++.h>
using namespace std;

template <class Z> map<Z, int> factorize(Z n) {
  map<Z, int> res;
  for (Z i = 2; i * i <= n; ++i) while (n % i == 0) ++res[i], n /= i;
  if (n != 1) ++res[n];
  return res;
}

long long phi(long long n) {
  long long res = n;
  for (auto e : factorize(n)) {
    res /= e.first;
    res *= e.first - 1;
  }
  return res;
}
constexpr long long mod = 1e9 + 7;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  k = (k + 1) / 2;
  while (k-- and n > 1) {
    n = phi(n);
  }
  n %= mod;
  cout << n << '\n';
}