#include <bits/stdc++.h>

const int N = 200005;
const int Q = 998244353;

int n;
char a[N];

int inverse(int x) {
  return x == 1 ? 1 : 1LL * (Q - Q / x) * inverse(Q % x) % Q;
}

void work() {
  scanf("%d%s", &n, a);
  int cur = -1;
  int even = 0, odd = 0, cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (i + 1 == n || a[i] != a[i + 1]) {
      if (a[i] == '0') {
        cnt += i - cur;
      } else {
        even += (i - cur) / 2;
        odd += (i - cur + 1) / 2;
      }
      cur = i;
    }
  }
  // C(cnt + even , even)
  int res = 1;
  cnt += even;
  for (int i = 1; i <= even; ++i) {
    res = 1LL * res * (cnt - i + 1) % Q;
    res = 1LL * res * inverse(i) % Q;
  }
  // printf("%d %d\n", cnt + even, even);
  printf("%d\n", res);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}