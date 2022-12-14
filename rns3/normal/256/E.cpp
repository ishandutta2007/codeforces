#include <bits/stdc++.h>
using namespace std;
#define M 111111
#define lft (id << 1)
#define rgt (id << 1 | 1)

const int mod = 777777777;
int n, Q;

int T[M << 2][4][4], f[4][4];

void setv(int id, int v) {
  for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) T[id][i][j] = 0;
  if (!v) {
    for (int i = 1; i <= 3; i++) T[id][i][i] = 1;
  }
  else T[id][v][v] = 1;
}

void up(int id) {
  for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) T[id][i][j] = 0;
  for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) if (f[i][j]) {
    for (int I = 1; I <= 3; I++) for (int J = 1; J <= 3; J++)
      T[id][I][J] = (T[id][I][J] + 1LL * T[lft][I][i] * T[rgt][j][J]) % mod;
  }
}

void build(int id, int l, int r) {
  if (l == r) {
    setv(id, 0);
    return;
  }
  int mid = (l + r) >> 1;
  build(lft, l, mid);
  build(rgt, mid + 1, r);
  up(id);
}

void update(int id, int l, int r, int x, int v) {
  if (l == r) {
    setv(id, v); return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid) update(lft, l, mid, x, v);
  else update(rgt, mid + 1, r, x, v);
  up(id);
}

int main() {
  //freopen("E.in", "r", stdin);
  scanf("%d %d", &n, &Q);
  for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) scanf("%d", &f[i][j]);
  build(1, 1, n);
  while (Q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    update(1, 1, n, x, y);
    int ans = 0;
    for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) {
      ans += T[1][i][j]; if (ans >= mod) ans -= mod;
    }
    printf("%d\n", ans);
  }
}