#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define all(cont) begin(cont), end(cont)

using ll = long long;

namespace io {
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
  const int SIZE = (1 << 21) + 1;
  char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1;
  inline char getc () {return (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++);}
  inline void flush () {fwrite (obuf, 1, oS - obuf, stdout); oS = obuf;}
  inline void putc (char x) {*oS ++ = x; if (oS == oT) flush ();}
  template<class T>
  inline void read(T &x) {
    char ch; int f = 1;
    x = 0;
    while(isspace(ch = getc()));
    if(ch == '-') ch = getc(), f = -1;
    do x = x * 10 + (ch - '0'); while(isdigit(ch = getc()));
    x *= f;
  }
  template<class T, class ...Args>
  inline void read(T &x, Args&... args) {read(x); read(args...);}
  template<class T>
  inline void write(T x) {
    static char stk[128];
    int top = 0;
    if(x == 0) {putc('0'); return;}
    if(x < 0) putc('-'), x = -x;
    while(x) stk[top++] = x % 10, x /= 10;
    while(top) putc(stk[--top] + '0');
  }
  template<class T, class ...Args>
  inline void write(T x, Args... args) {write(x); putc(' '); write(args...);}
  inline void space() {putc(' ');}
  inline void endl() {putc('\n');}
  struct _flush {~_flush() {flush();}} __flush;
};
using io::read; using io::write; using io::flush; using io::space; using io::endl; using io::getc; using io::putc;

const int N = 505;

vector<int> pos[N][N];
int a[N * 2][N];
bool del[N * 2], sel[N * 2];

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
    fill_n(sel, 2 * n, false);
    fill_n(del, 2 * n, false);
    for (int i = 0; i < n * 2; ++i)
      for (int j = 0; j < n; ++j)
        read(a[i][j]), --a[i][j];
    int ans = 1, scnt = 0;
    while (scnt < n) {
      start:
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          pos[i][j].clear();
      for (int i = 0; i < n * 2; ++i)
        if (!del[i])
          for (int j = 0; j < n; ++j)
            pos[j][a[i][j]].push_back(i);
      bool flag = false;
      for (int i = 0; i < n; ++i) {
        for (int val = 0; val < n; ++val)
          if (pos[i][val].size() == 1) {
            int ln = pos[i][val].front();
            if (del[ln]) continue;
            sel[ln] = true; ++scnt;
            flag = true;
            for (int j = 0; j < n; ++j) {
              for (int l : pos[j][a[ln][j]])
                del[l] = true;
            }
          }
      }
      if (flag) continue;
      for (int i = 0; i < n * 2; ++i) {
        if (del[i]) continue;
        sel[i] = true; ++scnt;
        ans = (ans + ans) % 998244353;
        for (int j = 0; j < n; ++j)
          for (int ln : pos[j][a[i][j]])
            del[ln] = true;
        if (scnt == n) break;
        goto start;
      }
    }
    printf("%d\n", ans);
    for (int i = 0; i < 2 * n; ++i)
      if (sel[i]) printf("%d ", i + 1);
    putchar('\n');
  }
  return 0;
}