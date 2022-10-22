#include <bits/stdc++.h>

const int N = 1e6 + 5, wd = 998244353;

int n, f[N];

int main() {
  std::cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j += i)
      f[j]++;
  for (int i = 1, s = 0; i <= n; i++)
    f[i] = (f[i] + s) % wd, s = (s + f[i]) % wd;
  return std::cout << f[n] << std::endl, 0;
}