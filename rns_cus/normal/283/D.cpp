#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define N 5050

int n;
LL a[N];
int f[N];

void run() {
  int ans = n;
  f[1] = 0;
  for(int i = 2; i <= n; i ++) {
    LL x = a[i];
    f[i] = i - 1;
    int tp;
    for(int j = i - 1; j; j --) {
      if(!(x & 1)) {
        x >>= 1;
        if(a[j] % x != 0 || !((a[j]/x) & 1)) continue;
      } else if(a[j] % x != 0) continue;
      tp = f[j] + i - j - 1;
      if(f[i] > tp) f[i] = tp;
    }
  }
  for(int i = 1; i <= n; i ++) {
    int tp = f[i] + n - i;
    if(ans > tp) ans = tp;
  }
  printf("%d\n", ans);
}

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  for(int i = 1 ;i <= n; i ++) scanf("%I64d", a + i);
  run();
  return 0;
}