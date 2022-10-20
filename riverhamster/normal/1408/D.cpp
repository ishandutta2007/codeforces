#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
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

const int N = 2005, V = 2000005;

struct pt {
  int x, y;
}a[N], b[N];

vector<int> up[V];
queue<int> q[N];

const int L = 2000005;
int sel[L];

bool cmp(pt x, pt y) {
  if (x.x == y.x) return x.y > y.y;
  return x.x < y.x;
}

int main() {
  // File("d");
  // setbuf(stdout, NULL);
  int n, m;
  read(n, m);
  for (int i = 1; i <= n; ++i)
    read(a[i].x, a[i].y);
  for (int i = 1; i <= m; ++i)
    read(b[i].x, b[i].y);
  sort(a + 1, a + 1 + n, cmp);
  sort(b + 1, b + 1 + m, cmp);
  int dy = 0;
  for (int i = 1; i <= n; ++i) {
    bool flag = false;
    for (int j = 1; j <= m; ++j)
      if (a[i].x <= b[j].x && a[i].y <= b[j].y) {
        if (j != 1 && b[j].x == b[j - 1].x) continue;
        q[i].push(j);
        ++sel[b[j].y - a[i].y + 1];
        dy = max(dy, b[j].y - a[i].y + 1);
        flag = true;
      }
    if (flag) {
      up[b[q[i].front()].x + 1 - a[i].x].push_back(i);
    }
  }
  if (dy == 0) {
    write(0), endl();
    return 0;
  }
  int res = dy;
  for (int dx = 1; dx <= 1000001; ++dx) {
    for (int i : up[dx]) {
      int id = q[i].front();
      --sel[b[id].y - a[i].y + 1];
      while (dy != 0 && !sel[dy]) --dy;
      q[i].pop();
      if (!q[i].empty()) up[b[q[i].front()].x + 1 - a[i].x].push_back(i);
    }
    up[dx].clear(); up[dx].shrink_to_fit();
    res = min(res, dx + dy);
    if (dy == 0) break;
  }
  write(res), endl();
  return 0;
}