#include <bits/stdc++.h>
using namespace std;
#define N 100100

int a, s[N], n;

int main() {
 // freopen("c.in", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++) scanf("%d", &a), s[i] = s[i-1] + a;
  int ans = 0;
  for (int i = 1; i < n; i ++) if (s[i] * 2 == s[n]) ans ++;
  printf("%d\n", ans);
}