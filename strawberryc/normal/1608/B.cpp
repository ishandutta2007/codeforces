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

int n, a, b;

void yhjssa() {
  read(n); read(a); read(b);
  if (a + b > n - 2) return (void) puts("-1");
  if (a != b && a != b + 1 && b != a + 1) return (void) puts("-1");
  if (a == b) {
  	for (int i = 1; i <= a; i++) printf("%d %d ", i, n - i + 1);
  	for (int i = a + 1; i <= n - a; i++) printf("%d ", i);
  	puts("");
  }
  else if (a > b) {
  	for (int i = 1; i <= a; i++) printf("%d %d ", i, n - i + 1);
  	for (int i = n - a; i > a; i--) printf("%d ", i);
  	puts("");
  }
  else {
    for (int i = 1; i <= b; i++) printf("%d %d ", n - i + 1, i);
    for (int i = b + 1; i <= n - b; i++) printf("%d ", i);
    puts("");
  }
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}