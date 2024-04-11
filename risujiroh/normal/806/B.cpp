#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int max_score(int ac, int all) {
  if (ac * 32 <= all) return 3000;
  if (ac * 16 <= all) return 2500;
  if (ac * 8 <= all) return 2000;
  if (ac * 4 <= all) return 1500;
  if (ac * 2 <= all) return 1000;
  return 500;
}

int score(int mx, int t) {
  if (t == -1) return 0;
  return mx - mx / 250 * t;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector a(n, vector<int>(5));
  vector<int> cnt(5);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; ++j) {
      cin >> a[i][j];
      cnt[j] += a[i][j] != -1;
    }
  }
  for (int m = 0; m <= 31 * n; ++m) {
    int sum0 = 0, sum1 = 0;
    for (int j = 0; j < 5; ++j) {
      int s0 = score(max_score(cnt[j], n), a[0][j]);
      int s1 = score(max_score(cnt[j], n), a[1][j]);
      if (a[0][j] != -1 and s0 < s1) {
        sum0 += score(max_score(cnt[j] + m, n + m), a[0][j]);
        sum1 += score(max_score(cnt[j] + m, n + m), a[1][j]);
      } else {
        sum0 += score(max_score(cnt[j], n + m), a[0][j]);
        sum1 += score(max_score(cnt[j], n + m), a[1][j]);
      }
    }
    if (sum0 > sum1) {
      cout << m << '\n';
      exit(0);
    }
  }
  cout << "-1\n";
}