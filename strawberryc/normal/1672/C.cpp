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

int n, a[N];

int main() {
  int T; read(T);
  while (T--) {
  	read(n);
  	for (int i = 1; i <= n; i++) read(a[i]);
  	int pl = -1, pr = -1;
  	for (int i = 1; i < n; i++) if (a[i] == a[i + 1]) pr = i;
  	for (int i = n - 1; i >= 1; i--) if (a[i] == a[i + 1]) pl = i;
  	if (pl == -1 || pl == pr) {puts("0"); continue;}
  	printf("%d\n", pr == pl + 1 ? 1 : pr - pl - 1);
  }
  return 0;
}