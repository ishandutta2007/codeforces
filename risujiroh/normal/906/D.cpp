#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> map<T, int> factorize(T n) {
  map<T, int> res;
  for (T i = 2; i * i <= n; ++i)
    while (n % i == 0) ++res[i], n /= i;
  if (n != 1) ++res[n];
  return res;
}

int totient(int n) {
  int res = n;
  for (auto [p, e] : factorize(n)) {
    res /= p;
    res *= p - 1;
  }
  return res;
}

template <class T, class Op = multiplies<T>>
T power(T a, long long n, Op op = Op(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  vector<int> ms;
  for (int i = m; i >= 2; i = totient(i)) {
    ms.push_back(i);
  }
  DEBUG(ms);
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    if (m == 1) {
      cout << "0\n";
      continue;
    }
    long long res = 1;
    for (int i = min((int)size(ms), r - l); i--; ) {
      res = power(a[l + i], res, [&](long long x, long long y) {
        long long z = x * y;
        if (z >= 30 + ms[i]) {
          z = 30 + (z - 30) % ms[i];
        }
        return z;
      });
    }
    res %= m;
    cout << res << '\n';
  }
}