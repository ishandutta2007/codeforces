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
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 105, M = 1e4 + 5, INF = 0x3f3f3f3f;

int n, a[N], b[N], sa[N], sb[N], f[N][M];

void yhjssa() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]), sa[i] = sa[i - 1] + a[i];
  for (int i = 1; i <= n; i++) read(b[i]), sb[i] = sb[i - 1] + b[i];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= 10000; j++)
      f[i][j] = INF;
  int delta = 0, ans = INF;
  for (int i = 1; i <= n; i++) delta += (n - 1) * (a[i] * a[i] + b[i] * b[i]);
  f[0][0] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= 10000; j++) {
      if (f[i][j] == INF) continue;
      f[i + 1][j + a[i + 1]] = Min(f[i + 1][j + a[i + 1]],
	    f[i][j] + a[i + 1] * j + b[i + 1] * (sa[i] + sb[i] - j));
	  f[i + 1][j + b[i + 1]] = Min(f[i + 1][j + b[i + 1]],
	    f[i][j] + b[i + 1] * j + a[i + 1] * (sa[i] + sb[i] - j));
	}
  for (int i = 0; i <= 10000; i++) ans = Min(ans, f[n][i]);
  printf("%d\n", delta + 2 * ans);
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}