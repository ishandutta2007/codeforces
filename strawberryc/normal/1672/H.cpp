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

const int N = 2e5 + 5;

int n, q, s0[N], s1[N];
char s[N];

int main() {
  int l, r;
  read(n); read(q);
  scanf("%s", s + 1);
  for (int i = 1; i < n; i++) s0[i] = s0[i - 1] + (s[i] == '0' && s[i + 1] == '0');
  for (int i = 1; i < n; i++) s1[i] = s1[i - 1] + (s[i] == '1' && s[i + 1] == '1');
  while (q--) {
  	read(l); read(r);
  	printf("%d\n", Max(s1[r - 1] - s1[l - 1], s0[r - 1] - s0[l - 1]) + 1);
  }
  return 0;
}