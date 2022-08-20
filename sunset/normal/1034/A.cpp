#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  int gcd = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    gcd = __gcd(gcd, a[i]);
  }
  for (int i = 0; i < n; ++i) {
    a[i] /= gcd;
  }
  int m = *max_element(a.begin(), a.end());
  if (m == 1) {
    puts("-1");
    return 0;
  }
  vector<int> minp(m + 1), primes;
  for (int i = 2; i <= m; ++i) {
    if (!minp[i]) {
      minp[i] = i;
      primes.push_back(i);
    }
    for (auto p : primes) {
      if (i * p > m) {
        break;
      }
      minp[i * p] = p;
      if (i % p == 0) {
        break;
      }
    }
  }
  vector<int> cover(m + 1);
  for (auto x : a) {
    while (x != 1) {
      int p = minp[x];
      while (x % p == 0) {
        x /= p;
      }
      ++cover[p];
    }
  }
  printf("%d\n", n - *max_element(cover.begin(), cover.end()));
  return 0;
}