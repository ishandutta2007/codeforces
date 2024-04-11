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

const int N = 505, M = N * N * 2;

int n, a[N], q, res[M], val[M], tot, ans[N];
std::map<int, int> orz;

void yhjssa() {
  read(n); q = tot = 0;
  for (int i = 1; i <= n; i++) read(a[i]);
  orz.clear();
  for (int i = 1; i <= n; i++) orz[a[i]]++;
  for (int i = 1; i <= n; i++) if (orz[a[i]] & 1)
    return (void) puts("-1");
  for (int z = 1, cur = 0; z <= n; z += 2) {
  	int y = z + 1, l;
  	while (a[z] != a[y]) y++; l = y - z << 1;
  	for (int i = z + 1; i < y; i++) val[++q] = a[i],
  	  res[q] = cur + y + i - z * 2;
  	for (int i = z + 1; i < z + y - i; i++) std::swap(a[i], a[z + y - i]);
  	for (int i = y; i >= z + 2; i--) a[i] = a[i - 1];
  	ans[++tot] = l; cur += l;
  }
  printf("%d\n", q);
  for (int i = 1; i <= q; i++) printf("%d %d\n", res[i], val[i]);
  printf("%d\n", tot);
  for (int i = 1; i <= tot; i++) printf("%d ", ans[i]);
  puts("");
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}