#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define LOG(f...) fprintf(stderr, f)
// #define DBG(f...) printf("%3d: ", __LINE__), printf(f)
#define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while (isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int MN = -5e8;

int power(int x, int y, int M) {
  int p = 1;
  for (; y; y >>= 1, x = (ll)x * x % M)
    if (y & 1) p = (ll)p * x % M;
  return p;
}

int n, m, T, w;

struct node {
  int xs, real_xs;
  int e:31, todd:1;
} t[1 << 24];
int a[10000005];

void up(int x) {
  const auto &lc = t[x << 1], &rc = t[x << 1 | 1];
  if (t[x].todd) {
    if (lc.xs == -1 || rc.xs == -1) t[x].xs = lc.xs & rc.xs, t[x].e = lc.e + rc.e - 1;
    else if (lc.xs == rc.xs) t[x].xs = lc.xs, t[x].e = lc.e + rc.e;
    else t[x].e = MN;
  }
  else {
    t[x].e = lc.e + rc.e;
    t[x].xs = (lc.xs == -1 || rc.xs == -1) ? -1 : lc.xs ^ rc.xs;
  }
  t[x].e = max(t[x].e, MN);
  DBG("t[%d].e = %d xs = %d odd %d\n", x, t[x].e, t[x].xs, t[x].todd);
}

void build(int x, int len, int T) {
  DBG("build %d T %d\n", x, T);
  t[x].todd = T & 1;
  if (!T) {
    t[x].real_xs = len & 1 ? -1 : 0;
    t[x].xs = -1;
    t[x].e = len;
    return;
  }
  build(x << 1, len >> 1, T >> 1);
  build(x << 1 | 1, len >> 1, T >> 1);
  up(x);
}

void modify(int x, int T, int pos, int v, int nv) {
  if (!T) {
    t[x].real_xs ^= v ^ nv;
    t[x].e -= (v == -1); t[x].e += (nv == -1);
    t[x].xs = !t[x].e ? t[x].real_xs : -1;
    DBG("t[%d].e %d xs %d\n", x, t[x].e, t[x].xs);
    return;
  }
  modify(x << 1 | (pos & 1), T >> 1, pos >> 1, v, nv);
  up(x);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n, m, T, w);
  fill(a, a + n, -1);
  if (T >= (n & -n)) {
    int msk = (n & -n) - 1;
    int cycsiz = n / (n & -n);
    int undet = n, fail = 0, full = 0;
    vector<int> spec(msk + 1), cnt(msk + 1);

    auto modify = [&](int p, int v) {
      if (a[p] == -1) --undet;
      else {
        int r = p & msk;
        spec[r] ^= a[p], --cnt[r];
        full -= cnt[r] == cycsiz - 1;
        if (cnt[r] == cycsiz - 1 && (spec[r] ^ a[p]) != 0) --fail;
      }
      if (v == -1) ++undet;
      else {
        int r = p & msk;
        spec[r] ^= v, ++cnt[r];
        full += cnt[r] == cycsiz;
        if (cnt[r] == cycsiz && spec[r] != 0) ++fail;
      }
      a[p] = v;
    };

    for (int i = 0; i < m; ++i) {
      int pos, val;
      read(pos, val); --pos;
      modify(pos, val);
    }
    int qc = 0;
    read(qc);
    for (int i = 0; i < qc; ++i) {
      int pos, val, mod;
      read(pos, val, mod); --pos;
      modify(pos, val);
      DBG("fail = %d\n", fail);
      if (fail) puts("0");
      else {
        printf("%d\n", power(1 << w, undet - (msk + 1) + full, mod));
      }
    }
    return 0;
  }
  build(1, n, T);
  for (int i = 0; i < m; ++i) {
    int pos, val;
    read(pos, val); --pos;
    modify(1, T, pos, a[pos], val);
    a[pos] = val;
    DBG("t[1] : xs %d e %d\n", t[1].xs, t[1].e);
  }
  int qc;
  read(qc);
  while (qc--) {
    int pos, val, mod;
    read(pos, val, mod); --pos;
    modify(1, T, pos, a[pos], val);
    a[pos] = val;
    if (t[1].e < 0) puts("0");
    else {
      printf("%d\n", power(1 << w, t[1].e, mod));
    }
  }
  return 0;
}