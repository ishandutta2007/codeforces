#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <numeric>
#include <cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 500005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

int n, q;
char qc[MX];
int qa[MX], qb[MX];
// int pu[MX], pm[MX];
vi tu[MX], tmm[MX];
ll ans[MX];

// Binary Indexed Tree
struct bit{
  typedef ll TT;
  vector<TT> d; int x2;
  bit(){}
  bit(int mx){ x2 = 1; while(x2 < mx) x2 <<= 1; d.resize(x2+1);}
  void add(int i, TT x=1){ for(++i;i<=x2;i+=i&-i) d[i] += x;}
  void add2(int i, int j, TT x=1){ add(i,x); add(j,-x);}
  TT sum(int i){
    TT x = 0; for(++i;i;i-=i&-i) x += d[i];
    return x;
  }
};

// Segment tree (RMQ type)
struct seg{
  typedef int TT;
  vector<TT> d; int x2;
  seg(){}
  seg(int mx){ x2 = 1; while(x2 < mx) x2 <<= 1; d.resize(x2<<1);}
  int get(int i){
    int res = 0;
    for(i+=x2;i;i>>=1) maxs(res,d[i]);
    return res;
  }
  void add(int a, int b, TT x, int i=1, int l=0, int r=-1){
    if (r == -1) r = x2;
    if(a <= l && r <= b) {
      d[i] = x;
      return;
    }
    int c = (l+r)>>1;
    if(a < c) add(a,b,x,i<<1,l,c);
    if(c < b) add(a,b,x,i<<1|1,c,r);
  }
};
//

bool used[MX];
vi ms, us, mi, ui;
int mc[MX], uc[MX];

void mfs(int v) {
  mi[v] = sz(ms);
  ms.pb(v);
  for (int u : tmm[v]) {
    mfs(u);
  }
}
void ufs(int v) {
  ui[v] = sz(us);
  us.pb(v);
  for (int u : tu[v]) {
    ufs(u);
  }
}

vector<P> qs[MX];

int main() {
  scanf("%d%d",&n,&q);
  rep(qi,q) {
    int a, b = 0;
    char c;
    scanf(" %c",&c);
    if (c == 'U') {
      scanf("%d%d",&a,&b);
    }
    if (c == 'M') {
      scanf("%d%d",&a,&b);
    }
    if (c == 'A') {
      scanf("%d",&a);
    }
    if (c == 'Z') {
      scanf("%d",&a);
    }
    if (c == 'Q') {
      scanf("%d",&a);
    }
    --a; --b;
    qc[qi] = c;
    qa[qi] = a;
    qb[qi] = b;
  }

  rep(qi,q) {
    char c = qc[qi];
    int a = qa[qi], b = qb[qi];
    if (c == 'M') {
      tmm[a].pb(b);
      used[b] = true;
    }
  }
  mi = ui = vi(n);
  rep(i,n) if (!used[i]) mfs(i);
  rep(i,n) mc[i] = 1;
  seg dm(n+5);
  // rep(i,n) cout<<mi[i]<<endl;
  rep(qi,q) {
    char c = qc[qi];
    int a = qa[qi], b = qb[qi];
    if (c == 'M') {
      mc[a] += mc[b];
    }
    if (c == 'Z') {
      // cout<<a<<" "<<mi[a]<<" "<<mc[a]<<endl;
      dm.add(mi[a],mi[a]+mc[a],qi);
    }
    if (c == 'Q') {
      // cout<<qi<<" "<<mi[a]<<" "<<dm.get(mi[a])<<endl;
      qs[qi].pb(P(qi,a));
      qs[dm.get(mi[a])].pb(P(qi,a+n));
    }
  }

  rep(i,n) used[i] = false;
  rep(qi,q) {
    char c = qc[qi];
    int a = qa[qi], b = qb[qi];
    if (c == 'U') {
      tu[a].pb(b);
      used[b] = true;
    }
  }
  rep(i,n) if (!used[i]) ufs(i);
  rep(i,n) uc[i] = 1;
  bit du(n+5);
  rep(qi,q) {
    char c = qc[qi];
    int a = qa[qi], b = qb[qi];
    if (c == 'U') {
      uc[a] += uc[b];
    }
    if (c == 'A') {
      // cout<<a<<" "<<ui[a]<<" "<<uc[a]<<endl;
      du.add2(ui[a],ui[a]+uc[a],uc[a]);
    }
    if (qi == 0) continue;
    rep(qj,sz(qs[qi])) {
      int ai = qs[qi][qj].fi;
      int pos = qs[qi][qj].se;
      int sig = 1;
      if (pos >= n) {
        sig = -1;
        pos -= n;
      }
      // cout<<qi<<" "<<ai<<" "<<pos<<" "<<sig<<" "<<du.sum(ui[pos])<<endl;
      ans[ai] += du.sum(ui[pos])*sig;
    }
  }

  rep(qi,q) {
    char c = qc[qi];
    if (c == 'Q') {
      printf("%I64d\n", ans[qi]);
    }
  }
  return 0;
}