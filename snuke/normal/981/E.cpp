#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>inline ostream& operator<<(ostream&o,const v(T)&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>inline ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
template<typename T>inline ll suma(const v(T)& a) { ll res(0); for (auto&& x : a) res += x; return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("YES");}else{puts("NO");}
const int MX = 200005;

typedef bitset<10001> B;

B ans;
// Segment tree (RMQ type)
struct seg {
  typedef vi TT;
  vector<TT> d; int n;
  seg(){}
  seg(int mx) {
    n = 1; while (n < mx) n <<= 1;
    d.resize(n<<1);
  }
  void add(int a, int b, int x) { return add(a,b,x,1,0,n);}
  void add(int a, int b, int x, int i, int l, int r){
    if (a <= l && r <= b) {
      d[i].pb(x);
      return;
    }
    int c = (l+r)>>1;
    if (a < c) add(a,b,x,i<<1,l,c);
    if (c < b) add(a,b,x,i<<1|1,c,r);
  }
  void dfs(int i, B s) {
    for (int x : d[i]) {
      s |= s<<x;
    }
    ans |= s;
    if (i >= n) return;
    rep(j,2) {
      int v = i<<1|j;
      B t = s;
      dfs(v,t);
    }
  }
};
//



int main() {
  int n,q;
  scanf("%d%d",&n,&q);
  seg t(n);
  rep(qi,q) {
    int l,r,x;
    scanf("%d%d%d",&l,&r,&x);
    --l;
    t.add(l,r,x);
  }
  B s; s[0] = 1;
  t.dfs(1,s);

  vi as;
  rrep(i,n) if (ans[i]) as.pb(i);
  cout<<sz(as)<<endl;
  cout<<as<<endl;
  return 0;
}