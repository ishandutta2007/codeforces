#include <cstdio>
#include <cctype>
#include <cmath>
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
int t[N], n;
void insert(int p) {
  for(++p; p <= n + 1; p += p & -p) ++t[p];
}
int query(int p) {
  int s = 0;
  for(++p; p ; p ^= p & -p) s += t[p];
  return s;
}

vector<pair<int, int> > Q[N];
int res[N], a[N];

int main() {
  int q;
  read(n, q);
  int lgn = log2(n);
  for (int i = 1; i <= n; ++i)
    read(a[i]), a[i] = i - a[i];
  for (int i = 1; i <= q; ++i) {
    int l, r;
    read(l, r);
    r = n - r + 1;
    Q[r].emplace_back(l, i);
  }
  int now = 0;
  for (int i = 1; i <= n; ++i) {
    for (auto q : Q[i])
      res[q.second] = now - query(q.first);
    if(a[i] < 0) continue;
    if(a[i] > now) continue;
    int s = now, p = 0;
    for (int j = lgn; j >= 0; --j) {
      int val = t[p | (1 << j)];
      if((p | (1 << j)) <= i && s - val >= a[i]){
        p |= 1 << j;
        s -= val;
      }
    }
    ++now;
    insert(p);
  }
  for (auto q : Q[n + 1])
    res[q.second] = now - query(q.first);
  for (int i = 1; i <= q; ++i)
    write(res[i]), endl();
  return 0;
}