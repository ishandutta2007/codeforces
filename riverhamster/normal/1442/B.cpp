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
#define getc getchar
#define putc putchar
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
using io::read; using io::write; using io::flush; using io::space; using io::endl;

const int N = 200005;
int lt[N], rt[N], pos[N], a[N], b[N];
bool key[N];
int find(int *fa, int x) {
  if (!fa[x]) return x;
  return fa[x] = find(fa, fa[x]);
}

void work() {
  int n, k;
  read(n, k);
  fill(lt + 1, lt + 1 + n, 0); fill(rt + 1, rt + 1 + n, 0);
  fill(key + 1, key + 1 + n, 0);
  key[0] = key[n + 1] = true;
  for (int i = 1; i <= n; ++i) {
    read(a[i]);
    pos[a[i]] = i;
  }
  for (int i = 1; i <= k; ++i) {
    read(b[i]);
    key[pos[b[i]]] = true;
  }
  int res = 1;
  for (int i = 1; i <= k; ++i) {
    int p = pos[b[i]];
    int l = find(lt, p - 1), r = find(rt, p + 1);
    if (key[l] && key[r]) {
      write(0), endl();
      return;
    }
    if (!key[l] && !key[r]) res = (res + res) % 998244353;
    lt[p] = l; rt[p] = r;
  }
  write(res), endl();
}

int main() {
  int T;
  read(T);
  while (T--) work();
  return 0;
}