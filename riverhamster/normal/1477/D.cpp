#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>
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

const int N = 500005;

set<int> V;
vector<int> G[N], T[N], star[N];
int p[N], q[N];
int ass[N], cnt[N];

void DFS(int x) {
  V.erase(x);
  auto it = G[x].begin();
  int cur = 0;
  while (true) {
    auto v = V.upper_bound(cur);
    if (v == V.end()) return;
    cur = *v;
    while (it != G[x].end() && *it < *v) ++it;
    if (it != G[x].end() && *it == *v) continue;
    T[x].push_back(*v); T[*v].push_back(x);
    DFS(*v);
  }
}

int main() {
  int cases;
  read(cases);
  while (cases--) {
    int n, m;
    read(n, m);
    V.clear();
    for (int i = 1; i <= n; ++i) {
      V.insert(i);
      G[i].clear(); T[i].clear(); star[i].clear();
    }
    fill(ass + 1, ass + 1 + n, 0);
    fill(cnt + 1, cnt + 1 + n, 0);
    fill(p + 1, p + 1 + n, 0);
    fill(q + 1, q + 1 + n, 0);
    for (int i = 1; i <= m; ++i) {
      int u, v; read(u, v);
      G[u].push_back(v); G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) sort(G[i].begin(), G[i].end());
    while (!V.empty()) DFS(*V.begin());
    int l = 0, r = 0;
    for (int i = 1; i <= n; ++i) {
      if (ass[i]) continue;
      if (T[i].empty()) {
        p[i] = q[i] = ++l;
        ++r; continue;
      }
      for (int v : T[i])
        if (!ass[v] && !cnt[v]) {
          ass[v] = i;
          ++cnt[i];
        }
      if (!cnt[i]) {
        int v = T[i].front();
        if (cnt[v]) { ass[i] = v; continue; }
        if (cnt[ass[v]] > 1) {
          --cnt[ass[v]];
          cnt[i] = 1, ass[v] = i;
          continue;
        }
        if (cnt[ass[v]] == 1) {
          ass[ass[v]] = v; cnt[ass[v]] = 0;
          ass[v] = 0;
          cnt[v] = 2; ass[i] = v;
          continue;
        }
      }
    }
    for (int i = 1; i <= n; ++i)
      if (ass[i]) star[ass[i]].push_back(i);
    for (int i = 1; i <= n; ++i)
      if (!star[i].empty()) {
        p[i] = ++l;
        for (int v : star[i])
          p[v] = ++l, q[v] = ++r;
        q[i] = ++r;
      }
    for (int i = 1; i <= n; ++i) write(p[i]), space();
    endl();
    for (int i = 1; i <= n; ++i) write(q[i]), space();
    endl();
  }
  return 0;
}