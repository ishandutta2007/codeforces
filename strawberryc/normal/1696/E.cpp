#include <bits/stdc++.h>

template <class T>
inline void read(T &res) {
  res = 0; bool bo = 0; char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');
  if (c == '-') bo = 1; else res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  if (bo) res = ~res + 1;
}

const int N = 5e5 + 5, wd = 1e9 + 7;

int n, fac[N], inv[N];

int main() {
  int x, ans = 0;
  read(n);
  fac[0] = inv[0] = inv[1] = 1;
  for (int i = 1; i <= 500000; i++) fac[i] = 1ll * fac[i - 1] * i % wd;
  for (int i = 2; i <= 500000; i++) inv[i] = 1ll * (wd - wd / i) * inv[wd % i] % wd;
  for (int i = 2; i <= 500000; i++) inv[i] = 1ll * inv[i] * inv[i - 1] % wd;
  for (int i = 0; i <= n; i++) read(x),
    ans = (1ll * fac[i + x] * inv[i + 1] % wd * inv[x - 1] + ans) % wd;
  return std::cout << ans << std::endl, 0;
}