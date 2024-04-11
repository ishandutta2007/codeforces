#include <bits/stdc++.h>
using namespace std;
#define M 100010
#define ep 1e-9

struct dat {
  int v, m, id;
  dat (int v = 0, int m = 0, int id = 0) : v(v), m(m), id(id) {}
  bool operator < (const dat &a) const {
    if (m != a.m) return m < a.m;
    if (v != a.v) return v < a.v;
    return id < a.id;
  }
} p[M];

int n, K, h;
int pos[M], H[M], POS[M];

bool check(double x) {
  int cur = K;
  for (int i = n - 1; i >= 0; i--) {
    if (x * p[i].v - cur * h > -ep) POS[cur] = p[i].id, cur--;
    if (!cur) break;
  }
  if (!cur) for (int i = 1; i <= K; i++) pos[i] = POS[i];
  return !cur;
}

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d %d", &n, &K, &h);
  for (int i = 0; i < n; i++) scanf("%d", &p[i].m);
  for (int i = 0; i < n; i++) scanf("%d", &p[i].v), p[i].id = i + 1;
  sort(p, p + n);
  double l = 0, r = 2e9;
  for (int step = 0; step < 100; step++) {
    double mid = (l + r) / 2;
    if (check(mid)) r = mid;
    else l = mid;
  }
  for (int i = 1; i <= K; i++) printf("%d ", pos[i]);
}