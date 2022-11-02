#include <bits/stdc++.h>
using namespace std;
#define M 2500

void read(int &x) {
  x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c <= '9' && c >= '0') x = 10 * x + c - '0', c = getchar();
}

bitset <M> row[M], col[M];
pair <int, int> p[M * M / 2];
int n, a[M][M];

void ins(int v) {
  int x = v / n, y = v % n;
  row[x][y] = 1, col[y][x] = 1;
  row[y][x] = 1, col[x][y] = 1;
}

bool check(int v) {
  int x = v / n, y = v % n;
  return ((row[x] | col[y]).count() == n);
}

int main() {
  //freopen("in.txt", "r", stdin);
  read(n);
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) read(a[i][j]);
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    if (a[i][j] != a[j][i]) return puts("NOT MAGIC"), 0;
  }
  for (int i = 0; i < n; i++) if (a[i][i]) return puts("NOT MAGIC"), 0;
  for (int i = 0; i < n; i++) row[i][i] = col[i][i] = 1;
  int N = 0;
  for (int i = 1; i < n; i++) for (int j = 0; j < i; j++)
    p[N++] = make_pair(a[i][j], i * n + j);

  sort(p, p + N, greater <pair <int, int> >());
  ins(p[0].second);
  int i = 1, j = 0;

  for ( ; ; ) {
    while (i < N && p[i].first == p[i - 1].first) ins(p[i].second), i++;
    for ( ; j < i; j++) if (!check(p[j].second)) {
      return puts("NOT MAGIC"), 0;
    }
    if (j >= N) break;
    ins(p[i].second); i++;
  }
  return puts("MAGIC"), 0;
}