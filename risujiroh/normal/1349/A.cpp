#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T, class Op = multiplies<T>>
constexpr T power(T a, long long n, Op op = Op(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

vector<int> min_factor;
void prepare(int n) {
  min_factor.assign(n + 1, 0);
  for (int p = 2; p <= n; ++p) {
    if (min_factor[p]) continue;
    for (int i = p; i <= n; i += p)
      if(min_factor[i] == 0) min_factor[i] = p;
  }
}
vector<int> factors(int n) {
  vector<int> res;
  while (int d = min_factor[n])
    res.push_back(d), n /= d;
  return res;
}

constexpr int lim = 2e5;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  prepare(lim);
  vector<vector<int>> v(lim + 1);
  for (auto e : a) {
    map<int, int> mp;
    for (auto p : factors(e)) {
      ++mp[p];
    }
    for (auto [p, c] : mp) {
      v[p].push_back(c);
    }
  }
  auto res = 1LL;
  for (int p = 2; p <= lim; ++p) {
    if (min_factor[p] != p) continue;
    if ((int)size(v[p]) <= n - 2) continue;
    while ((int)size(v[p]) < n) {
      v[p].push_back(0);
    }
    sort(begin(v[p]), end(v[p]));
    res *= power<long long>(p, v[p][1]);
  }
  cout << res << '\n';
}