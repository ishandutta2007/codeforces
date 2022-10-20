#pragma GCC optimize(2)
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
// #define DBG(f...) printf(f)
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

const int N = 1e6 + 5;
const ull K = 14631884094044847581ULL;

int a[2][N];
ll s[2][N];
int pr[3][N];
int n;

template <int siz, int bits>
struct hashtable {
  struct node {
    ull k;
    int v, nt;
  } t[siz + 1];
  int hd[1 << bits], cnt = 0;

  void clear() { memset(hd, 0, sizeof(hd)); cnt = 0; }
  node *find(ull k) {
    int h = (k * K) >> (64 - bits);
    int i = hd[h];
    while (i && t[i].k != k) i = t[i].nt;
    if (!i) {
      i = ++cnt; t[i] = {k, -1, hd[h]}; hd[h] = i;
    }
    return t + i;
  }
};

hashtable<N, 20> _pre;
hashtable<7000000, 23> dp;

int solve(int i, int j) {
  auto p = dp.find((ull)i << 32 | j);
  if (p->v != -1) return p->v;
  p->v = 0;
  int mn = min(i, j);
  if (~pr[2][mn])
    p->v = 1 + solve(pr[2][mn], pr[2][mn]);
  if (pr[0][i] != -1 || pr[1][j] != -1) {
    if (pr[0][i] > pr[1][j]) p->v = max(p->v, 1 + solve(pr[0][i], j));
    else p->v = max(p->v, 1 + solve(i, pr[1][j]));
  }
  return p->v;
}

int main() {
  read(n);
  for (int i = 1; i <= n; ++i)
    read(a[0][i]), s[0][i] = s[0][i - 1] + a[0][i];
  for (int i = 1; i <= n; ++i)
    read(a[1][i]), s[1][i] = s[1][i - 1] + a[1][i];
  for (int t = 0; t < 2; ++t) {
    _pre.clear();
    for (int i = 0; i <= n; ++i) {
      auto p = _pre.find(s[t][i]);
      pr[t][i] = p->v;
      p->v = i;
    }
  }
  _pre.clear();
  for (int i = 0; i <= n; ++i) {
    auto p = _pre.find(s[0][i] + s[1][i]);
    pr[2][i] = p->v;
    p->v = i;
  }
  for (int t = 0; t < 3; ++t)
    for (int i = 1; i <= n; ++i)
      pr[t][i] = max(pr[t][i], pr[t][i - 1]);
  printf("%d\n", solve(n, n));
  return 0;
}