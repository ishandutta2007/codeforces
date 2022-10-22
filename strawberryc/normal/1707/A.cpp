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

int n, q, a[N];
char ans[N];

void yhjssa() {
  read(n); read(q);
  for (int i = 1; i <= n; i++) read(a[i]), ans[i] = '1';
  for (int i = n, cur = 0; i >= 1; i--) {
  	if (a[i] > cur) cur++;
  	if (cur > q) cur--, ans[i] = '0';
  }
  for (int i = 1; i <= n; i++) putchar(ans[i]);
  puts("");
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}