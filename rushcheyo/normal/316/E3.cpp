#include <bits/stdc++.h>
using namespace std;

const int N = 200005, P = 1000000000;
int n, m, f[N], fs[N], s[N * 4][2], tag[N * 4];

void pushup(int u, int l) {
  s[u][0] = (s[u << 1][0] +
    1ll * f[l - 1] * s[u << 1 | 1][0] + 1ll * f[l] * s[u << 1 | 1][1]) % P;
  s[u][1] = (s[u << 1][1] +
    1ll * f[l] * s[u << 1 | 1][0] + 1ll * f[l + 1] * s[u << 1 | 1][1]) % P;
}

void build(int u = 1, int l = 1, int r = n) {
  if (l == r) { s[u][0] = 0; scanf("%d", s[u] + 1); return; }
  int mid = l + r >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
  pushup(u, mid - l + 1);
}

void add(int u, int l, int v) {
  tag[u] = (tag[u] + v) % P;
  s[u][0] = (s[u][0] + 1ll * fs[l - 1] * v) % P;
  s[u][1] = (s[u][1] + 1ll * fs[l] * v) % P;
}

void pushdown(int u, int l, int r, int mid) {
  if (tag[u]) {
    add(u << 1, mid - l + 1, tag[u]);
    add(u << 1 | 1, r - mid, tag[u]);
    tag[u] = 0;
  }
}

void update(int ql, int qr, int v, int u = 1, int l = 1, int r = n) {
  if (l >= ql && r <= qr) { add(u, r - l + 1, v); return; }
  int mid = l + r >> 1;
  pushdown(u, l, r, mid);
  if (ql <= mid) update(ql, qr, v, u << 1, l, mid);
  if (qr > mid) update(ql, qr, v, u << 1 | 1, mid + 1, r);
  pushup(u, mid - l + 1);
}

void setv(int p, int v, int u = 1, int l = 1, int r = n) {
  if (l == r) { s[u][0] = 0, s[u][1] = v; return; }
  int mid = l + r >> 1;
  pushdown(u, l, r, mid);
  if (p <= mid) setv(p, v, u << 1, l, mid);
  else setv(p, v, u << 1 | 1, mid + 1, r);
  pushup(u, mid - l + 1);
}

int query(int ql, int qr, int u = 1, int l = 1, int r = n) {
  if (l >= ql && r <= qr)
    return (1ll * f[l - ql] * s[u][0] + 1ll * f[l - ql + 1] * s[u][1]) % P;
  int mid = l + r >> 1;
  pushdown(u, l, r, mid);
  int ans = 0;
  if (ql <= mid) ans = query(ql, qr, u << 1, l, mid);
  if (qr > mid) ans = (ans + query(ql, qr, u << 1 | 1, mid + 1, r)) % P;
  return ans;
}

int main() {
  scanf("%d%d", &n, &m);
  fs[1] = f[1] = 1;
  for (int i = 2; i <= n; i++) {
    f[i] = (f[i - 1] + f[i - 2]) % P;
    fs[i] = (fs[i - 1] + f[i]) % P;
  }
  build();
  while (m--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x, v;
      scanf("%d%d", &x, &v);
      setv(x, v);
    } else if (t == 2) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", query(l, r));
    } else {
      int l, r, d;
      scanf("%d%d%d", &l, &r, &d);
      update(l, r, d);
    }
  }
  return 0;
}