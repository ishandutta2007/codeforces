#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, m, n) for (int i = (m); i < (n); i++)

bool is_p[3005];
int ps[3005], pss, f[3005];

int main() {
  fill(is_p + 2, end(is_p), true);
  for (int p = 2; p * p < size(is_p); p++)
    if (is_p[p])
      for (int m = p * p; m < size(is_p); m += p)
        is_p[m] = false;

  rep(i, size(is_p)) if (is_p[i]) ps[pss++] = i;

  rep(i, pss) rep(j, i) {
    for (int p = ps[i]; p < size(f); p *= ps[i])
      for (int q = ps[j]; p * q < size(f); q *= ps[j])
        f[p * q] = 1;
  }

  int n; scanf("%d", &n);
  printf("%d\n", accumulate(f, f + n + 1, 0));
}