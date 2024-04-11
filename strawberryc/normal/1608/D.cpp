#include <bits/stdc++.h>

const int N = 1e5 + 5, M = N << 3, wd = 998244353;

int n, ans, bb, ww, _b, _w, __, fac[N], inv[N];
char s[N][2];

int C(int n, int m) {
  if (n < 0 || m < 0 || n < m) return 0;
  return 1ll * fac[n] * inv[m] % wd * inv[n - m] % wd;
}

int main() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) scanf("%s", s[i]);
  for (int i = 1; i <= n; i++) {
  	if (s[i][0] == 'B' && s[i][1] == 'B') bb++;
  	if (s[i][0] == 'W' && s[i][1] == 'W') ww++;
  	if ((s[i][0] == 'B' && s[i][1] == '?')
	  || (s[i][0] == '?' && s[i][1] == 'B')) _b++;
	if ((s[i][0] == 'W' && s[i][1] == '?')
	  || (s[i][0] == '?' && s[i][1] == 'W')) _w++;
	if (s[i][0] == '?' && s[i][1] == '?') __++;
  }
  if (!bb && !ww) {
  	ans = 1;
  	for (int i = 1; i <= __; i++) ans = (ans << 1) % wd;
  	bool is = 1;
  	for (int i = 1; i <= n; i++)
  	  if (s[i][0] == 'B' || s[i][1] == 'W') is = 0;
  	if (is) ans = (ans + wd - 1) % wd;
  	is = 1;
  	for (int i = 1; i <= n; i++)
  	  if (s[i][0] == 'W' || s[i][1] == 'B') is = 0;
  	if (is) ans = (ans + wd - 1) % wd;
  	ans = (wd - ans) % wd;
  }
  fac[0] = inv[0] = inv[1] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % wd;
  for (int i = 2; i <= n; i++) inv[i] = 1ll * (wd - wd / i) * inv[wd % i] % wd;
  for (int i = 2; i <= n; i++) inv[i] = 1ll * inv[i] * inv[i - 1] % wd;
  for (int i = 0; i <= __; i++)
    ans = (1ll * C(__, i) * C(_w + _b + __, _w + i + ww - bb) + ans) % wd;
  return std::cout << ans << std::endl, 0;
}