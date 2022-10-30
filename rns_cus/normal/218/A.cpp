#include <bits/stdc++.h>
using namespace std;
#define N 2020

int n, k, r[N], step;

int main() {
//  freopen("a.in", "r", stdin);
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= 2 * n + 1; i ++) scanf("%d", &r[i]);
  for (int i = 2; i <= 2 * n && step < k; i += 2) {
    if (r[i] > r[i-1] + 1 && r[i] > r[i+1] + 1) r[i] --, step ++;
  }
  for (int i = 1; i <= 2 * n + 1; i ++) printf("%d ", r[i]);
  puts("");
  return 0;
}