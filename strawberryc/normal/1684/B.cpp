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

int a, b, c;

int main() {
  int T; read(T);
  while (T--) {
  	read(a); read(b); read(c);
  	printf("%d %d %d\n", a + b + c, b + c, c);
  }
  return 0;
}