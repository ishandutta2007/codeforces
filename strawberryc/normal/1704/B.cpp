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

const int N = 2e5 + 5;

int n, x, a[N];

void yhjssa() {
  read(n); read(x);
  for (int i = 1; i <= n; i++) read(a[i]);
  int ans = 0;
  for (int i = 1, mi = a[1], mx = a[1]; i <= n; i++) {
  	mi = std::min(mi, a[i]); mx = std::max(mx, a[i]);
  	if (mx - mi > 2 * x) ans++, mi = a[i], mx = a[i];
  }
  printf("%d\n", ans);
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}