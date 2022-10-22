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

const int N = 2005, wd = 1e9 + 7;

int n, f[N][N], g[N][N], sf[N][N], sg[N][N], ans, ns[N], nt[N];
char s[N], t[N];

int sumf(int l, int r, int x, int y) {
  int res = sf[r][y];
  if (l) res = (res - sf[l - 1][y] + wd) % wd;
  if (x) res = (res - sf[r][x - 1] + wd) % wd;
  if (l && x) res = (res + sf[l - 1][x - 1]) % wd;
  return res;
}

int sumg(int l, int r, int x, int y) {
  int res = sg[r][y];
  if (l) res = (res - sg[l - 1][y] + wd) % wd;
  if (x) res = (res - sg[r][x - 1] + wd) % wd;
  if (l && x) res = (res + sg[l - 1][x - 1]) % wd;
  return res;
}

void yhjssa() {
  read(n); ans = 0;
  scanf("%s%s", s + 1, t + 1);
  for (int i = 2; i <= n; i += 2) {
  	if (s[i] == '0') s[i] = '1';
  	else if (s[i] == '1') s[i] = '0';
  	if (t[i] == '0') t[i] = '1';
  	else if (t[i] == '1') t[i] = '0';
  }
  for (int i = 1, c1 = 0, c2 = 0; i <= n + 1; i++) {
  	ns[i] = c1; nt[i] = c2;
  	if (s[i] == '1') c1 = i;
  	if (t[i] == '1') c2 = i;
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      f[i][j] = sf[i][j] = g[i][j] = sg[i][j] = 0;
  f[0][0] = 1;
  for (int i = 0; i <= n; i++) sf[i][0] = sf[0][i] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (s[i] != '0' && t[j] != '0') {
      	int delta = sumf(ns[i], i - 1, nt[j], j - 1);
      	f[i][j] = delta;
      	g[i][j] = (1ll * abs(i - j) * delta + sumg(ns[i], i - 1, nt[j], j - 1)) % wd;
	  }
	  sf[i][j] = (1ll * f[i][j] + sf[i - 1][j] + sf[i][j - 1]
	    - sf[i - 1][j - 1] + wd) % wd;
	  sg[i][j] = (1ll * g[i][j] + sg[i - 1][j] + sg[i][j - 1]
	    - sg[i - 1][j - 1] + wd) % wd;
	}
  printf("%d\n", sumg(ns[n + 1], n, nt[n + 1], n));
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}