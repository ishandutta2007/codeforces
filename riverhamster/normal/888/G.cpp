#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
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
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}
const int N = 200005, W = 32;
int c[N * W][2], nc = 0;
ll res = 0;
void insert(int val){
  int p = 0;
  for(int i=29; i>=0; i--){
    int v = (val >> i) & 1;
    if(!c[p][v]) c[p][v] = ++nc;
    p = c[p][v];
  }
}
int query(int x, int y, int k){
  if(!c[x][0] && !c[x][1]) return 0;
  int ret = 0x7fffffff;
  if(c[x][0]){
    if(c[y][0]) upmin(ret, query(c[x][0], c[y][0], k - 1));
    else upmin(ret, query(c[x][0], c[y][1], k - 1) | (1 << k));
  }
  if(c[x][1]){
    if(c[y][1]) upmin(ret, query(c[x][1], c[y][1], k - 1));
    else upmin(ret, query(c[x][1], c[y][0], k - 1) | (1 << k));
  }
  return ret;
}
void dfs(int x, int k){
  if(k < 0) return;
  if((int)(c[x][0] != 0) + (int)(c[x][1] != 0) == 1){
    dfs(c[x][0] | c[x][1], k - 1);
    return;
  }
  res += query(c[x][0], c[x][1], k - 1) | (1 << k);
  dfs(c[x][0], k - 1); dfs(c[x][1], k - 1);
}

int main(){
  // File("cf888g");
  int n;
  gi(n);
  for(int i=1; i<=n; i++){
    int x; gi(x);
    insert(x);
  }
  dfs(0, 29);
  printf("%lld\n", res);
  return 0;
}