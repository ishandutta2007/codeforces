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

const int N = 1e5 + 5;

int n, a[N], b[N], fa[N], sze[N];

int cx(int x) {
  if (fa[x] != x) fa[x] = cx(fa[x]);
  return fa[x];
}

void zm(int x, int y) {
  if ((x = cx(x)) != (y = cx(y))) fa[y] = x, sze[x] += sze[y];
}

int main() {
  int T; read(T);
  while (T--) {
  	read(n);
  	for (int i = 1; i <= n; i++) fa[i] = i, sze[i] = 1;
  	for (int i = 1; i <= n; i++) read(a[i]);
  	for (int i = 1; i <= n; i++) read(b[i]);
  	for (int i = 1; i <= n; i++) zm(a[i], b[i]);
  	ll ans = 0;
  	int cnt = 0;
  	for (int i = 1; i <= n; i++) if (fa[i] == i) cnt += sze[i] / 2;
  	for (int i = 1; i <= cnt; i++) ans += n + 1 - 2 * i;
  	printf("%lld\n", ans * 2);
  }
  return 0;
}