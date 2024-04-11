#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;
using ll = long long;

namespace io {
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
  const int SIZE = (1 << 21) + 1;
  char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1;
  inline char getc () {return (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++);}
  inline void flush () {fwrite (obuf, 1, oS - obuf, stdout); oS = obuf; fflush(stdout);}
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
  template<> inline void write(char *s) {while(*s) putc(*s), ++s;}
  template<> inline void write(const char *s) {while(*s) putc(*s), ++s;}
  template<class T, class ...Args>
  inline void write(T x, Args... args) {write(x); putc(' '); write(args...);}
  inline void space() {putc(' ');}
  inline void endl() {putc('\n');}
  struct _flush {~_flush() {flush();}} __flush;
};
using io::read; using io::write; using io::flush; using io::space; using io::endl; using io::getc; using io::putc;

const int N = 100004;
vector<int> G[N], T[N];

int sz[N];
int n;
ll k;
void getsize(int x, int fa) {
  sz[x] = 1;
  for (int v : G[x]) {
    if (v == fa) continue;
    getsize(v, x);
    sz[x] += sz[v];
  }
}
int getcentroid(int x) {
  int fa = x;
  while (true) {
    bool flag = true;
    for (int v : G[x]) {
      if (sz[v] > n / 2 && v != fa) {
        fa = x;
        x = v;
        flag = false;
        break;
      }
    }
    if (flag) return x;
  }
}

priority_queue<pair<int, int> > subtree;
priority_queue<pair<int, int> > nonleaf[N];
bool vis[N];
int dep[N];
int centroid_subt;

void init(int x, int fa) {
  if (x != fa && G[x].size() > 1) nonleaf[centroid_subt].emplace(dep[x], x);
  sz[x] = 1;
  for (int v : G[x]) {
    if (v == fa) continue;
    T[x].push_back(v);
    dep[v] = dep[x] + 2;
    if (x == fa) centroid_subt = v;
    init(v, x);
    sz[x] += sz[v];
  }
}

int ord[N], tot = 0;
void getorder(int x, int fa) {
  if(!vis[x])
    ord[++tot] = x;
  for (int v : G[x]) {
    if (v == fa) continue;
    getorder(v, x);
  }
}

int main() {
  read(n, k);
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u, v);
    G[u].push_back(v); G[v].push_back(u);
  }
  getsize(1, 1);
  int c = getcentroid(1);
  init(c, c);
  ll low = 0, high = 0;
  for (int i = 1; i <= n; ++i)
    if (i != c) {
      low += sz[i] & 1;
      high += sz[i];
      assert(sz[i] <= n / 2);
    }
  if (k < low || k > high || ((k ^ high) & 1)) {
    write("NO\n");
    return 0;
  }
  write("YES\n");
  ll d = high - k;
  for (int v : G[c])
    if(sz[v] >= 2) subtree.emplace(sz[v], v);
  while (d) {
    int t = subtree.top().second, s = subtree.top().first;
    subtree.pop();
    int dep = nonleaf[t].top().first, x = nonleaf[t].top().second;
    nonleaf[t].pop();
    auto getchild = [&](int x) {
      while (!T[x].empty()) {
        if (vis[T[x].back()]) T[x].pop_back();
        else {
          int ret = T[x].back();
          T[x].pop_back();
          return ret;
        }
      }
      return -1;
    };
    if (d < dep) {
      while (true) {
        while (!nonleaf[t].empty() && nonleaf[t].top().first > d) nonleaf[t].pop();
        x = nonleaf[t].top().second;
        int c = getchild(x);
        if (c != -1) {
          vis[x] = vis[c] = true;
          write(x, c), endl();
          break;
        }
      }
      break;
    }
    int c[2];
    c[0] = getchild(x);
    if (c[0] == -1){
      subtree.emplace(s, t);
      continue;
    }
    c[1] = getchild(x);
    d -= dep;
    if (c[1] != -1) {
      vis[c[0]] = vis[c[1]] = true;
      write(c[0], c[1]), endl();
      if(!T[x].empty()) nonleaf[t].emplace(dep, x);
    }
    else {
      vis[x] = vis[c[0]] = true;
      write(x, c[0]), endl();
    }
    subtree.emplace(s - 2, t);
  }
  getorder(c, c);
  for (int i = 1, half = tot / 2; i <= half; ++i)
    write(ord[i], ord[i + half]), endl();
  return 0;
}