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
  int n, x; scanf("%d%d", &n, &x);
  vector<int> a(n);
  vector<bool> used(n);
  rep(i, n) scanf("%d", &a[i]);
  sort(all(a));
  map<int, vector<int>> m;
  repr(i, n) m[a[i]].push_back(i);
  int cnt = 0;
  rep(i, n) if (!used[i]) {
    m[a[i]].pop_back();
    ll nxt = 1LL * a[i] * x;
    if (nxt < INT_MAX && !m[nxt].empty()) {
      int j = m[nxt].back();
      m[nxt].pop_back();
      used[j] = true;
    } else cnt++;
  }
  printf("%d\n", cnt);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}