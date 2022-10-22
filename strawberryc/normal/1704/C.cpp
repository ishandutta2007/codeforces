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

int n, m, a[N], b[N], ans;

void yhjssa() {
  read(n); read(m); ans = m;
  for (int i = 1; i <= m; i++) read(a[i]);
  std::sort(a + 1, a + m + 1);
  for (int i = 1; i < m; i++) b[i] = a[i + 1] - a[i] - 1;
  b[m] = n - a[m] + a[1] - 1;
  std::sort(b + 1, b + m + 1);
  for (int i = m, t = 0; i >= 1; i--) {
  	if (b[i] <= 2 * t) {ans += b[i]; continue;}
  	if (b[i] <= 2 * t + 2) {ans += b[i] - 1; t++; continue;}
  	ans += 2 * t + 1; t += 2;
  }
  printf("%d\n", ans);
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}