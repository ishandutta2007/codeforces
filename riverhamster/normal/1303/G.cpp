#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
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

template <class T> void upmax(T &x, T y) { x = x > y ? x : y; }
template <class T> void upmin(T &x, T y) { x = x < y ? x : y; }

const int N = 150005;
vector<int> G[N];

int a[N];
bool vis[N];
int sz[N], dep[N], mxdep;
ll sum[N], spart[N];
ll res = 0;

namespace seg {
struct Line {
  ll k, b;
  ll operator()(ll x) { return k * x + b; }
};
Line t[N * 4];
bool ex[N * 4];
void insert(Line p) {
  int x = 1, l = 1, r = mxdep;
  while (true) {
    int mid = (l + r) >> 1;
    if (!ex[x]) {
      ex[x] = true, t[x] = p;
      return;
    }
    ll tl = t[x](l), tr = t[x](r), pl = p(l), pr = p(r);
    if (tl < pl && tr < pr)
      return void(t[x] = p);
    if (tl >= pl && tr >= pr)
      return;
    if (t[x](mid) < p(mid))
      swap(t[x], p), swap(tl, pl), swap(tr, pr);
    if (tl > pl)
      r = mid, x <<= 1;
    else
      l = mid + 1, x = x << 1 | 1;
  }
}
ll query(ll p) {
  int x = 1, l = 1, r = mxdep;
  ll res = 0;
  while (l != r) {
    int mid = (l + r) >> 1;
    if (ex[x])
      upmax(res, t[x](p));
    if (x <= mid)
      r = mid, x <<= 1;
    else
      l = mid + 1, x = x << 1 | 1;
  }
  if (ex[x])
    upmax(res, t[x](p));
  return res;
}
} // namespace seg

void getdep(int x, int fa) {
  upmax(mxdep, dep[x]);
  for (int v : G[x]) {
    if (v == fa || vis[v])
      continue;
    dep[v] = dep[x] + 1;
    getdep(v, x);
  }
}

void query(int x, int fa, ll p, ll sp) {
  p += a[x];
  sp += p;
  bool flag = true;
  for (int v : G[x]) {
    if (v == fa || vis[v])
      continue;
    flag = false;
    query(v, x, p, sp);
  }
  if (flag)
    upmax(res, seg::query(dep[x]) + sp);
}
void insert(int x, int fa, ll p, ll sp) {
  p += a[x];
  sp += 1LL * a[x] * (dep[x] + 1);
  bool flag = true;
  for (int v : G[x]) {
    if (v == fa || vis[v])
      continue;
    flag = false;
    insert(v, x, p, sp);
  }
  if (flag)
    seg::insert({p, sp});
}
void work(int x) {
  mxdep = 0;
  dep[x] = 0;
  getdep(x, x);
  if (mxdep == 0)
    return;
  fill_n(seg::ex + 1, mxdep * 4, false);
  for (auto v = G[x].begin(); v != G[x].end(); ++v) {
    if (vis[*v])
      continue;
    query(*v, x, 0, 0);
    if (next(v) != G[x].end())
      insert(*v, x, a[x], a[x]);
  }
  fill_n(seg::ex + 1, mxdep * 4, false);
  for (auto v = G[x].rbegin(); v != G[x].rend(); ++v) {
    if (vis[*v])
      continue;
    query(*v, x, 0, 0);
    if (next(v) != G[x].rend())
      insert(*v, x, a[x], a[x]);
  }
}

void getsize(int x, int fa) {
  sz[x] = 1;
  for (int v : G[x]) {
    if (v == fa || vis[v])
      continue;
    getsize(v, x);
    sz[x] += sz[v];
  }
}
int centroid(int x) {
  int fa = x, s = sz[x], w = 0;
  while (true) {
    bool flag = false;
    for (int v : G[x]) {
      if (v == fa || vis[v])
        continue;
      if (sz[v] * 2 > s) {
        flag = true, w = v;
        break;
      }
    }
    if (!flag)
      return x;
    fa = x, x = w;
  }
}
void solve(int x) {
  getsize(x, x);
  int g = centroid(x);
  work(g);
  vis[g] = true;
  for (int v : G[g])
    if (!vis[v])
      solve(v);
}

int main() {
  int n;
  read(n);
  for (int i = 1; i < n; i++) {
    int x, y;
    read(x, y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  for (int i = 1; i <= n; i++)
    read(a[i]);
  if (n == 1) {
    printf("%d\n", a[1]);
    return 0;
  }
  if (n == 2) {
    printf("%d\n", max(a[1] * 2 + a[2], a[2] * 2 + a[1]));
    return 0;
  }
  solve(1);
  printf("%lld\n", res);
  return 0;
}