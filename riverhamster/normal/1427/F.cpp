#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <cassert>
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

const int N = 1205;

bool f[N];
vector<int> dep[N];
int stk[N], top = 0;
int stkd[N], dtop = 0;
int pos[N][3];
int res[N];
bool root[N];
struct cmp_size {
  bool operator()(int x, int y) {
    return dep[x].size() < dep[y].size();
  }
};
priority_queue<int, vector<int>, cmp_size> q[2];

int main() {
  int n;
  read(n);
  for (int i = 1; i <= 3 * n; ++i) {
    int x; read(x);
    f[x] = true;
  }

  int cnt = 0;
  fill(root + 1, root + 1 + n * 2, true);
  for (int i = 1; i <= 6 * n; ++i) {
    stk[++top] = i;
    while (top >= 3 && f[stk[top]] == f[stk[top - 1]] && f[stk[top - 1]] == f[stk[top - 2]]) {
      int l = stk[top - 2];
      ++cnt;
      while (dtop != 0 && pos[stkd[dtop]][0] > l) {
        root[stkd[dtop]] = false;
        dep[cnt].push_back(stkd[dtop--]);
      }
      stkd[++dtop] = cnt;
      for (int i = 2; i >= 0; --i) pos[cnt][i] = stk[top--];
    }
  }
  for (int i = 1; i <= cnt; ++i)
    if (root[i])
      q[f[pos[i][0]]].push(i);

  for (int i = 2 * n; i >= 1; --i) {
    int now = i & 1;
    int x = q[now].top();
    q[now].pop();
    res[i] = x;
    for (int v : dep[x])
      q[now ^ 1].push(v);
  }
  for (int i = 1; i <= n * 2; ++i)
    write(pos[res[i]][0], pos[res[i]][1], pos[res[i]][2]), endl();
  return 0;
}