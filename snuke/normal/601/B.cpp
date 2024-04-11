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
#define df(x) int x = in()
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

// // Segment tree (RMQ type)
// struct seg{
//   typedef ll TT;
//   vector<TT> d, s; int x2;
//   seg(){}
//   seg(int mx){
//     x2 = 1; while(x2 < mx) x2 <<= 1;
//     d.resize(x2<<1);
//     s.resize(x2<<1);
//   }
//   void fil(){
//     drep(i,x2) {
//       int l = i<<1, r = l|1;
//       d[i] = max(d[l],d[r]);
//     }
//   }
//   TT get(int a, int b, int i=1, int l=0, int r=-1){
//     if (r == -1) r = x2;
//     if(a <= l && r <= b) return d[i];
//     int c = (l+r)>>1; TT res = -LINF;
//     if(a < c) res = max(res,get(a,b,i<<1,l,c));
//     if(c < b) res = max(res,get(a,b,i<<1|1,c,r));
//     return res;
//   }
// };
// //

int a[MX];
// Union find
struct uf{
  vector<int> d;
  uf(){}
  uf(int mx):d(mx,-1){}
  int root(int x){
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  void unite(int x, int y){
    x = root(x); y = root(y);
    if(x == y) return;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y]; d[y] = x;
  }
};
//

ll solve(int x[], int n) {
  vector<P> p(n);
  rep(i,n) p[i] = P(x[i],i);
  sort(rng(p));
  ll res = 0;
  uf t(n+1);
  rep(i,n) {
    int j = p[i].se;
    int l = t.root(j);
    int r = t.root(j+1);
    res += (ll)p[i].fi*t.d[l]*t.d[r];
    t.unite(l,r);
  }
  return res;
}

int main() {
  int n;
  scanf("%d",&n);
  int q;
  scanf("%d",&q);
  rep(i,n) scanf("%d",&a[i]);
  rep(i,n-1) a[i] = abs(a[i]-a[i+1]);
  // seg t(n);
  // rep(i,n-1) t.d[t.mx+i] = abs(a[i]-a[i+1]);
  // t.fil();
  rep(qi,q) {
    int l, r;
    scanf("%d%d",&l,&r);
    printf("%I64d\n", solve(a+l-1,r-l));
  }
  return 0;
}