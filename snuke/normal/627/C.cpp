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
#include <bitset>
#include <cassert>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("-1"); return 0;}
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{for(T&x:v)i>>x;return i;}
template<typename T>string join(vector<T>&v)
{stringstream s;for(T&x:v)s<<' '<<x;return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,vector<T>&v)
{if(sz(v))o<<join(v);return o;}

const int MX = 200005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;


int n, l, m;
P p[MX];

// Segment tree (RMQ type)
struct seg {
  typedef ll TT;
  vector<TT> d, e; int x2;
  seg(){}
  seg(int mx) {
    x2 = 1; while(x2 < mx) x2 <<= 1;
    d.resize(x2<<1);
    e.resize(x2<<1,LINF);
  }
  void fil() {
    drep(i,x2) {
      e[i] = min(e[i<<1],e[i<<1|1]);
    }
  }
  void sp(int i) {
    int l = i<<1, r = l|1;
    d[l] += d[i]; e[l] -= d[i];
    d[r] += d[i]; e[r] -= d[i];
    d[i] = 0;
  }
  void add(int a, int b, TT x, int i=1, int l=0, int r=-1){
    if (r == -1) r = x2;
    if(a <= l && r <= b) {
      d[i] += x;
      e[i] -= x;
      return;
    }
    sp(i);
    int c = (l+r)>>1;
    if(a < c) add(a,b,x,i<<1,l,c);
    if(c < b) add(a,b,x,i<<1|1,c,r);
    e[i] = min(e[i<<1], e[i<<1|1]);
  }
  TT get(int a, int b, int i=1, int l=0, int r=-1){
    if (r == -1) r = x2;
    if(a <= l && r <= b) {
      return e[i];
    }
    sp(i);
    int c = (l+r)>>1;
    TT res = LINF;
    if(a < c) mins(res,get(a,b,i<<1,l,c));
    if(c < b) mins(res,get(a,b,i<<1|1,c,r));
    return res;
  }
  void pri() {
    rrep(i,x2-1) cout<<i<<" "<<d[i]<<" "<<e[i]<<endl;
  }
};
//

int main() {
  scanf("%d%d%d",&l,&m,&n);
  rep(i,n) scanf("%d%d",&p[i].fi,&p[i].se);
  sort(p,p+n);
  p[n++] = P(l,0);
  ll ans = 0, now = m;
  seg d(n+2);
  rep(i,n) d.e[d.x2+i] = p[i].fi;
  d.fil();
  priority_queue<P,vp,greater<P>> q;
  int pre = 0;
  rep(i,n) {
    // d.pri();
    now -= p[i].fi-pre; pre = p[i].fi;
    while (sz(q) && now < 0) {
      P a = q.top(); q.pop();
      int j = a.se;
      int x = p[j].fi, c = a.fi;
      ll r = d.get(j,n);
      if (now+r > 0) {
        ll am = -now;
        now = 0;
        d.add(j,n,am);
        ans += am*c;
        q.push(P(c,j));
      } else {
        now += r;
        d.add(j,n,r);
        ans += r*c;
      }
    }
    // cout<<i<<" "<<now<<" "<<ans<<endl;
    if (now < 0) dame;
    q.push(P(p[i].se,i));
  }
  cout<<ans<<endl;
  return 0;
}