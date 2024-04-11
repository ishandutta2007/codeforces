#line 2 "lib/prelude.hpp"
#ifndef LOCAL
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)
#define repr2(i, m, n) for (auto i = (n); i-- > (m);)
#define repr(i, n) repr2(i, 0, n)
#define all(x) begin(x), end(x)
#line 2 "main.cpp"

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n), b;
  rep(i, n) scanf("%d", &a[i]);
  int z_cnt = 0;
  rep(t, n - 1) {
    if (a.size() == 0) {
      z_cnt--;
      continue;
    }
    rep(i, a.size() - 1) b.push_back(a[i + 1] - a[i]);
    if (z_cnt) {
      b.push_back(a[0]);
      z_cnt--;
    }
    sort(all(b));
    auto it = b.begin();
    while (it != b.end() && *it == 0) it++;
    z_cnt += it - b.begin();
    b.erase(b.begin(), it);
    swap(a, b);
    b.clear();
  }
  printf("%d\n", a.size() ? a[0] : 0);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}