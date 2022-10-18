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

int T, n, a[200000], m, b[200000];
vector<int> ai[200002];

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    rep(i, n + 2) ai[i].clear();
    rep(i, n) scanf("%d", a + i), ai[a[i]].push_back(i);
    rep(i, n+1) reverse(all(ai[i]));
    m = 0;
    int f = 0;
    while (!ai[0].empty()) {
      int maxI = -1, mex = -1;
      rep(i, n + 2) {
        while (!ai[i].empty() && ai[i].back() < f) ai[i].pop_back();
        if (!ai[i].empty()) {
          maxI = max(maxI, ai[i].back());
        } else {
          mex = i;
          break;
        }
      }
      b[m++] = mex;
      f = maxI + 1;
      while (!ai[0].empty() && ai[0].back() < f) ai[0].pop_back();
    }
    rep(i, n+1) {
      while (!ai[i].empty()) {
        if (ai[i].back() >= f) b[m++] = 0;
        ai[i].pop_back();
      }
    }
    printf("%d\n", m);
    rep(i, m) printf("%d%c", b[i], " \n"[i==m-1]);
  }
}