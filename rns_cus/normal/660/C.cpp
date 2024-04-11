#include <bits/stdc++.h>
using namespace std;
#define M 300010

int n, K, cnt[M], en, a[M];

bool check(int m) {
  for (int i = m; i <= n; i++) {
    if (cnt[i] - cnt[i - m] <= K) {en = i; return 1;}
  }
  return 0;
}

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d", &n, &K);
  int x;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x); cnt[i] = cnt[i - 1] + !x;
    a[i] = x;
  }
  int l = 0, r = n + 1;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (check(mid)) l = mid;
    else r = mid - 1;
  }
  printf("%d\n", l);
  for (int i = 1; i <= en - l; i++) printf("%d ", a[i]);
  for (int i = en - l + 1; i <= en; i++) printf("1 ");
  for (int i = en + 1; i <= n; i++) printf("%d ", a[i]);
}