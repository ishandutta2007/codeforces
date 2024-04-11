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

const int N = 1e5 + 5;

int n, cnt0, a[N], m;

void yhjssa() {
  read(n); cnt0 = 0;
  for (int i = 1; i <= n; i++) read(a[i]), cnt0 += a[i] == 0;
  if (a[n] == 0) return (void) puts("0");
  m = n - cnt0;
  for (int i = 1; i <= m; i++) a[i] = a[i + cnt0];
  for (int T = 1; T < n; T++) {
  	if (!cnt0) {
  	  for (int i = 1; i < m; i++) a[i] = a[i + 1] - a[i];
  	  m--; std::sort(a + 1, a + m + 1);
  	  for (int i = 1; i <= m; i++) cnt0 += a[i] == 0;
  	  m -= cnt0;
  	  for (int i = 1; i <= m; i++) a[i] = a[i + cnt0];
    }
    else {
      for (int i = m; i >= 2; i--) a[i] -= a[i - 1];
      cnt0--; std::sort(a + 1, a + m + 1);
      int cnt1 = 0;
      for (int i = 1; i <= m; i++) cnt1 += a[i] == 0;
      cnt0 += cnt1; m -= cnt1;
      for (int i = 1; i <= m; i++) a[i] = a[i + cnt1];
	}
	if (!m) return (void) puts("0");
  }
  printf("%d\n", a[1]);
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}