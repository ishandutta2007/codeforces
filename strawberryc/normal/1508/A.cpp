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

const int N = 1e6 + 5;

int n;
char s[4][N];

void work() {
  int cnt1 = 0, cnt2 = 0, cnt3 = 0;
  char c;
  read(n);
  scanf("%s%s%s", s[1] + 1, s[2] + 1, s[3] + 1);
  int o1, o2;
  for (int i = 1; i <= n * 2; i++) {
  	if (s[1][i] == '0') cnt1++;
  	if (s[2][i] == '0') cnt2++;
  	if (s[3][i] == '0') cnt3++;
  }
  if (!((cnt1 <= n) ^ (cnt2 <= n))) o1 = 1, o2 = 2, c = '0' + (cnt1 <= n);
  if (!((cnt1 <= n) ^ (cnt3 <= n))) o1 = 1, o2 = 3, c = '0' + (cnt3 <= n);
  if (!((cnt2 <= n) ^ (cnt3 <= n))) o1 = 2, o2 = 3, c = '0' + (cnt2 <= n);
  int tot = 0, j = 1;
  for (int i = 1; i <= n * 2; i++)
    if (s[o1][i] != c) putchar(s[o1][i]), tot++;
    else {
      while (j <= n * 2 && s[o2][j] != c) putchar(s[o2][j]), j++, tot++;
      putchar(s[o1][i]); tot++; j++;
	}
  while (j <= n * 2) putchar(s[o2][j]), j++, tot++;
  for (int i = 1; i <= 3 * n - tot; i++) putchar('0');
  puts("");
}

int main() {
  int T; read(T);
  while (T--) work();
  return 0;
}