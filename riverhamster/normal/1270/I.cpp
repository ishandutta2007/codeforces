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

const int SIZE = 1 << 21;
char ibuf[SIZE], *iS, *iT;
char getc() { return (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++); }

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getc()));
  if (ch == '-') ch = getc(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getc()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

using ull = unsigned long long;

const int N = 513;

ull a[N][N], b[N][N];
int x[100], y[100];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  read(n);
  for (int i = 0; i < (1 << n); ++i)
    for (int j = 0; j < (1 << n); ++j)
      read(a[i][j]);
  const int mask = (1 << n) - 1;
  int t;
  read(t);
  for (int i = 0; i < t; ++i)
    read(x[i], y[i]);
  for (int i = 0; i < n; ++i) {
    memset(b, 0, sizeof(b));
    for (int j = 0; j < (1 << n); ++j)
      for (int k = 0; k < (1 << n); ++k)
        for (int p = 0; p < t; ++p)
          b[(j + x[p]) & mask][(k + y[p]) & mask] ^= a[j][k];
    for (int p = 0; p < t; ++p) {
      x[p] = (x[p] << 1) & mask;
      y[p] = (y[p] << 1) & mask;
    }
    memcpy(a, b, sizeof(a));
  }
  int res = 0;
  for (int i = 0; i < (1 << n); ++i)
    for (int j = 0; j < (1 << n); ++j)
      res += (a[i][j] > 0);
  printf("%d\n", res);
  return 0;
}