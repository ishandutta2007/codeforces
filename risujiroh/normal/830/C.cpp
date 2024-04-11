#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

using Z = long long;
Z tmod(Z a, Z b) {
  if (b < 0) return -tmod(-a, -b);
  return (a %= b) < 0 ? a + b : a;
}
Z tdiv(Z a, Z b) { return (a - tmod(a, b)) / b; }
pair<Z, Z> divmod(Z a, Z b) { return {tdiv(a, b), tmod(a, b)}; }

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  long long k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  vector<long long> p;
  for (auto e : a) {
    for (int q = 1e4; q; --q) {
      p.push_back((e + q - 1) / q);
    }
  }
  p.push_back(1e12);
  sort(begin(p), end(p));
  p.erase(unique(begin(p), end(p)), end(p));
  for (int j = size(p) - 1; j--; ) {
    auto u = 0LL, v = 0LL;
    for (auto e : a) {
      u += -tdiv(-e, p[j]);
      v += -e;
    }
    if (u * p[j] + v > k) continue;
    cout << (k - v) / u << '\n';
    exit(0);
  }
  for (int d = 1e5; d >= 1; --d) {
    auto sum = 0LL;
    for (auto e : a) {
      sum += tmod(-e, d);
    }
    if (sum <= k) {
      cout << d << '\n';
      exit(0);
    }
  }
}