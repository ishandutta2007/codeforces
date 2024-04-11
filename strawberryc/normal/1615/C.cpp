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

int n;
char s[N], t[N];

void yhjssa() {
  read(n);
  scanf("%s%s", s + 1, t + 1);
  int ans = 1111111, cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n; i++) cnt1 += s[i] == '1', cnt2 += t[i] == '1';
  if (cnt1 == cnt2) {
  	ans = 0;
  	for (int i = 1; i <= n; i++) if (s[i] != t[i]) ans++;
  }
  int ans2 = 1111111;
  for (int i = 1; i <= n; i++) s[i] = s[i] == '0' ? '1' : '0';
  cnt1 = cnt2 = 0;
  for (int i = 1; i <= n; i++) cnt1 += s[i] == '1', cnt2 += t[i] == '1';
  if (cnt1 + 1 == cnt2) {
  	ans2 = 0;
  	for (int i = 1; i <= n; i++) if (s[i] != t[i]) ans2++;
  	for (int i = 1; i <= n; i++) if (s[i] == '0') {
  	  int res = ans2 - (s[i] != t[i]) + (s[i] == t[i]);
  	  if (res + 1 < ans) ans = res + 1;
	}
  }
  printf("%d\n", ans == 1111111 ? -1 : ans);
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}