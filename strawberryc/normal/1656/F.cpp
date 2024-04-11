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

typedef long long ll;

const int N = 2e5 + 5;

int n, a[N];
ll s1[N], s2[N];

void yhjssa() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  std::sort(a + 1, a + n + 1);
  s1[0] = s2[n + 1] = 0;
  for (int i = 1; i <= n; i++) s1[i] = s1[i - 1] + a[i];
  for (int i = n; i >= 1; i--) s2[i] = s2[i + 1] + a[i];
  ll sp = 0;
  for (int i = 2; i <= n; i++) sp += a[1] + a[i];
  if (sp > 0) return (void) puts("INF");
  sp = 0;
  for (int i = 1; i < n; i++) sp += a[i] + a[n];
  if (sp < 0) return (void) puts("INF");
  ll ans = -1e18;
  for (int i = 1; i <= n; i++) {
  	int t = -a[i];
  	ll cur = 0;
  	if (1 < i && i < n) cur = (1ll * (n - i) * t + s2[i + 1]) * (a[1] + t)
  	  + (1ll * (i - 1) * t + s1[i - 1]) * (a[n] + t) - 1ll * (a[1] + t) * (a[n] + t);
  	cur -= 1ll * (n - 1) * t * t;
  	if (cur > ans) ans = cur;
  }
  printf("%lld\n", ans);
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}