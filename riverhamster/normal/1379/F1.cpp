#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
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

const int N = 200005;
int x[N], y[N];
bool type[N];
int n, m, q;
int pmin[N];

bool check(int l){
  fill(pmin + 1, pmin + 1 + n, 0x7fffffff);
  for(int i=1; i<=l; i++)
    if(type[i]) upmin(pmin[x[i]], y[i]);
  for(int i=2; i<=n; i++)
    upmin(pmin[i], pmin[i - 1]);
  for(int i=1; i<=l; i++)
    if(!type[i] && pmin[x[i]] <= y[i]) return true;
  return false;
}

int main(){
//  File("cf1379f1");
  gi(n); gi(m); gi(q);
  for(int i=1; i<=q; i++){
    gi(x[i]); gi(y[i]);
    type[i] = x[i] & 1;
    x[i] = (x[i] + 1) / 2; y[i] = (y[i] + 1) / 2;
  }
  int l = 1, r = q, mid, res = q + 1;
  while(l <= r){
    mid = (l + r) >> 1;
    if(check(mid)) res = mid, r = mid - 1;
    else l = mid + 1;
  }
  for(int i=1; i<res; i++) puts("YES");
  for(int i=res; i<=q; i++) puts("NO");
  return 0;
}