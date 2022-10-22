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

const int N = 505;

int n, a[N][N];

int main() {
  int v;
  read(n);
  for (int i = 1; i <= n; i++) {
  	read(v);
  	a[i][i] = v;
  	int x = i, y = i, tv = v - 1;
  	while (tv--) {
  	  if (y > 1 && !a[x][y - 1]) y--;
  	  else x++;
  	  a[x][y] = v;
	}
  }
  for (int i = 1; i <= n; i++) {
  	for (int j = 1; j <= i; j++) printf("%d ", a[i][j]);
  	puts("");
  }
  return 0;
}