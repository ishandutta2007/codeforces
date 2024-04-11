#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using ll = long long;

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 500005;
const int V = 1000001;

struct node {
  int mn, tag;
  int cnt;
} t[(V + 5) * 4];

void up(int x) {
  const node &lc = t[x << 1], &rc = t[x << 1 | 1];
  if (lc.mn == rc.mn) t[x].mn = lc.mn, t[x].cnt = lc.cnt + rc.cnt;
  else if (lc.mn < rc.mn) t[x].mn = lc.mn, t[x].cnt = lc.cnt;
  else t[x].mn = rc.mn, t[x].cnt = rc.cnt;
  t[x].mn += t[x].tag;
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
void modify_cnt(int x, int l, int r, int p, int v) {
  if (l == r) {
    t[x].cnt += v;
    return;
  }
  int mid = (l + r) >> 1;
  p <= mid ? modify_cnt(x << 1, l, mid, p, v) : modify_cnt(x << 1 | 1, mid + 1, r, p, v);
  up(x);
}

int a[N];
int n, qc;

void update(int p, int coef) {
  if (a[p] > a[p + 1])
    modify(1, 1, V, a[p + 1] + 1, a[p], coef);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n, qc);
  for (int i = 1; i <= n; ++i)
    read(a[i]);
  a[0] = V; a[n + 1] = 0;
  for (int i = 0; i <= n; ++i)
    update(i, 1);
  for (int i = 0; i <= n + 1; ++i)
    modify_cnt(1, 1, V, a[i], 1);
  while (qc--) {
    int pos;
    read(pos);
    modify_cnt(1, 1, V, a[pos], -1);
    update(pos - 1, -1); update(pos, -1);
    read(a[pos]);
    modify_cnt(1, 1, V, a[pos], 1);
    update(pos - 1, 1); update(pos, 1);
    printf("%d\n", t[1].mn == 1 ? t[1].cnt - 2 : 1);
  }
  return 0;
}