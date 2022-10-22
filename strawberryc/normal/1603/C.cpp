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

const int N = 1e5 + 5, wd = 998244353;

int n, a[N], ans, tot, mi[N], mx[N], cnt[N], w[N], _tot, _mi[N], _mx[N], _cnt[N], _w[N];

void yhjssa() {
  read(n); ans = 0; tot = cnt[1] = 1;
  for (int i = 1; i <= n; i++) read(a[i]);
  int cur = 0;
  mi[1] = mx[1] = a[n]; w[1] = 0;
  for (int i = n - 1; i >= 1; i--) {
  	_tot = 0;
  	for (int j = 1; ;) {
  	  _mx[++_tot] = (a[i] + j - 1) / j; _mi[_tot] = _mx[_tot] - (a[i] % j > 0);
	  _cnt[_tot] = 0; _w[_tot] = j - 1;
	  if (j >= a[i]) break;
	  else j = (a[i] - 1) / (_mx[_tot] - 1) + 1;
	}
	_cnt[1] = 1;
	for (int j = 1, k = 1; j <= tot; j++) {
	  while (mi[j] < _mx[k]) k++;
	  _cnt[k] += cnt[j];
	}
	tot = _tot;
	for (int j = 1; j <= tot; j++) mx[j] = _mx[j], mi[j] = _mi[j],
	  w[j] = _w[j], cnt[j] = _cnt[j], cur = (1ll * cnt[j] * w[j] + cur) % wd;
	ans = (ans + cur) % wd;
  }
  printf("%d\n", ans);
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}