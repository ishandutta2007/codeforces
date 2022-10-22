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

int n, a[N], b[N], ans, X[N], Y[N], tot;
bool vis[N];
std::vector<int> cir[N];

void record(int x, int y) {
  X[++ans] = a[x]; Y[ans] = a[y];
  std::swap(a[x], a[y]);
}

void eliminate(int A, int B) {
  int n = cir[A].size() - 1, m = cir[B].size() - 1;
  record(cir[A][n], cir[B][m]);
  for (int i = n; i >= 1; i--) record(cir[A][i], cir[A][i - 1]);
  for (int i = m; i >= 1; i--) record(cir[B][i], cir[B][i - 1]);
  record(cir[A][0], cir[B][0]);
}

int main() {
  int x;
  read(n);
  for (int i = 1; i <= n; i++) read(x), a[x] = i;
  for (int i = 1; i <= n; i++) if (!vis[i]) {
  	tot++;
    for (int j = i; !vis[j]; j = a[j])
      vis[j] = 1, cir[tot].push_back(j);
  }
  for (int i = 1; i + 1 <= tot; i += 2) eliminate(i, i + 1);
  if ((tot & 1) && tot > 1) {
  	x = cir[1][0]; cir[1].clear(); cir[1].push_back(x);
  	eliminate(1, tot);
  }
  if (tot == 1) {
  	for (int i = 1; i <= n; i++)
  	  b[i <= 2 ? i : n - i + 3] = cir[1][i - 1];
  	for (int i = 1; i < n; i++) record(b[i], b[i + 1]);
  	record(b[1], b[2]); record(b[2], b[n]);
  }
  std::cout << ans << std::endl;
  for (int i = 1; i <= ans; i++) printf("%d %d\n", X[i], Y[i]);
  return 0;
}