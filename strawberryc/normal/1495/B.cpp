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

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 1e5 + 5;

int n, p[N], lex[N], rix[N], ley[N], riy[N], dx[N], maxd, pos;

int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(p[i]);
  for (int i = 1; i <= n; i++) {
  	lex[i] = i == 1 || p[i - 1] > p[i] ? 0 : 1 + lex[i - 1];
  	ley[i] = i == 1 || p[i - 1] < p[i] ? 0 : 1 + ley[i - 1];
  }
  for (int i = n; i >= 1; i--) {
  	rix[i] = i == n || p[i + 1] > p[i] ? 0 : 1 + rix[i + 1];
  	riy[i] = i == n || p[i + 1] < p[i] ? 0 : 1 + riy[i + 1];
  }
  for (int i = 1; i <= n; i++) dx[i] = Max(lex[i], rix[i]),
    maxd = Max(maxd, dx[i]);
  int cnt = 0;
  for (int i = 1; i <= n; i++) if (dx[i] == maxd) cnt++, pos = i;
  if (cnt > 1) return puts("0"), 0;
  return printf("%d\n", lex[pos] == rix[pos] ? !(maxd & 1) : 0), 0;
}