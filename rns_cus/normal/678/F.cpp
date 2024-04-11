#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> PII;

#define INF (2e18)
#define M 300010
#define lft (id << 1)
#define rgt (id << 1 | 1)

int n;

vector <PII> v[M << 2], con[M << 2], val[M << 2];

void ins(int id, int l, int r, int st, int en, PII t) {
  if (st <= l && r <= en) {
    v[id].push_back(t); return;
  }
  int mid = (l + r) >> 1;
  if (st <= mid) ins(lft, l, mid, st, en, t);
  if (mid < en) ins(rgt, mid + 1, r, st, en, t);
}

PII operator - (PII a, PII b) {return PII(a.first - b.first, a.second - b.second);}
LL operator ^ (PII a, PII b) {return 1LL * a.first * b.second - 1LL * a.second * b.first;}

int sz[M << 2];

void build(int id, int l, int r) {
  if (v[id].size() > 1) {
    sort(v[id].begin(), v[id].end());
    v[id].resize(unique(v[id].begin(), v[id].end()) - v[id].begin());
    con[id].resize(v[id].size());
    sz[id] = 0;
    for (int i = 0; i < v[id].size(); i++) {
      while (sz[id] > 1 && ((v[id][i] - con[id][sz[id] - 1]) ^ (v[id][i] - con[id][sz[id] - 2])) <= 0) sz[id]--;
      con[id][sz[id]++] = v[id][i];
    }
    val[id].resize(sz[id] - 1);
    for (int i = 0; i < sz[id] - 1; i++) {
      val[id][i] = con[id][i + 1] - con[id][i];
      val[id][i].second = -val[id][i].second;
    }
  }
  else sz[id] = v[id].size();
  if (l == r) {
    return;
  }
  int mid = (l + r) >> 1;
  build(lft, l, mid);
  build(rgt, mid + 1, r);
}

inline void chkmax(LL &x, LL y) {if (x < y) x = y;}

LL rlt;

bool cmp(PII a, PII b) {return 1LL * b.first * a.second < 1LL * b.second * a.first;}

void calc(int id, int l, int r, int x, int q) {
  if (sz[id] == 1) {
    chkmax(rlt, 1LL * v[id][0].first * q + v[id][0].second);
  }
  else if (sz[id] > 1) {
    int pos = lower_bound(val[id].begin(), val[id].end(), PII(1, q), cmp) - val[id].begin();
    for (int i = 0; i <= 1; i++) {
      int j = pos + i;
      if (j >= 0 && j < sz[id]) {
        chkmax(rlt, 1LL * con[id][j].first * q + con[id][j].second);
      }
    }
  }
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (x <= mid) calc(lft, l, mid, x, q);
  else calc(rgt, mid + 1, r, x, q);
  return;
}

PII p[M];

vector <PII> qry;

int type[M], en[M];

int main() {
  int x, y;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) en[i] = n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &type[i]);
    if (type[i] == 3) {
      scanf("%d", &x); qry.push_back(PII(i, x));
    }
    else if (type[i] == 1) {
      scanf("%d %d", &x, &y);
      p[i] = PII(x, y);
    }
    else {
      scanf("%d", &x);
      en[x] = i;
    }
  }
  for (int i = 1; i <= n; i++) if (type[i] == 1) {
    ins(1, 1, n, i, en[i], p[i]);
  }

  build(1, 1, n);
  for (int i = 0; i < qry.size(); i++) {
    rlt = -INF;
    calc(1, 1, n, qry[i].first, qry[i].second);
    if (rlt == -INF) {
      puts("EMPTY SET");
    }
    else {
      printf("%I64d\n", rlt);
    }
  }
}