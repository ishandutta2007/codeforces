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

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

// Segment tree (RMQ type)
struct seg{
  typedef int TT;
  vector<TT> d; int x2;
  seg(){}
  seg(int mx, int defo){ x2 = 1; while(x2 < mx) x2 <<= 1; d.resize(x2<<1,defo);}
  TT get(int i){
    int res = INF;
    for(i+=x2;i;i>>=1) mins(res,d[i]);
    return res;
  }
  void up(int a, int b, int x, int i=1, int l=0, int r=-1){
    if (r == -1) r = x2;
    if(a <= l && r <= b) {
      mins(d[i],x);
      return;
    }
    int c = (l+r)>>1;
    if(a < c) up(a,b,x,i<<1,l,c);
    if(c < b) up(a,b,x,i<<1|1,c,r);
  }
};
//

vector<P> p;
map<int,int> mp;
vector<int> xs;

int main() {
  int n, q;
  scanf("%d%d",&n,&q);
  rep(qi,q) {
    int x, y; char c;
    scanf("%d%d %c",&x,&y,&c);
    --x; --y;
    mp[x] = 0;
    if (c == 'L') {
      p.pb(P(x,0));
    } else {
      p.pb(P(x,1));
    }
  }
  int cnt = 0;
  for (auto it = mp.begin(); it != mp.end(); ++it) {
    it->se = cnt++;
    xs.pb(it->fi);
  }
  xs.pb(n);
  mp[n] = cnt;
  seg ta(cnt+5, cnt);
  seg tb(cnt+5, 1);
  // ll ans = 0;
  set<int> alr;
  rep(qi,q) {
    int x = p[qi].fi;
    if (alr.count(x)) {
      puts("0");
      continue;
    }
    int xi = mp[x];
    if (p[qi].se) { // U
      int yi = ta.get(xi);
      int y = xs[yi];
      // ans += y-x;
      printf("%d\n",y-x);
      tb.up(xi,yi,-xi);
      // printf("%d %d %d\n",x,yi,y);
    } else {
      int yi = -tb.get(xi);
      int y = 0;
      if (yi == -1) y = -1, yi = 0; else y = xs[yi];
      // ans += x-y;
      printf("%d\n",x-y);
      ta.up(yi,xi,xi);
    }
    alr.insert(x);
  }
  // cout<<ans<<endl;
  return 0;
}