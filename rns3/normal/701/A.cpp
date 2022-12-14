#include <bits/stdc++.h>
using namespace std;

#define N 110

int a[N], id[N];
bool cmp(int i, int j) {
  return a[i] < a[j];
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i ++) scanf("%d", &a[i]), id[i] = i;
  sort(id, id + n, cmp);
  for(int i = 0; i * 2 < n; i ++) {
    printf("%d %d\n", id[i] + 1, id[n - 1 - i] + 1);
  }
  return 0;
}