#include <bits/stdc++.h>

const int max_N = (int)2e5 + 21;

int n, p[max_N];

long long s[max_N], bit[max_N];

void bit_add(int x, int y) {
  for (; x && x <= n; x += (x & -x)) {
    bit[x] += y;
  }
}

int bit_query(long long k) {
  int ans = 0;
  for (int i = (1 << 20); i; i >>= 1) {
    if (ans + i > n || bit[ans + i] >= k)
      continue;
    k -= bit[ans += i];
  }
  return ans + 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", s + i);
    bit_add(i, i);
  }
  for (int i = n; i; --i) {
    p[i] = bit_query(s[i] + 1);
    bit_add(p[i], -p[i]);
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", p[i], " \n"[i == n]);
  }
}