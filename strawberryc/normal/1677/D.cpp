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

const int wd = 998244353;

const int N = 1e6 + 5;

int n, k, v[N], ans;

int main() {
  int T; read(T);
  while (T--) {
  	read(n); read(k);
  	for (int i = 1; i <= n; i++) read(v[i]);
  	ans = 1;
  	for (int i = n; i > n - k; i--) if (v[i] && v[i] != -1) ans = 0;
  	if (!ans) {puts("0"); continue;}
  	for (int i = 1; i <= k; i++) ans = 1ll * ans * i % wd;
  	for (int i = 1; i <= n - k; i++) {
  	  int delta = 1;
  	  if (!v[i]) delta = k + 1;
  	  else if (v[i] == -1) delta = k + i;
  	  ans = 1ll * ans * delta % wd;
	}
  	printf("%d\n", ans);
  }
  return 0;
}