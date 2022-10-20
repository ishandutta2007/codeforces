#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <limits>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

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

const int N = 500005;

vector<int> pos[N];
int L[N / 2], R[N / 2], cnt = 0;
vector<int> rbound[N];
int tot_valued = 0;

struct node {
  int mn, tag;
} t[N * 4];

void up(int x) { t[x].mn = min(t[x << 1].mn, t[x << 1 | 1].mn) + t[x].tag; }
void init(int x, int l, int r) {
  t[x].tag = 0;
  if (l == r) {
    t[x].mn = l + tot_valued;
    return;
  }
  int mid = (l + r) >> 1;
  init(x << 1, l, mid);
  init(x << 1 | 1, mid + 1, r);
  up(x);
}

void modify(int x, int l, int r, int ql, int qr, int v) {
  if (ql <= l && r <= qr) {
    t[x].mn += v; t[x].tag += v;
    return;
  }
  int mid = (l + r) >> 1;
  if (ql <= mid) modify(x << 1, l, mid, ql, qr, v);
  if (qr > mid) modify(x << 1 | 1, mid + 1, r, ql, qr, v);
  up(x);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) {
    int n;
    read(n);
    for (int i = 0; i <= n; ++i)
      pos[i].clear();
    tot_valued = 0;
    for (int i = 1; i <= n; ++i) {
      int x;
      read(x);
      pos[x].push_back(i);
    }
    cnt = 0;
    int len = pos[0].size() - pos[0].size() / 2;
    for (size_t i = 0, li = pos[0].size() / 2; i < li; ++i) {
      L[cnt] = pos[0][i];
      R[cnt++] = pos[0][i + len];
    }
    for (int i = 0; i <= cnt; ++i)
      rbound[i].clear();
    int res = pos[0].size() / 2;
    if (!res) {
      puts("0");
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      if (pos[i].empty()) continue;
      ++tot_valued;
      int lcnt = 0, rcnt = 0;
      for (int p : pos[i]) {
        if (L[cnt - 1] <= p && p <= R[0]) {
          lcnt = cnt; rcnt = cnt;
          break;
        }
        else if (p <= L[cnt - 1])
          lcnt = max<int>(lcnt, upper_bound(L, L + cnt, p) - L);
        else
          rcnt = max<int>(rcnt, R + cnt - lower_bound(R, R + cnt, p));
      }
      rbound[lcnt].push_back(rcnt);
    }
    init(1, 0, cnt);
    for (int l = 0; l <= cnt; ++l) {
      for (int r : rbound[l])
        modify(1, 0, cnt, r, cnt, -1);
      res = min(res, l + t[1].mn);
    }
    printf("%d\n", res);
  }
  return 0;
}