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

int n;

bool sqr(int n) {
  int m = sqrt(n);
  return m * m == n;
}

void work() {
  read(n);
  puts((n % 2 == 0 && sqr(n / 2)) || (n % 4 == 0 && sqr(n / 4))
    ? "YES" : "NO");
}

int main() {
  int T; read(T);
  while (T--) work();
  return 0;
}