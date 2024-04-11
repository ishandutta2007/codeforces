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

int n, a[N];

void yhjssa() {
  bool is0 = 0, is1 = 0, is = 0;
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++)
    is0 |= a[i] == 0, is1 |= a[i] == 1;
  if (is0 && is1) return (void) puts("no");
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i < n; i++) if (a[i] + 1 == a[i + 1]) is = 1;
  puts(is1 && is ? "no" : "yes");
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}