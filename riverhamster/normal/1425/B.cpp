#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <numeric>
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

const int M = 1000000007;
inline int add(int x, int y) {return x+y>=M ? x+y-M : x+y;}
template<class ...Args> inline int add(int x, int y, Args... args) {return add(add(x, y), args...);}
inline int sub(int x, int y) {return x-y<0 ? x-y+M : x-y;}
inline int mul(int x, int y) {return 1LL * x * y % M;}
template<class ...Args> inline int mul(int x, int y, Args... args) {return mul(mul(x, y), args...);}
inline void inc(int &x, int y=1) {x += y; if(x >= M) x -= M;}
inline void dec(int &x, int y=1) {x -= y; if(x < 0) x += M;}
inline int power(int x, int y){
  int res = 1;
  for(; y; y>>=1, x = mul(x, x)) if(y & 1) res = mul(res, x);
  return res;
}
inline int inv(int x){return power(x, M - 2);}

const int N = 4005;

int _g[N * 2], *g = _g + N;
int n, m;

struct DP {
  int a[N * 2];
  int *f;
  DP() {
    f = a + N;
    fill(f - m, f + m + 1, 0);
    f[0] = 1;
  }
  void update(int x) {
    fill(g - m, g + m + 1, 0);
    for (int i = -m + x; i <= m - x; ++i)
      g[i - x] = (g[i - x] + f[i]) % M;
    for (int i = -m + x; i <= m - x; ++i)
      g[i + x] = (g[i + x] + f[i]) % M;
    for (int i = -m; i <= m; ++i)
      f[i] = (f[i] + g[i]) % M;
  }
  void select(int x) {
    fill(g - m, g + m + 1, 0);
    for (int i = -m + x; i <= m; ++i)
      g[i - x] = (g[i - x] + f[i]) % M;
    for (int i = -m; i <= m - x; ++i)
      g[i + x] = (g[i + x] + f[i]) % M;
    for (int i = -m; i <= m; ++i)
      f[i] = g[i];
  }
  void operator=(const DP &r) {
    for (int i = -m; i <= m; ++i)
      f[i] = r.f[i];
  }
  int query(int x) {
    int res = 0;
    for (int i = 2 - x; i <= x - 2; ++i)
      inc(res, f[i]);
    return res;
  }
};
vector<int> G[N];
int a[N];
bool vis[N];

DP f;
DP stk[20];
int top = 0;

int dfs(int x, int fa) {
  vis[x] = true;
  for (int v : G[x]) {
    if (v == fa) continue;
    if (v == 1) return 1;
    return dfs(v, x) + 1;
  }
  return 1; // 2-nodes
}

int res = 0;

void solve(int l, int r) {
  if (l == r) {
    inc(res, f.query(a[l]));
    return;
  }
  stk[top] = f;
  ++top;
  int mid = (l + r) >> 1;
  for (int i = l; i <= mid; ++i) f.update(a[i]);
  solve(mid + 1, r);
  f = stk[top - 1];
  for (int i = mid + 1; i <= r; ++i) f.update(a[i]);
  solve(l, mid);
  --top;
}
void solve2(int l, int r) {
  if (l == r) {
    inc(res, add(f.f[a[l]], f.f[a[l] - 1], f.f[1 - a[l]], f.f[-a[l]]));
    inc(res, add(f.f[a[l]], f.f[a[l] - 1], f.f[1 - a[l]], f.f[-a[l]]));
    return;
  }
  stk[top] = f;
  ++top;
  int mid = (l + r) >> 1;
  for (int i = l; i <= mid; ++i) f.select(a[i]);
  solve2(mid + 1, r);
  f = stk[top - 1];
  for (int i = mid + 1; i <= r; ++i) f.select(a[i]);
  solve2(l, mid);
  --top;
}

int main() {
  read(n, m);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    read(u, v);
    G[u].push_back(v); G[v].push_back(u);
  }
  int cnt = 0;
  for (int v : G[1]) {
    if (!vis[v])
      a[++cnt] = dfs(v, 1) + 1;
  }
  solve(1, cnt);
  res = mul(res, 2);
  if ((m & 1) == 0) {
    f = DP();
    for (int i = 1; i <= cnt; ++i)
      f.select(a[i]);
    inc(res, f.f[0]);
  }
  else {
    f = DP();
    solve2(1, cnt);
  }
  write(res), endl();
  return 0;
}