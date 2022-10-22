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

void yhjssa() {
  int mi, mx, cx = 0, ci = 1145141145, x;
  read(n);
  for (int i = 1; i <= n; i++) {
  	read(x);
  	if (x > cx) cx = x, mx = i;
  	if (x < ci) ci = x, mi = i;
  }
  printf("%d %d\n", mi, mx);
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}