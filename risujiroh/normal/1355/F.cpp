#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

vector<int> sieve(int n) {
  vector<bool> b(n / 3 + 1, true);
  vector<int> res{2, 3};
  for (int p = 5, d = 4; p * p <= n; p += d = 6 - d) if (b[p / 3])
    for (int i = p * p, di = p % 3 * 2 * p; i <= n; i += di = 6 * p - di)
      b[i / 3] = false;
  for (int p = 5, d = 4; p <= n; p += d = 6 - d) if(b[p / 3]) res.push_back(p);
  while (not res.empty() and res.back() > n) res.pop_back();
  return res;
}

template <class T> map<T, int> factorize(T n) {
  map<T, int> res;
  for (T i = 2; i * i <= n; ++i)
    while (n % i == 0) ++res[i], n /= i;
  if (n != 1) ++res[n];
  return res;
}

constexpr long long lim = 1e18;

int main() {
  auto ps = sieve(1000);
  DEBUG(ps);
  vector<long long> v;
  auto t = 1LL;
  for (int p : ps) {
    if (t > lim / p) {
      v.push_back(t);
      DEBUG(p, t);
      t = 1;
    }
    t *= p;
    if (size(v) == 18) break;
  }
  DEBUG(v);
  int tt;
  cin >> tt;
  while (tt--) {
    int prod = 1;
    for (auto e : v) {
      cout << "? " << e << endl;
      int g;
      cin >> g;
      prod *= g;
    }
    vector<int> pp;
    for (auto [p, e] : factorize(prod)) {
      pp.push_back(p);
    }
    int x = 1;
    for (int i = 0; i < min<int>(size(pp), 8); i += 2) {
      long long cur = 1;
      while (cur * pp[i] <= (long long)1e9) {
        cur *= pp[i];
      }
      if (i + 1 < (int)size(pp)) {
        while (cur <= lim / pp[i + 1]) {
          cur *= pp[i + 1];
        }
      }
      cout << "? " << cur << endl;
      int g;
      cin >> g;
      x *= g;
    }
    int d = 1;
    for (auto [p, e] : factorize(x)) {
      d *= e + 1;
    }
    if (x > 2) {
      cout << "! " << 2 * d << endl;
    } else if (prod == 1) {
      cout << "! 8" << endl;
    } else {
      cout << "! 9" << endl;
    }
  }
}