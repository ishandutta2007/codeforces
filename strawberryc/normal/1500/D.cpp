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

const int N = 1505, M = N * N, E = 13;

int n, q, a[N][N], ToT = 20050131, vis[M], zc[N], zv[N],
ans[N], cz[N], vz[N];

struct elem {
  int tot, col[E], val[E];
  
  friend inline elem operator + (elem a, elem b) {
  	ToT++;
  	int ntot = 0; elem res;
  	for (int i = 1, j = 1; i <= a.tot || j <= b.tot;)
  	  if (i <= a.tot && (j > b.tot || a.val[i] < b.val[j]))
  	    cz[++ntot] = a.col[i], vz[ntot] = a.val[i], i++;
  	  else cz[++ntot] = b.col[j], vz[ntot] = b.val[j], j++;
  	res.tot = 0;
  	for (int i = 1; i <= ntot; i++)
  	  if (vis[cz[i]] != ToT && res.tot < q + 1)
		res.col[++res.tot] = cz[i],
		  res.val[res.tot] = vz[i], vis[cz[i]] = ToT;
  	return res;
  }
} b[N][N];

int main() {
  read(n); read(q);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      read(a[i][j]);
  for (int i = 1; i <= n; i++) {
  	int tot = 0;
    for (int j = n; j >= 1; j--) {
      int ot = tot + 1;
      for (int k = 1; k <= tot; k++)
        if (zc[k] == a[i][j]) {ot = k; break;}
      if (ot > tot) tot++;
      for (int k = ot; k > 1; k--)
        zc[k] = zc[k - 1], zv[k] = zv[k - 1];
      zc[1] = a[i][j]; zv[1] = j;
      if (tot > q + 1) tot--;
      elem tmp; tmp.tot = tot;
      for (int k = 1; k <= tot; k++)
        tmp.col[k] = zc[k], tmp.val[k] = (i + j >> 1) + zv[k] - j;
      b[i][j] = b[i][j] + tmp;
	}
  }
  for (int i = 1; i <= n; i++) {
  	int tot = 0;
    for (int j = n; j >= 1; j--) {
      int ot = tot + 1;
      for (int k = 1; k <= tot; k++)
        if (zc[k] == a[j][i]) {ot = k; break;}
      if (ot > tot) tot++;
      for (int k = ot; k > 1; k--)
        zc[k] = zc[k - 1], zv[k] = zv[k - 1];
      zc[1] = a[j][i]; zv[1] = j;
      if (tot > q + 1) tot--;
      elem tmp; tmp.tot = tot;
      for (int k = 1; k <= tot; k++)
        tmp.col[k] = zc[k], tmp.val[k] = (i + j >> 1) + zv[k] - j;
      b[j][i] = b[j][i] + tmp;
	}
  }
  for (int i = n - 1; i >= 1; i--)
    for (int j = n - 1; j >= 1; j--)
      b[i][j] = b[i][j] + b[i + 1][j + 1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int tm = n - std::max(i, j) + 1;
      if (b[i][j].tot == q + 1)
      	tm = std::min(tm, b[i][j].val[q + 1] - (i + j >> 1));
      ans[tm]++;
    }
  for (int i = n; i >= 1; i--) ans[i] += ans[i + 1];
  for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
  return 0;
}