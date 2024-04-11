#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
namespace io {
  const int SIZE = (1 << 21) + 1;
  char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
  #define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
  char getc () {return gc();}
  inline void flush () {fwrite (obuf, 1, oS - obuf, stdout); oS = obuf;}
  inline void putc (char x) {*oS ++ = x; if (oS == oT) flush ();}
  template <class I> inline void gi (I &x) {for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;}
  template <class I> inline void print (I x) {if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;while (x) qu[++ qr] = x % 10 + '0',  x /= 10;while (qr) putc (qu[qr --]);}
  struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi; using io :: putc; using io :: print; using io :: getc;

const int N = 500005;
const ll INF = 1000000000000000000;
struct Edge {
  int v, w;
};
struct Query {
  int l, r, id;
};
vector<Edge> G[N];
vector<Query> Q[N];
ll res[N];
int n;

ll dis[N];
ll mn[N * 4], tag[N * 4];
void build(int x, int l, int r){
  if(l == r){
    mn[x] = dis[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
}
void modify(int x, int l, int r, int ql, int qr, int d){
  if(ql <= l && r <= qr){
    tag[x] += d, mn[x] += d;
    return;
  }
  int mid = (l + r) >> 1;
  if(ql <= mid) modify(x << 1, l, mid, ql, qr, d);
  if(qr > mid) modify(x << 1 | 1, mid + 1, r, ql, qr, d);
  mn[x] = min(mn[x << 1], mn[x << 1 | 1]) + tag[x];
}
ll query(int x, int l, int r, int ql, int qr){
  if(ql <= l && r <= qr) return mn[x];
  int mid = (l + r) >> 1;
  ll res = INF;
  if(ql <= mid) res = min(res, query(x << 1, l, mid, ql, qr));
  if(qr > mid) res = min(res, query(x << 1 | 1, mid + 1, r, ql, qr));
  return res + tag[x];
}

int R[N];
void dfs(int x){
  R[x] = x;
  for(Edge e : G[x]){
    dis[e.v] = dis[x] + e.w;
    dfs(e.v);
    R[x] = max(R[x], R[e.v]);
  }
  if(R[x] != x) dis[x] = INF;
}
void solve(int x){
  for(const Query &q : Q[x])
    res[q.id] = query(1, 1, n, q.l, q.r);
  for(Edge e : G[x]){
    modify(1, 1, n, e.v, R[e.v], -e.w - e.w);
    mn[1] += e.w; tag[1] += e.w;
    solve(e.v);
    modify(1, 1, n, e.v, R[e.v], e.w << 1);
    mn[1] -= e.w; tag[1] -= e.w;
  }
}

int main(){
  // File("tree");
  int q;
  gi(n); gi(q);
  for(int i=2; i<=n; i++){
    int fa, w;
    gi(fa); gi(w);
    G[fa].push_back({i, w});
  }
  for(int i=1; i<=q; i++){
    int x, l, r;
    gi(x); gi(l); gi(r);
    Q[x].push_back({l, r, i});
  }

  dfs(1);
  build(1, 1, n);
  solve(1);

  for(int i=1; i<=q; i++) print(res[i]), putc('\n');
  return 0;
}