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
  int x; bool res = 1;
  read(n);
  for (int t = 1; t <= n; t++) {
  	read(x); bool is = 0;
  	for (int i = 2; i <= t + 1; i++)
  	  if (x % i) {is = 1; break;}
  	res &= is;
  }
  puts(res ? "YES" : "NO");
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}