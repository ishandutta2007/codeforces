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

int n, m, fa[N];

int cx(int x) {
  if (fa[x] != x) fa[x] = cx(fa[x]);
  return fa[x];
}

void work() {
  int x, y, ans = 0;
  read(n); read(m);
  for (int i = 1; i <= n; i++) fa[i] = i;
  while (m--) {
  	read(x); read(y);
  	if (x != y) {
  	  int ax = cx(x), ay = cx(y);
  	  if (ax == ay) ans++; else fa[ay] = ax;
  	  ans++;
	}
  }
  printf("%d\n", ans);
}

int main() {
  int T; read(T);
  while (T--) work();
  return 0;
}