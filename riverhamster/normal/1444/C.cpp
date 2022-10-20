#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
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

#define LOG(f...) fprintf(stderr, f)

const int N = 500005;

int fa[N], rk[N], c[N];
int u[N], v[N], g[N];
int stx[N], sty[N], top = 0;
bool val[N];

pair<int, int> find(int x) {
  if (!fa[x]) return {x, 0};
  auto ret = find(fa[x]);
  ret.second ^= c[x];
  return ret;
}
#define fi first
#define se second
bool merge(int x, int y) {
  auto fx = find(x), fy = find(y);
  if (fx.fi == fy.fi) {
    if (fx.se == fy.se) return false;
    return true;
  }
  if (rk[fx.fi] < rk[fy.fi]) swap(fx, fy);
  ++top;
  stx[top] = fx.fi; sty[top] = fy.fi;
  fa[fy.fi] = fx.fi; c[fy.fi] = fx.se ^ fy.se ^ 1;
  rk[fx.fi] += rk[fx.fi] == rk[fy.fi];
  return true;
}
int bot;
void recover(int bot) {
  while (top != bot) {
    fa[sty[top]] = 0;
    rk[stx[top]] -= (rk[stx[top]] == rk[sty[top]] + 1);
    c[sty[top]] = 0;
    --top;
  }
}

map<pair<int, int>, int> mp;
vector<pair<int, int> > e[N];

int main() {
  int n, m, k;
  read(n, m, k);
  for (int i = 1; i <= n; ++i) read(g[i]);
  fill(val + 1, val + 1 + k, true);
  int cnt = 0;
  for (int i = 1; i <= m; ++i) {
    read(u[i], v[i]);
    if (g[u[i]] == g[v[i]])
      val[g[u[i]]] &= merge(u[i], v[i]);
    else {
      pair<int, int> gp = {g[u[i]], g[v[i]]};
      if (gp.fi > gp.se) swap(gp.fi, gp.se);
      if (!mp.count(gp)) mp.insert({gp, ++cnt}), e[cnt].emplace_back(u[i], v[i]);
      else e[mp[gp]].emplace_back(u[i], v[i]);
    }
  }
  bot = top;
  ll gr = accumulate(val + 1, val + 1 + k, 0LL);
  ll res = gr * (gr - 1) / 2;
  LOG("res = %lld\n", res);
  for (int i = 1; i <= cnt; ++i) {
    bool flag = true;
    recover(bot);
    auto p = e[i].front();
    if (!val[g[p.fi]] || !val[g[p.se]]) continue;
    for (auto p : e[i]) {
      if (!merge(p.fi, p.se)) {
        flag = false;
        break;
      }
    }
    res -= !flag;
  }
  assert(res >= 0);
  write(res), endl();
  return 0;
}