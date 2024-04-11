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

const int N = 105;

int n, a[N], mex[N][N], f[N][N];
bool vis[N];

void yhjssa() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++) {
  	for (int j = i; j <= n; j++) {
  	  if (a[j] <= n) vis[a[j]] = 1;
  	  mex[i][j] = 0;
  	  while (vis[mex[i][j]]) mex[i][j]++;
	}
	for (int j = i; j <= n; j++) if (a[j] <= n) vis[a[j]] = 0;
  }
  int ans = 0;
  for (int l = n; l >= 1; l--)
    for (int r = l; r <= n; r++) {
      f[l][r] = mex[l][r] + 1;
      for (int i = l; i < r; i++)
        f[l][r] = Max(f[l][r], f[l][i] + f[i + 1][r]);
      ans += f[l][r];
	}
  printf("%d\n", ans);
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}