#undef NDEBUG

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <typeinfo>
#include <limits>

using namespace std;

struct Query {
  int x1, x2, y1, y2, id;
};

struct Point {
  int x, y;
};

const int kMaxN = 150000;
const int kInf = 1e9;

int t[kMaxN * 4];

void Upd(int pos, int val, int idx, int l, int r) {
  if (l == r) {
    assert(pos == l);
    t[idx] = val;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    Upd(pos, val, 2 * idx + 1, l, mid);
  else
    Upd(pos, val, 2 * idx + 2, mid + 1, r);
  t[idx] = max(t[2 * idx + 1], t[2 * idx + 2]);
}

int MaxV(int l, int r, int idx, int tl, int tr) {
  if (l == tl && r == tr)
    return t[idx];
  int mid = (tl + tr) >> 1;
  int ans = -kInf;
  if (l <= mid)
    ans = max(ans, MaxV(l, min(r, mid), 2 * idx + 1, tl, mid));
  if (r >= mid + 1)
    ans = max(ans, MaxV(max(l, mid + 1), r, 2 * idx + 2, mid + 1, tr));
  return ans;
}

bool CmpX(const Point& a, const Point& b) {
  return a.x < b.x;
}

bool CmpQX(const Query& a, const Query& b) {
  return a.x1 < b.x1;
}

vector<int> Solve(vector<Query> q, vector<Point> a) {
  vector<int> ans(q.size());
  sort(a.begin(), a.end(), CmpX);
  sort(q.begin(), q.end(), CmpQX);
  for (int i = 0; i < kMaxN; ++i)
    Upd(i, kInf, 0, 0, kMaxN - 1);
  int ita = a.size() - 1, itq = q.size() - 1;
  for (int x = kMaxN - 1; x >= 0; --x) {
    while (ita >= 0 && a[ita].x == x) {
      Upd(a[ita].y, a[ita].x, 0, 0, kMaxN - 1);
      ita--;
    }
    while (itq >= 0 && q[itq].x1 == x) {
      int maxx = MaxV(q[itq].y1, q[itq].y2, 0, 0, kMaxN - 1);
      ans[q[itq].id] = (maxx <= q[itq].x2);
      itq--;
    }
  }
  return ans;
}

int main() {
#ifdef ssu1
  assert(freopen("input.txt", "rt", stdin));
#endif
  int k, q, n, m;
  cin >> n >> m >> k >> q;
  vector<Point> a(k);
  for (int i = 0; i < k; ++i) {
    scanf("%d%d", &a[i].x, &a[i].y);
  }
  vector<Query> qs(q);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d%d%d", &qs[i].x1, &qs[i].y1, &qs[i].x2, &qs[i].y2);
    qs[i].id = i;
  }

  vector<int> answer1 = Solve(qs, a);

  for (int i = 0; i < k; ++i)
    swap(a[i].x, a[i].y);
  for (int i = 0; i < q; ++i) {
    swap(qs[i].x1, qs[i].y1);
    swap(qs[i].x2, qs[i].y2);
  }
  vector<int> answer2 = Solve(qs, a);

  for (int i = 0; i < q; ++i) {
    puts((answer1[i] || answer2[i]) ? "YES" : "NO");
  }

#ifdef ssu1
  cerr << "\nTime = " << ((double)clock()) / CLOCKS_PER_SEC << endl;
#endif    
  return 0;
}