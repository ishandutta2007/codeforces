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

const int N = 55;

int n, m;
char s[N], t[N];

void yhjssa() {
  read(n); read(m);
  scanf("%s%s", s + 1, t + 1);
  bool have0 = 0, have1 = 0;
  for (int i = 1; i <= n - m + 1; i++)
    have0 |= s[i] == '0', have1 |= s[i] == '1';
  if ((!have0 && t[1] == '0') || (!have1 && t[1] == '1')) return (void) puts("NO");
  for (int i = 0; i < m - 1; i++)
    if (s[n - i] != t[m - i]) return (void) puts("NO");
  puts("YES");
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}