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

void yhjssa() {
  int x, y;
  read(x); read(y);
  if (x > y) return (void) printf("%lld\n", 1000000000ll * x + y);
  else return (void) printf("%d\n", y - y % x / 2);
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}