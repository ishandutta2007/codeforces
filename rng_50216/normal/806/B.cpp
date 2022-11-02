#include <bits/stdc++.h>

int solved[42];
int a[123][42];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
     scanf("%d", a[i] + j);
      if (a[i][j] >= 0) {
        ++solved[j];
      }
    }
  }
  for (int mid = 0; mid < 10000; mid++) {
    int us = 0;
    int petya = 0;
    for (int i = 0; i < 5; i++) {
      int s = solved[i];
      if (a[0][i] < 0 || a[1][i] < 0 || a[0][i] < a[1][i]) {
      } else {
        s += mid;
      }
      int all = mid + n;
      int cost;
      if (all < 2LL * s) {
        cost = 500;
      } else if (all < 4LL * s) {
        cost = 1000;
      } else if (all < 8LL * s) {
        cost = 1500;
      } else if (all < 16LL * s) {
        cost = 2000;
      } else if (all < 32LL * s) {
        cost = 2500;
      } else {
        cost = 3000;
      }
      if (a[0][i] >= 0) {
        us += cost / 250 * (250 - a[0][i]);
      }
      if (a[1][i] >= 0) {
        petya += cost / 250 * (250 - a[1][i]);
      }
    }
    if (petya < us) {
      printf("%d\n", mid);
      return 0;
    }
  }
  puts("-1");
}