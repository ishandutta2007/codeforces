#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

using arr = array<int, 10>;

int n, m, c[10], a[10][200000];
set<pair<ll, arr>> cand;
set<arr> ng;

int main() {
  scanf("%d", &n);
  rep(i, n) {
    scanf("%d", c+i);
    rep(j, c[i]) scanf("%d", a[i]+j);
  }
  scanf("%d", &m);
  while (m--) {
    arr b{};
    rep(i, n) scanf("%d", &b[i]), b[i]--;
    ng.insert(b);
  }
  {
    ll s = 0;
    arr l{};
    rep(i, n) l[i] = c[i] - 1, s += a[i][c[i] - 1];
    cand.emplace(s, l);
  }
  while (!cand.empty()) {
    auto itr = --cand.end();
    auto [s, l] = *itr; cand.erase(itr);
    if (!ng.count(l)) {
      rep(i, n) printf("%d%c", l[i]+1, " \n"[i==n-1]);
      return 0;
    }
    rep(i, n) if (l[i]) {
      auto l2 = l;
      l2[i]--;
      cand.emplace(s - a[i][l[i]] + a[i][l2[i]], l2);
    }
  }
}