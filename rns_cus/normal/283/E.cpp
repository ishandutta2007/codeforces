#include <bits/stdc++.h>

using namespace std;

#define N 100100
#define ls id << 1
#define rs id << 1 | 1

int n, a[N];
int tmp[N], m, cnt;
int b[N], c[N], f[N];
vector <int> v[N], u[N];

int sum[N << 2], flip[N << 2];

void up(int id) {
  sum[id] = sum[id << 1] + sum[id << 1 | 1];
}

void down(int id) {
  if(flip[id] == -1) {
    sum[id <<1] = -sum[ls]; flip[ls] *= -1;
    sum[rs] = - sum[rs]; flip[rs] *= -1;
    flip[id] = 1;
  }
}

void build(int l, int r, int id) {
  flip[id] = 1;
  if(l == r) {
    sum[id] = 1;
    return;
  }
  int md = (l + r) >> 1;
  build(l, md, id<<1);
  build(md + 1, r, id << 1 | 1);
  up(id);
}

void modify(int l, int r, int id, int L, int R) {
  if(L <= l && r <= R) {
    sum[id] = - sum[id];
    flip[id] *= -1;
    return ;
  }
  down(id);
  int md = (l + r) >> 1;
  int rt = 0;
  if(L <= md) modify(l, md, ls, L, R);
  if(R > md) modify(md + 1, r, rs, L, R);
  up(id);
}

int query(int l, int r, int id, int L, int R) {
  if(L <= l && r <= R) {
    return sum[id];
  }
  down(id);
  int md = (l + r) >> 1;
  int rt = 0;
  if(L <= md) rt = query(l, md, ls, L, R);
  if(R > md) rt += query(md + 1, r, rs, L, R);
  return rt;
}

void run() {
  build(1, n, 1);
  for(int i = 1; i <= n; i ++) {
    if(i > 1) {
      f[i] = (i - 1 + query(1, n, 1, 1, i - 1)) / 2;
    }
    if((int)v[i].size() & 1) modify(1, n, 1, i, n);
    for(int j = 0; j < (int)u[i].size(); j ++) {
      int k = u[i][j];
      modify(1, n, 1, b[k], n);
    }
  }
  build(1, n, 1);
  for(int i = n; i ; i --) {
    if(i < n) {
      f[i] += (n - i - query(1, n, 1, i + 1, n)) / 2;
    }
    if((int)u[i].size() & 1) modify(1, n, 1, 1, i);
    for(int j = 0; j < (int)v[i].size(); j ++) {
      int k = v[i][j];
      modify(1, n, 1, 1, c[k]);
    }
  }
  long long rt = 1LL * n * (n - 1) * (n - 2) / 6;
  for(int i = 1; i <= n; i ++) {
    if(f[i] > 1) rt -= 1LL * f[i] * (f[i] - 1) / 2;
  }
  printf("%I64d\n", rt);
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i ++) {
    scanf("%d", a + i);
    tmp[i - 1] = a[i];
  }
  sort(tmp, tmp + n);
  for(int i = 1 ;i <= n ;i ++) a[i] = lower_bound(tmp, tmp + n, a[i]) - tmp + 1;
  for(int i = 1; i <= m ;i ++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x = lower_bound(tmp, tmp + n, x) - tmp + 1;
    y = upper_bound(tmp, tmp + n, y) - tmp;
    if(x >= y) continue;
    b[++ cnt] = x; c[cnt] = y;
    v[x].push_back(cnt);
    u[y].push_back(cnt);
  }
  m = cnt;
  run();
  return 0;
}