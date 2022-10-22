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

const int N = 105;

int n, a[N], x;

void work() {
  int s = 0;
  read(n); read(x);
  for (int i = 1; i <= n; i++) read(a[i]), s += a[i];
  if (s == x) return (void) puts("NO");
  puts("YES"); s = 0;
  for (int i = 1; i <= n; i++) {
  	if (s + a[i] == x) std::swap(a[i], a[i + 1]);
  	s += a[i]; printf("%d ", a[i]);
  }
  puts("");
}

int main() {
  int T; read(T);
  while (T--) work();
  return 0;
}