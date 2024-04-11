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

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 1e4 + 5;

int n, a[N], b[N], c[N];

void yhjssa() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  b[0] = 0; c[n + 1] = 1e9 + 1;
  for (int i = 1; i <= n; i++) b[i] = Max(b[i - 1], a[i]);
  for (int i = n; i >= 1; i--) c[i] = Min(c[i + 1], a[i]);
  for (int i = 1; i < n; i++)
    if (b[i] > c[i]) return (void) puts("YES");
  puts("NO");
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}