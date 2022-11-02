#include <bits/stdc++.h>

int const N = 2222;

long long const INF = 1LL << 60;

long long w[N];
int d[N][N];
int s[N], was[N];

int main() {
  int n;
  scanf("%d", &n);
  int mn = 1 << 30;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      scanf("%d", d[i] + j);
      d[j][i] = d[i][j];
      if (d[i][j] < mn) {
        mn = d[i][j];
      }
    }
  }
  for (int i = 0; i < n; i++) s[i] = 1 << 30;
  long long ans = (long long) mn * (n - 1);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      d[i][j] -= mn;
      d[j][i] -= mn;
      s[i] = std::min(s[i], d[i][j]);
      s[j] = std::min(s[j], d[i][j]);
    }
  }
  // for (int i = 0; i < n; i++) printf("%d\n", s[i]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        d[i][j] = std::min(d[i][j], s[j] * 2);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == 0) w[i] = 0; else
    w[i] = INF;
  }
  while (true) {
    int best = -1;
    for (int i = 0; i < n; i++) {
      if (was[i] || w[i] == INF) continue;
      if (best < 0 || w[best] > w[i]) {
        best = i;
      }
    }
    if (best < 0) break;
    was[best] = true;
    for (int i = 0; i < n; i++) {
      if (i == best) continue;
      if (w[i] > w[best] + d[best][i]) {
        w[i] = w[best] + d[best][i];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%lld\n", ans + w[i]);
  }
}