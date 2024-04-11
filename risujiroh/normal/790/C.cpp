#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

auto chmin = [](auto&& a, auto b) { return b < a ? a = b, 1 : 0; };

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> iv, ik, ir;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'V') {
      iv.push_back(i);
    } else if (s[i] == 'K') {
      ik.push_back(i);
    } else {
      ir.push_back(i);
    }
  }
  vector dp(1, vector(1, array<int, 2>{0, inf<int>}));
  for (int i = 0; i < n; ++i) {
    vector ndp(i + 2, vector(i + 2, array<int, 2>{inf<int>, inf<int>}));
    for (int v = 0; v <= i; ++v) {
      for (int k = 0; v + k <= i; ++k) {
        int r = i - v - k;
        for (int f : {0, 1}) {
          if (dp[v][k][f] == inf<int>) continue;
          if (v < (int)size(iv)) {
            int cost = 0;
            for (int x = 0; x < k; ++x) {
              cost += iv[v] < ik[x];
            }
            for (int x = 0; x < r; ++x) {
              cost += iv[v] < ir[x];
            }
            chmin(ndp[v + 1][k][1], dp[v][k][f] + cost);
          }
          if (k < (int)size(ik) and f == 0) {
            int cost = 0;
            for (int x = 0; x < v; ++x) {
              cost += ik[k] < iv[x];
            }
            for (int x = 0; x < r; ++x) {
              cost += ik[k] < ir[x];
            }
            chmin(ndp[v][k + 1][0], dp[v][k][f] + cost);
          }
          if (r < (int)size(ir)) {
            int cost = 0;
            for (int x = 0; x < v; ++x) {
              cost += ir[r] < iv[x];
            }
            for (int x = 0; x < k; ++x) {
              cost += ir[r] < ik[x];
            }
            chmin(ndp[v][k][0], dp[v][k][f] + cost);
          }
        }
      }
    }
    swap(dp, ndp);
  }
  cout << min(dp[size(iv)][size(ik)][0], dp[size(iv)][size(ik)][1]) << '\n';
}