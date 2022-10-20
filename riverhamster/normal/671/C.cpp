#include <cstdio>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cassert>
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

const int N = 200005, V = 200000;

ll sum[N * 4];
int mn[N * 4], tag[N * 4];
void up(int x){
  sum[x] = sum[x << 1] + sum[x << 1 | 1];
  mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
}
void push(int x, int lenl, int lenr){
  if(tag[x]){
    sum[x << 1] = 1LL * tag[x] * lenl; sum[x << 1 | 1] = 1LL * tag[x] * lenr;
    mn[x << 1] = mn[x << 1 | 1] = tag[x];
    tag[x << 1] = tag[x << 1 | 1] = tag[x];
    tag[x] = 0;
  }
}
void assign(int x, int l, int r, int ql, int qr, int v){
  if(ql <= l && r <= qr){
    tag[x] = v;
    sum[x] = 1LL * v * (r - l + 1);
    mn[x] = v;
    return;
  }
  int mid = (l + r) >> 1;
  push(x, mid - l + 1, r - mid);
  if(ql <= mid) assign(x << 1, l, mid, ql, qr, v);
  if(qr > mid) assign(x << 1 | 1, mid + 1, r, ql, qr, v);
  up(x);
}
int lower(int x, int l, int r, int v){
  if(l == r) return sum[x] < v ? l : 1000000000;
  int mid = (l + r) >> 1;
  push(x, mid - l + 1, r - mid);
  if(mn[x << 1] < v) return lower(x << 1, l, mid, v);
  return lower(x << 1 | 1, mid + 1, r, v);
}
ll qsum(int x, int l, int r, int ql, int qr){
  if(ql <= l && r <= qr) return sum[x];
  int mid = (l + r) >> 1;
  push(x, mid - l + 1, r - mid);
  ll s = 0;
  if(ql <= mid) s += qsum(x << 1, l, mid, ql, qr);
  if(qr > mid) s += qsum(x << 1 | 1, mid + 1, r, ql, qr);
  return s;
}

ll h[N];
int s[N][2], t[N][2];

vector<pair<int, int> > r[N];

int main(){
//  File("c");
  int n;
  gi(n);
  for(int i=1; i<=n; i++){
    int x; gi(x);
    if(!s[x][0]) s[x][0] = i;
    else if(!s[x][1]) s[x][1] = i;
    t[x][1] = t[x][0]; t[x][0] = i;
  }

  for(int d=1; d<=V; d++){
    if(!s[d][0]) s[d][0] = n + 1;
    if(!s[d][1]) s[d][1] = n + 1;
    for(int i=d+d; i<=V; i+=d){
      if(s[i][0] && s[i][0] < s[d][0])
        s[d][1] = s[d][0], s[d][0] = s[i][0];
      else if(s[i][0] && s[i][0] < s[d][1])
        s[d][1] = s[i][0];
      if(s[i][1] && s[i][1] < s[d][1])
        s[d][1] = s[i][1];
      if(t[i][0] > t[d][0])
        t[d][1] = t[d][0], t[d][0] = t[i][0];
      else if(t[i][0] > t[d][1])
        t[d][1] = t[i][0];
      if(t[i][1] > t[d][1]) t[d][1] = t[i][1];
    }
    if(s[d][0] == n + 1) s[d][0] = 0;
    if(s[d][1] == n + 1) s[d][1] = 0;
  }

  for(int i=1; i<=V; i++){
    if(s[i][0] && t[i][0] && t[i][0] - s[i][0] >= 2)
      r[s[i][0] + 1].push_back({t[i][0] - 1, i});
    if(s[i][0] && s[i][1] && s[i][1] != n)
      r[s[i][1] + 1].push_back({n, i});
    if(t[i][0] && t[i][1] && t[i][1] != 1)
      r[1].push_back({t[i][1] - 1, i});
  }
#define Rt 1, 1, n  
  ll res = 0;
  for(int i=1; i<=n; i++){
    for(auto q : r[i]){
      int p = lower(Rt, q.second);
      if(p <= q.first) assign(Rt, p, q.first, q.second);
    }
    res += qsum(Rt, i, n);
    assign(Rt, i, i, V + 1);
  }
  printf("%lld\n", res);
  return 0;
}