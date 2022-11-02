#include <bits/stdc++.h>
using namespace std;
#define M 40000

int p[M], flag[M], cnt;

void init() {
  for (int i = 2; i < M; i++) {
    if (flag[i]) continue;
    p[cnt++] = i;
    for (int j = 2 * i; j < M; j += i) flag[j] = 1;
  }
}

int a[M], b[M];

int main() {
  //freopen("in.txt", "r", stdin);
  init();
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int m = 0;
  for (int i = 0; i < n - 1; i++) {
    b[m++] = a[i];
    int d = __gcd(a[i], a[i + 1]);
    if (d > 1) {
      for (int j = 0; j < cnt; j++) {
        if ((a[i] % p[j]) && (a[i + 1] % p[j])) {b[m++] = p[j]; break;}
      }
    }
  }
  b[m++] = a[n - 1];
  printf("%d\n", m - n);
  for (int i = 0; i < m; i++) printf("%d ", b[i]);
}