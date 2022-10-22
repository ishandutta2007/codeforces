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

const int N = 205;

int n, out[N], in[N], fa[N];

int cx(int x) {
  if (fa[x] != x) fa[x] = cx(fa[x]);
  return fa[x];
}

void zm(int x, int y) {
  if ((x = cx(x)) != (y = cx(y))) fa[y] = x;
}

int main() {
  int T; read(T);
  while (T--) {
  	read(n);
  	for (int i = 1; i <= n; i++) read(out[i]), in[out[i]] = fa[i] = i;
  	for (int i = 1; i <= n; i++) zm(i, out[i]);
  	while (114 + 514 < 1919 + 810) {
  	  int cnt = 0;
  	  for (int i = 1; i <= n; i++) cnt += fa[i] == i;
  	  if (cnt == 1) break;
  	  int cur;
  	  for (int i = 1; i < n; i++) if (cx(i) != cx(i + 1))
  	    {cur = i; break;}
  	  zm(cur, cur + 1);
  	  int x = in[cur], y = in[cur + 1];
  	  out[x] = cur + 1; out[y] = cur;
  	  in[cur + 1] = x; in[cur] = y;
	}
	for (int i = 1, x = 1; i <= n; i++, x = in[x]) printf("%d ", x);
	puts("");
  }
  return 0;
}