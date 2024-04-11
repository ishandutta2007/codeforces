#include <bits/stdc++.h>

using namespace std;

const int N = 77777;

int cnt[N], a[N], ans[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i]--;
  }
  for (int i = 0; i < n; i++) {
    ans[i] = 0;
  }
  for (int start = 0; start < n; start++) {
    for (int i = 0; i < n; i++) {
      cnt[i] = 0;
    }
    int best = 0;
    for (int i = start; i < n; i++) {
      cnt[a[i]]++;
      if (cnt[a[i]] > cnt[best] || (cnt[a[i]] == cnt[best] && a[i] < best)) {
        best = a[i];
      }
      ans[best]++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}