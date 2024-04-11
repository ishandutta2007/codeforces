#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;
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
    do x = x * 10 + ch - '0'; while(isdigit(ch = getc()));
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

const int N = 300005;

int a[N];
vector<int> O[N];
int res[N];

int main() {
  // File("a");
  int T;
  read(T);
  while (T--) {
    int n;
    read(n);
    for (int i = 1; i <= n; ++i) O[i].clear();
    for (int i = 1; i <= n; ++i) read(a[i]), O[a[i]].push_back(i);
    fill(res + 1, res + 1 + n, 0x3fffffff);
    for (int i = 1; i <= n; ++i) {
      if (O[i].empty()) continue;
      int d = max(O[i].front(), n - O[i].back() + 1);
      for (int j = 1; j < (int)O[i].size(); ++j)
        d = max(d, O[i][j] - O[i][j - 1]);
      // printf("i %d d %d\n", i, d);
      res[d] = min(res[d], i);
    }
    if (res[1] == 0x3fffffff) write(-1), space();
    else write(res[1]), space();
    for (int i = 2; i <= n; ++i) {
      res[i] = min(res[i], res[i - 1]);
      if (res[i] == 0x3fffffff) write(-1), space();
      else write(res[i]), space();
    }
    endl();
  }
  return 0;
}