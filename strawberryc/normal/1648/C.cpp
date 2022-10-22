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

const int N = 2e5 + 5, wd = 998244353, L = 2e5;

int n, m, s[N], t[N], fac[N], inv[N], invf[N], cur, cnt[N], A[N], ans;

void change(int x, int v) {
  for (; x <= L; x += x & -x) A[x] += v;
}

int ask(int x) {
  int res = 0;
  for (; x; x -= x & -x) res += A[x];
  return res;
}

int main() {
  read(n); read(m);
  for (int i = 1; i <= n; i++) read(s[i]), cnt[s[i]]++;
  for (int i = 1; i <= m; i++) read(t[i]);
  if (n < m) t[n]++;
  else if (n > m) for (int i = n; i > m; i--) t[i] = 1;
  fac[0] = inv[1] = invf[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % wd;
  for (int i = 2; i <= n; i++) inv[i] = 1ll * (wd - wd / i) * inv[wd % i] % wd;
  for (int i = 1; i <= n; i++) invf[i] = 1ll * inv[i] * invf[i - 1] % wd;
  cur = fac[n];
  for (int i = 1; i <= L; i++) cur = 1ll * cur * invf[cnt[i]] % wd;
  for (int i = 1; i <= n; i++) change(s[i], 1);
  for (int i = 1; i <= n; i++) {
  	ans = (1ll * ask(t[i] - 1) * inv[n - i + 1] % wd * cur + ans) % wd;
  	if (!cnt[t[i]]) return std::cout << ans << std::endl, 0;
  	cnt[t[i]]--; cur = 1ll * invf[n - i + 1] * fac[n - i] % wd * cur % wd;
  	cur = 1ll * fac[cnt[t[i]] + 1] % wd * invf[cnt[t[i]]] % wd * cur % wd;
  	change(t[i], -1);
  }
  return std::cout << ans << std::endl, 0;
}