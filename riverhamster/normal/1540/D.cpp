#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <unistd.h>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define all(cont) begin(cont), end(cont)

using ll = long long;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int B = 1024;
const int N = 100000;

struct pt {
  int x, y;
  pt() = default;
  pt(int _x, int _y) : x(_x), y(_y) {}
};

int a[N];
vector<pt> t[N / B + 2][B * 2 + 2];

vector<pt> composite(const vector<pt> &l, const vector<pt> &r, vector<pt> &res) {
  res.clear();
  auto itl = begin(l), itr = begin(r), tl = end(l), tr = end(r);
  while (itl != tl && itr != tr) {
    if (itl->y == itr->x)
      res.emplace_back(itl->x, itr->y), ++itl, ++itr;
    else if (itl->y < itr->x) {
      if (itr != begin(r)) res.emplace_back(itl->x, prev(itr)->y + itl->y - prev(itr)->x);
      ++itl;
    }
    else {
      if (itl != begin(l)) {
        int pos = itr->x - prev(itl)->y + prev(itl)->x;
        if (pos < itl->x)
          res.emplace_back(itr->x - prev(itl)->y + prev(itl)->x, itr->y);
      }
      ++itr;
    }
  }
  for (; itl != tl; ++itl)
    res.emplace_back(itl->x, r.back().y + itl->y - r.back().x);
  for (; itr != tr; ++itr)
    res.emplace_back(l.back().x + itr->x - l.back().y, itr->y);
  return res;
}
int eval(const vector<pt> &a, int x) {
  auto it = prev(partition_point(all(a), [&](const pt &a) { return a.x <= x; }));
  return it->y + (x - it->x);
}

void build(vector<pt> *t, int x, int l, int r) {
  if (l == r) {
    if (a[l] == 0) t[x] = {pt(0, 1)};
    else t[x] = {pt(0, 0), pt(a[l], a[l] + 1)};
    return;
  }
  int mid = (l + r) >> 1;
  build(t, x << 1, l, mid);
  build(t, x << 1 | 1, mid + 1, r);
  t[x].reserve(t[x << 1].size() + t[x << 1 | 1].size());
  composite(t[x << 1], t[x << 1 | 1], t[x]);
}
void update(vector<pt> *t, int x, int l, int r, int pos) {
  if (l == r) {
    if (a[l] == 0) t[x] = {pt(0, 1)};
    else t[x] = {pt(0, 0), pt(a[l], a[l] + 1)};
    return;
  }
  int mid = (l + r) >> 1;
  pos <= mid ? update(t, x << 1, l, mid, pos) : update(t, x << 1 | 1, mid + 1, r, pos);
  composite(t[x << 1], t[x << 1 | 1], t[x]);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, qc;
  read(n);
  for (int i = 0; i < n; ++i)
    read(a[i]), a[i] = i - a[i];
  int bc = (n - 1) / B + 1;
  for (int b = 0; b < bc; ++b) {
    int bl = b * B, br = min(n, (b + 1) * B);
    build(t[b], 1, bl, br - 1);
  }
  read(qc);
  while (qc--) {
    int opt, p;
    read(opt, p); --p;
    int b = p / B, bl = b * B, br = min(n, (b + 1) * B);
    if (opt == 1) {
      read(a[p]);
      a[p] = p - a[p];
      update(t[p / B], 1, bl, br - 1, p);
    }
    else {
      int res = a[p];
      for (int i = p + 1; i < br; ++i)
        res += a[i] <= res;
      for (int i = b + 1; i < bc; ++i)
        res = eval(t[i][1], res);
      printf("%d\n", res + 1);
    }
  }
  return 0;
}