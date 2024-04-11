#include <bits/stdc++.h>

const int N = 2005, M = N << 1, wd = 998244353;

int r, c, ans, cntx[N], cnty[N], fa[M], sze[M], cnt[M];
char s[N][N];
bool sumx[N], sumy[N], csx[M];

int cx(int x) {
  if (fa[x] != x) fa[x] = cx(fa[x]);
  return fa[x];
}

void zm(int x, int y) {
  if ((x = cx(x)) != (y = cx(y)))
    fa[y] = x, sze[x] += sze[y], cnt[x] += cnt[y], csx[x] ^= csx[y];
}

int solve() {
  int res = 1;
  for (int i = 1; i <= r + c; i++) fa[i] = i, sze[i] = 1,
    cnt[i] = i <= r ? cntx[i] : cnty[i - r], csx[i] = i <= r ? sumx[i] : sumy[i - r];
  for (int i = 1; i <= r; i++)
    for (int j = 1; j <= c; j++)
      if (s[i][j] == '?') zm(i, j + r);
  for (int i = 1; i <= r + c; i++) if (fa[i] == i) {
  	if (csx[i]) return 0;
  	for (int j = 1; j <= (cnt[i] >> 1) - sze[i] + 1; j++)
  	  res = (res << 1) % wd;
  }
  return res;
}

int main() {
  std::cin >> r >> c;
  for (int i = 1; i <= r; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= r; i++)
    for (int j = 1; j <= c; j++)
      if (s[i][j] == '1') sumx[i] ^= 1, sumy[j] ^= 1;
      else if (s[i][j] == '?') cntx[i]++, cnty[j]++;
  if (!(r & 1) && !(c & 1)) {
  	ans = 1;
  	for (int i = 1; i <= r; i++)
  	  for (int j = 1; j <= c; j++)
  	    if (s[i][j] == '?') ans = (ans << 1) % wd;
  	return printf("%d\n", ans), 0;
  }
  if (!(r & 1)) {
  	ans = 1;
  	for (int i = 1; i <= r; i++) {
  	  int cnt = 0;
  	  for (int j = 1; j <= c; j++) if (s[i][j] == '?') cnt++;
  	  if (!cnt) {if (sumx[i]) ans = 0;}
  	  else for (int j = 1; j < cnt; j++) ans = (ans << 1) % wd;
	}
	int res = 1;
	for (int i = 1; i <= r; i++) {
	  int cnt = 0;
	  for (int j = 1; j <= c; j++) if (s[i][j] == '?') cnt++;
	  if (!cnt) {if (!sumx[i]) res = 0;}
	  else for (int j = 1; j < cnt; j++) res = (res << 1) % wd;
	}
	return printf("%d\n", (ans + res) % wd), 0;
  }
  if (!(c & 1)) {
  	ans = 1;
  	for (int i = 1; i <= c; i++) {
  	  int cnt = 0;
  	  for (int j = 1; j <= r; j++) if (s[j][i] == '?') cnt++;
  	  if (!cnt) {if (sumy[i]) ans = 0;}
  	  else for (int j = 1; j < cnt; j++) ans = (ans << 1) % wd;
	}
	int res = 1;
	for (int i = 1; i <= c; i++) {
	  int cnt = 0;
	  for (int j = 1; j <= r; j++) if (s[j][i] == '?') cnt++;
	  if (!cnt) {if (!sumy[i]) res = 0;}
	  else for (int j = 1; j < cnt; j++) res = (res << 1) % wd;
	}
	return printf("%d\n", (ans + res) % wd), 0;
  }
  ans = solve();
  for (int i = 1; i <= r; i++) sumx[i] ^= 1;
  for (int i = 1; i <= c; i++) sumy[i] ^= 1;
  return std::cout << (ans + solve()) % wd << std::endl, 0;
}