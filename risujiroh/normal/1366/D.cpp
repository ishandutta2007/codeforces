#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  prepare(1e7);
  int n;
  cin >> n;
  vector<int> r0, r1;
  while (n--) {
    int a;
    cin >> a;
    auto v = factors(a);
    if (v[0] == v.back()) {
      r0.push_back(-1);
      r1.push_back(-1);
      continue;
    }
    int r = 0;
    while (r < (int)size(v) and v[r] == v[0]) {
      ++r;
    }
    r0.push_back(accumulate(begin(v), begin(v) + r, 1, multiplies<>()));
    r1.push_back(accumulate(begin(v) + r, end(v), 1, multiplies<>()));
  }
  n = size(r0);
  for (int i = 0; i < n; ++i) {
    cout << r0[i] << " \n"[i == n - 1];
  }
  for (int i = 0; i < n; ++i) {
    cout << r1[i] << " \n"[i == n - 1];
  }
}