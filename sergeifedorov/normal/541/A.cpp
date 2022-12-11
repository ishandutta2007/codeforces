#undef NDEBUG
#ifdef ssu1
#endif

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

struct Seg {
  int l, r;
};

struct TV {
  int l, r, c, id;
};

const int kMaxN = 500000;

int t[kMaxN * 4], tlen[kMaxN * 4], x[kMaxN], y[kMaxN];
long long ans[kMaxN];

void Build(int v, int l, int r) {
  if (l == r) {
    t[v] = y[l];
    tlen[v] = y[l] - x[l];
    return;
  }
  int mid = (l + r) >> 1;
  Build(2 * v + 1, l, mid);
  Build(2 * v + 2, mid + 1, r);
  t[v] = max(t[2 * v + 1], t[2 * v + 2]);
  tlen[v] = max(tlen[2 * v + 1], tlen[2 * v + 2]);
}

int globalL, globalR;

int GetMaxT(int l, int r, int v, int tl, int tr) {
  if (l == tl && r == tr)
    return t[v];

  int mid = (tl + tr) >> 1;
  int lv = 2 * v + 1, rv = 2 * v + 2;

  if (r <= mid) {
    return GetMaxT(l, r, lv, tl, mid);
  } else {
    if (l >= mid + 1)
      return GetMaxT(l, r, rv, mid + 1, tr);
    else {
      return max(GetMaxT(l, mid, lv, tl, mid),
                 GetMaxT(mid + 1, r, rv, mid + 1, tr));
    }
  }
}

int GetMax(int l, int r, int v, int tl, int tr) {
  if (tl == tr) {
    return min(y[tl], globalR) - x[tl];
  }

  int mid = (tl + tr) >> 1;
  int lv = 2 * v + 1, rv = 2 * v + 2;

  if (tl == l && tr == r) {
    int mxr = t[v];
    if (mxr <= globalR)
      return tlen[v];
    if (t[lv] > globalR)
      return GetMax(l, mid, lv, tl, mid);
    return max(tlen[lv], GetMax(mid + 1, r, rv, mid + 1, tr));
  }

  if (r <= mid) {
    return GetMax(l, r, lv, tl, mid);
  } else {
    if (l >= mid + 1)
      return GetMax(l, r, rv, mid + 1, tr);
    else {
      return max(GetMax(l, mid, lv, tl, mid),
                 GetMax(mid + 1, r, rv, mid + 1, tr));
    }
  }
}

void FillAns(vector<Seg> a, vector<TV> b) {
  map<int, int> beg;
  for (int i = 0; i < a.size(); ++i) {
    if (beg.count(a[i].l) == 0)
      beg[a[i].l] = a[i].r;
    beg[a[i].l] = max(beg[a[i].l], a[i].r);
  }
  {
    int i = 0;
    for (auto item : beg) {
      x[i] = item.first;
      y[i] = item.second;
      ++i;
    }
  }
  Build(0, 0, beg.size() - 1);
  for (auto& tv : b) {
    int lf = lower_bound(x, x + beg.size(), tv.l) - x;
    int rg = upper_bound(x, x + beg.size(), tv.r) - x;
    rg--;
    globalL = tv.l;
    globalR = tv.r;
    if (0 <= lf && lf <= rg) {
      int mx = GetMax(lf, rg, 0, 0, beg.size() - 1);
      assert(mx <= tv.r - tv.l);
      ans[tv.id] = max(ans[tv.id], mx * 1LL * tv.c);
    }
    if (lf > 0) {
      int maxr = GetMaxT(0, lf - 1, 0, 0, beg.size() - 1);
      if (maxr >= tv.r) {
        ans[tv.id] = max(ans[tv.id], (tv.r - tv.l) * 1LL * tv.c);
      }
    }
  }
}

void Reverse(vector<Seg>& a, vector<TV>& b) {
  for (int i = 0; i < a.size(); ++i) {
    swap(a[i].l, a[i].r);
    a[i].r *= -1;
    a[i].l *= -1;
  }
  for (int i = 0; i < b.size(); ++i) {
    swap(b[i].l, b[i].r);
    b[i].r *= -1;
    b[i].l *= -1;
  }
}

int main() {
#ifdef ssu1
  assert(freopen("input.txt", "rt", stdin));
#endif
  int n, m;
  scanf("%d%d", &n, &m);
  vector<Seg> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", &a[i].l, &a[i].r);
  vector<TV> b(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &b[i].l, &b[i].r, &b[i].c);
    b[i].id = i;
  }

  FillAns(a, b);
  Reverse(a, b);
  FillAns(a, b);
  Reverse(a, b);

  int maxj = max_element(ans, ans + m) - ans;
  if (ans[maxj] > 0) {
    cout << ans[maxj] << endl;
    for (int i = 0; i < n; ++i) {
      int ll = max(b[maxj].l, a[i].l);
      int rr = min(b[maxj].r, a[i].r);
      long long f = (rr - ll) * 1LL * b[maxj].c;
      if (f == ans[maxj]) {
        cout << i + 1 << " " << maxj + 1 << endl;
        return 0;
      }
    }
    throw;
  } else {
    puts("0");
  }

#ifdef ssu1
  cerr << "\nTime = " << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}