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

const int N = 105, M = 1e4 + 5;

int n, m, len[N][N], p[N][N], ans[N];
bool vis[N];

struct wd {
  int x, y, v;
} b[M];

void yhjssa() {
  read(n); read(m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      read(b[(i - 1) * m + j].v), b[(i - 1) * m + j].x = i,
	    b[(i - 1) * m + j].y = j, len[i][j] = b[(i - 1) * m + j].v,
		  p[i][j] = 0;
  std::sort(b + 1, b + n * m + 1, [&](wd x, wd y) {return x.v < y.v;});
  int tot = 0;
  for (int i = 1; i <= m; i++) p[b[i].x][b[i].y] = ++tot;
  for (int i = 1; i <= n; i++) {
  	int fk = 0;
  	for (int j = 1; j <= m; j++) vis[j] = 0;
  	for (int j = 1; j <= m; j++) if (p[i][j]) ans[p[i][j]] = j, vis[p[i][j]] = 1;
  	for (int j = 1, k = 1; j <= m; j++) if (!p[i][j]) {
  	  while (vis[k]) k++;
  	  ans[k++] = j;
	}
  	for (int j = 1; j <= m; j++) printf("%d ", len[i][ans[j]]);
  	puts("");
  }
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}