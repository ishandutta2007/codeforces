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

const int N = 105;

int n, u, v, a[N];

void work() {
  read(n); read(u); read(v);
  for (int i = 1; i <= n; i++) read(a[i]);
  bool is = 1;
  for (int i = 2; i <= n; i++) if (a[i] != a[i - 1]) is = 0;
  if (is) return (void) printf("%d\n", Min(u + v, v * 2));
  for (int i = 1; i < n; i++) if (abs(a[i] - a[i + 1]) > 1)
    return (void) puts("0");
  printf("%d\n", Min(u, v));
}

int main() {
  int T; read(T);
  while (T--) work();
  return 0;
}