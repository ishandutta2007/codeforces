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

int n, m;
int c[500], ix[500];
char S[501];

int ask() {
  printf("? %s\n", S);
  fflush(stdout);
  int q;
  scanf("%d", &q);
  return q;
}

int main() {
  scanf("%d%d", &n, &m);
  fill(S, S+m, '0');
  rep(i, m) {
    S[i] = '1';
    c[i] = ask();
    S[i] = '0';
  }
  iota(ix, ix+m, 0);
  sort(ix, ix+m, [](int i, int j) { return c[i] < c[j]; });
  int now = 0;
  rep(i2, m) {
    int i = ix[i2];
    S[i] = '1';
    int nxt = ask();
    if (nxt == now + c[i]) {
      now = nxt;
    } else {
      S[i] = '0';
    }
  }
  printf("! %d\n", now);
}