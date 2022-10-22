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

const int N = 2e5 + 5;

int n, id[N];
char s[N], resa[N], resb[N];

void work() {
  read(n);
  scanf("%s", s + 1);
  int cnt0 = 0, cnt1 = 0;
  for (int i = 1; i <= n; i++)
    if (s[i] == '1') id[i] = ++cnt1; else id[i] = ++cnt0;
  if ((cnt1 & 1) || (cnt0 & 1)) return (void) puts("NO");
  for (int i = 1, cura = 0, curb = 0; i <= n; i++) {
  	if (s[i] == '1') resa[i] = resb[i] = id[i] <= cnt1 / 2 ? '(' : ')';
  	else if (id[i] & 1) resa[i] = '(', resb[i] = ')';
  	else resa[i] = ')', resb[i] = '(';
  	cura += resa[i] == '(' ? 1 : -1;
  	curb += resb[i] == '(' ? 1 : -1;
  	if (cura < 0 || curb < 0) return (void) puts("NO");
  }
  puts("YES");
  for (int i = 1; i <= n; i++) putchar(resa[i]);
  puts("");
  for (int i = 1; i <= n; i++) putchar(resb[i]);
  puts("");
}

int main() {
  int T; read(T);
  while (T--) work();
  return 0;
}