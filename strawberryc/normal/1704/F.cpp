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

const int N = 5e5 + 5;

int n, SG[N], SG1[N], vis[N];
char s[N];

void yhjssa() {
  read(n);
  scanf("%s", s + 1);
  int cntr = 0, cntb = 0;
  for (int i = 1; i <= n; i++) cntr += s[i] == 'R', cntb += s[i] == 'B';
  if (cntr > cntb) return (void) puts("Alice");
  if (cntr < cntb) return (void) puts("Bob");
  int ans = 0;
  for (int i = 1, c = 0; i <= n; i++) {
  	c++;
  	if (i == n || s[i] == s[i + 1]) ans ^= SG[c], c = 0;
  }
  puts(ans ? "Alice" : "Bob");
}

int main() {
  for (int i = 2; i <= 500000; i++) {
  	for (int j = 0; j <= i - 2 && j <= 100; j++) vis[SG[j] ^ SG[i - 2 - j]] = i;
  	while (vis[SG[i]] == i) SG[i]++;
  }
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}