#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <chrono>
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
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

const int N = 1 << 12, Q = 1 << 16;
const unsigned long long P1 = 180143985094819841, P2 = 1945555039024054273;

template<>
struct std::hash<pair<int, int> >{
  unsigned long long operator()(pair<int, int> p) const{
    return (unsigned long long)p.first * P1 + (unsigned long long)p.second * P2;
  }
};

size_t _hash_mask = std::chrono::steady_clock::now().time_since_epoch().count();
template<class T, class Hash>
struct safe_hash {
  size_t operator()(const T &x) const {
    return Hash()(x) ^ _hash_mask;
  }
};

template<class T, class Hash = std::hash<T>>
using safe_unordered_set = std::unordered_set<T, safe_hash<T, std::hash<T>>>;

template<class Kt, class Vt, class Hash = std::hash<Kt>>
using safe_unordered_map = std::unordered_map<Kt, Vt, safe_hash<Kt, std::hash<Kt>>>;

#define unordered_set safe_unordered_set
#define unordered_map safe_unordered_map

typedef unordered_map<pair<int, int>, int> d2;

int a[N], res[Q], pos[N];
d2 tr[N << 2];
vector<int> p[N << 2], suml[N << 2];
pair<int, int> op[2200005];
int oc = 0, cnt;

// all ranges are [l, r)
void build(int x, int l, int r){
  if(l + 1 == r) return;
  int mid = (l + r) >> 1;
  suml[x].resize(r - l);
  p[x << 1].reserve(mid - l), p[x << 1 | 1].reserve(r - mid);
  suml[x][0] = p[x][0] < mid;
  if(p[x][0] < mid) p[x << 1].push_back(p[x][0]);
  else p[x << 1 | 1].push_back(p[x][0]);
  for(int i=1; i<r-l; i++){
    suml[x][i] = suml[x][i - 1] + int(p[x][i] < mid);
    if(p[x][i] < mid) p[x << 1].push_back(p[x][i]);
    else p[x << 1 | 1].push_back(p[x][i]);
  }
  build(x << 1, l, mid);
  build(x << 1 | 1, mid, r);
}
int query(int x, int l, int r, int ql, int qr){
  if(l + 1 == r) return pos[p[x][0]];
  int &res = tr[x][{ql, qr}];
  assert(ql < r - l && qr <= r - l);
  if(res) return res;
  int mid = (l + r) >> 1;
  int l0 = ql == 0 ? 0 : suml[x][ql - 1], r0 = suml[x][qr - 1];
  int l1 = ql == 0 ? 0 : ql - suml[x][ql - 1], r1 = qr - suml[x][qr - 1];
  if(l0 == r0) return query(x << 1 | 1, mid, r, l1, r1);
  if(l1 == r1) return query(x << 1, l, mid, l0, r0);
  op[++oc] = {query(x << 1, l, mid, l0, r0), query(x << 1 | 1, mid, r, l1, r1)};
  return res = ++cnt;
}

int main(){
  int n, q;
  gi(n); gi(q);
  for(int i=0; i<n; i++) gi(a[i]), --a[i], pos[a[i]] = i + 1;
  p[1].resize(n);
  copy(a, a + n, p[1].begin());
  build(1, 0, n);
  cnt = n;
  for(int i=0; i<q; i++){
    int l, r;
    gi(l); gi(r); --l;
    res[i] = query(1, 0, n, l, r);
  }
  print(oc + n); putc('\n');
  for(int i=1; i<=oc; i++) print(op[i].first), putc(' '), print(op[i].second), putc('\n');
  for(int i=0; i<q; i++) print(res[i]), putc(' ');
  putc('\n');
  return 0;
}