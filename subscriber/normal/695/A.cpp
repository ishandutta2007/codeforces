#include <bits/stdc++.h>

using namespace std;

const int N = 2345678;

double real_p[123], p[123];
double f[N];
double ans[123];
int id[123];
int kb[N];

int main() {
  int real_n, k;
  scanf("%d %d", &real_n, &k);
  int n = 0;
  for (int i = 0; i < real_n; i++) {
    scanf("%lf", real_p + i);
    if (real_p[i] > 1e-4) {
      id[n] = i;
      p[n++] = real_p[i];
    }
  }
  k = min(k, n);
  kb[0] = 0;
  for (int t = 1; t < (1 << n); t++) {
    kb[t] = kb[t & (t - 1)] + 1;
  }
  for (int t = 0; t < (1 << n); t++) {
    f[t] = 0.0;
  }
  for (int i = 0; i < real_n; i++) {
    ans[i] = 0.0;
  }
  f[0] = 1.0;
  for (int t = 0; t < (1 << n); t++) {
    if (kb[t] == k) {
      for (int j = 0; j < n; j++) {
        if (t & (1 << j)) {
          ans[id[j]] += f[t];
        }
      }
      continue;
    }
    double total = 0;
    for (int j = 0; j < n; j++) {
      if (t & (1 << j)) {
        continue;
      }
      total += p[j];
    }
    double q = f[t] * 1.0 / total;
    for (int j = 0; j < n; j++) {
      if (t & (1 << j)) {
        continue;
      }
      f[t | (1 << j)] += p[j] * q;
    }
  }
  for (int i = 0; i < real_n; i++) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%.17f", ans[i]);
  }
  printf("\n");
  return 0;
}