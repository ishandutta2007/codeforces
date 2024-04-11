#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <cassert>
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

const int N = 1000005;
int a[N];
struct S {
  int v, id;
}s[N];
int pos[N];
vector<int> op[N];

int main() {
  // File("cf1119g");
  int m, n, sum = 0;
  read(n, m);
  for (int i = 1; i <= m; ++i)
    read(a[i]), sum += a[i];
  write((sum - 1) / n + 1), endl();
  if (sum % n != 0) a[1] += n - sum % n;
  for (int i = 1; i <= m; ++i) {
    s[i].v = (s[i - 1].v + a[i]) % n;
    s[i].id = i;
  }
  s[m].v = n;
  sort(s + 1, s + 1 + m, [](S a, S b) {return a.v < b.v;});

  for (int i = 1; i <= m; ++i)
    write(s[i].v - s[i - 1].v), space();
  endl();

  for (int i = 1; i <= m; ++i)
    pos[s[i].id] = i;

  int pre_cnt = 0;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1, li = a[i] / n; j <= li; ++j) {
      for (int k = 1; k <= m; ++k)
        write(i), space();
      endl();
      ++pre_cnt;
    }
    a[i] %= n;
  }

  for (int i = 1; i <= m; ++i) {
    if (a[i] == 0) continue;
    int l = pos[i - 1] + 1, r = pos[i];
    if (l <= r)
      for (int j = l; j <= r; ++j)
        op[j].push_back(i);
    else {
      for (int j = l; j <= n; ++j)
        op[j].push_back(i);
      for (int j = 1; j <= r; ++j)
        op[j].push_back(i);
    }
  }
  int cnt = (sum - 1) / n + 1 - pre_cnt;
  for (int i = 0; i < cnt; ++i) {
    for (int j = 1; j <= m; ++j)
      if ((int)op[j].size() > i) write(op[j][i]), space();
      else write(1), space();
    endl();
  }
  return 0;
}