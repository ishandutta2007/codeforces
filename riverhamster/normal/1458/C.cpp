#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;
using ll = long long;

#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
namespace io {
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
    do x = x * 10 + ch - '0'; while(isdigit(ch = getc()));
    x *= f;
  }
  inline void read(char *s) {
    char c;
    while (isspace(c = getc()));
    do *s = c, ++s; while (isalpha(c = getc()));
    *s = 0;
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

char s[100005];
int res[1005][1005];

int main() {
  int T;
  read(T);
  while (T--) {
    int n, m;
    read(n, m);
    vector<array<int, 3>> p(n * n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        int x; read(x); --x;
        p[i * n + j] = {i, j, x};
      }
    array<int, 3> d = {0, 0, 0}, ord = {0, 1, 2};
    read(s);
    for (int i = 0; i < m; ++i) {
      switch (s[i]) {
        case 'R': ++d[1]; break;
        case 'L': --d[1]; break;
        case 'U': --d[0]; break;
        case 'D': ++d[0]; break;
        case 'I': swap(d[1], d[2]); swap(ord[1], ord[2]); break;
        case 'C': swap(d[0], d[2]); swap(ord[0], ord[2]); break;
      }
    }
    for (auto &x : d) x = (x % n + n) % n;
    for (auto &x : p) {
      x = {x[ord[0]], x[ord[1]], x[ord[2]]};
      for (int i = 0; i < 3; ++i) x[i] = (x[i] + d[i]) % n;
      res[x[0]][x[1]] = x[2];
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        write(res[i][j] + 1), space();
      endl();
    }
    endl();
  }
  return 0;
}