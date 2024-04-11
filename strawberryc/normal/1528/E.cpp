#include <bits/stdc++.h>

const int N = 1e6 + 5, wd = 998244353, I2 = 499122177, I6 = 166374059;

int f[N], f2[N], f3[N], s[N];

int solve(int n) {
  f[0] = 1;
  for (int i = 1; i <= n; i++)
    f[i] = (1ll * f[i - 1] * (f[i - 1] + 1) % wd * I2 + f[i - 1] + 1) % wd;
  for (int i = 1; i <= n; i++)
    f2[i] = 1ll * f[i - 1] * (f[i - 1] + 1) % wd * I2 % wd;
  for (int i = 1; i <= n; i++)
    f3[i] = 1ll * f[i - 1] * (f[i - 1] + 1) % wd * (f[i - 1] + 2) % wd * I6 % wd;
  int ans = 2ll * (f2[n] + f3[n]) % wd;
  ans = (ans - 2ll * (f2[n - 1] + f3[n - 1]) % wd + wd) % wd;
  for (int i = n; i >= 1; i--) f2[i] = (f2[i] - f2[i - 1] + wd) % wd;
  f2[0] = s[0] = 1;
  for (int i = 1; i <= n; i++) s[i] = (s[i - 1] + f2[i]) % wd;
  for (int i = 0; i < n; i++) ans = (1ll * f2[i] * s[n - 1 - i] + ans) % wd;
  return ans;
}

int main() {
  int n; std::cin >> n;
  return std::cout << solve(n) << std::endl, 0;
}