#include <bits/stdc++.h>
using namespace std;
#define M 400010
#define lft (id << 1)
#define rgt (id << 1 | 1)
#define all(v) v.begin(), v.end()

struct data {
  int rnk, age, id;
  data (int rnk = 0, int age = 0, int id = 0) : rnk(rnk), age(age), id(id) {}
  bool operator < (const data & a) const {
    if (age != a.age) return age < a.age;
    return rnk < a.rnk;
  }
} p[M];

vector <int> v[M], px[M], bit[M];

void buildT(int id, int l, int r) {
  for (int i = l; i <= r; i++) v[id].push_back(p[i].rnk);
  sort(all(v[id]));
  if (l == r) return;
  int mid = (l + r) >> 1;
  buildT(lft, l, mid);
  buildT(rgt, mid + 1, r);
}

int calc(int id, int l, int r, int st, int en, int val) {
  if (st <= l && r <= en) {
    return upper_bound(all(v[id]), val) - v[id].begin();
  }
  int mid = (l + r) >> 1;
  int rlt = 0;
  if (st <= mid) rlt += calc(lft, l, mid, st, en, val);
  if (mid < en) rlt += calc(rgt, mid + 1, r, st, en, val);
  return rlt;
}

int a[M], r[M], b[M], arr[M];

void upd(vector <int> &u, int x, int val) {
  while (x) {
    u[x] = max(u[x], val); x -= (x & -x);
  }
}

void build(int id, int l, int r) {
  for (int i = l; i <= r; i++) {
    px[id].push_back(p[i].rnk);
  }
  sort(all(px[id]));
  bit[id].resize(px[id].size() + 1);
  px[id].resize(unique(all(px[id])) - px[id].begin());
  for (int i = l; i <= r; i++) {
    int j = lower_bound(all(px[id]), p[i].rnk) - px[id].begin() + 1;
    upd(bit[id], j, b[i]);
  }
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(lft, l, mid);
  build(rgt, mid + 1, r);
}

int calc(vector <int> &u, int x) {
  int rlt = 0;
  while (x < u.size()) {
    rlt = max(rlt, u[x]); x += (x & -x);
  }
  return rlt;
}

int query(int id, int l, int r, int st, int en, int val) {
  if (st <= l && r <= en) {
    int pos = lower_bound(all(px[id]), val) - px[id].begin();
    if (pos == px[id].size()) return -1;
    return calc(bit[id], pos + 1);
  }
  int rlt = -1;
  int mid = (l + r) >> 1;
  if (st <= mid) rlt = max(rlt, query(lft, l, mid, st, en, val));
  if (mid < en) rlt = max(rlt, query(rgt, mid + 1, r, st, en, val));
  return rlt;
}

int n, d;

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d", &n, &d);
  for (int i = 1; i <= n; i++) scanf("%d", r + i);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) p[i] = data(r[i], a[i], i);
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; i++) arr[i] = p[i].age;

  buildT(1, 1, n);
  for (int i = 1; i <= n; i++) {
    int st = lower_bound(arr + 1, arr + n + 1, p[i].age - d) - arr;
    int en = upper_bound(arr + 1, arr + n + 1, p[i].age + d) - arr - 1;
    b[i] = calc(1, 1, n, st, en, p[i].rnk);
  }
  build(1, 1, n);
  int Q, x, y;
  for (scanf("%d", &Q); Q--; ) {
    scanf("%d %d", &x, &y);
    if (a[x] > a[y]) swap(x, y);
    int L = a[y] - d, R = a[x] + d;
    if (L > R) puts("-1");
    else {
      L = lower_bound(arr + 1, arr + n + 1, L) - arr;
      R = upper_bound(arr + 1, arr + n + 1, R) - arr - 1;
      int val = max(r[x], r[y]);
      printf("%d\n", query(1, 1, n, L, R, val));
    }
  }
}