#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
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
const int M = 100002;

// Starry sky tree
struct seg {
  vector<int> d; int n;
  seg(){}
  seg(int mx) {
    n = 1; while (n < mx) n <<= 1;
    d = vector<int>(n<<1);
  }
  void prop(int i) {
    if (!d[i]) return;
    int l = i<<1, r = l|1;
    d[l] = d[i];
    d[r] = d[i];
    d[i] = 0;
  }
  void add(int a, int b, int x) {
    add(a,b,x,1,0,n);
  }
  void add(int a, int b, int x, int i, int l, int r) {
    if (a <= l && r <= b) {
      d[i] = x;
      return;
    }
    prop(i);
    int c = (l+r)>>1;
    if (a < c) add(a,b,x,i<<1,l,c);
    if (c < b) add(a,b,x,i<<1|1,c,r);
  }
  int get(int i) {
    i += n;
    int res = 0;
    while (i) {
      if (d[i]) res = d[i];
      i >>= 1;
    }
    return res;
  }
};
//



int main() {
  int n,q;
  scanf("%d%d",&n,&q);
  vi a(n);
  rep(i,n) scanf("%d",&a[i]);
  int f = 1;
  seg t(MX);
  rep(qi,q) {
    char c; int x;
    scanf(" %c%d",&c,&x);
    x *= f;
    bool s = c=='>';
    if (f == -1) s = !s;
    if (s && x < 0) {
      ++x;
      f = -f;
      s = false;
    } else if (!s && x > 0) {
      --x;
      f = -f;
      s = true;
    }
    if (s) {
      t.add(x+1,MX,-1);
    } else {
      t.add(-x+1,MX,1);
    }
  }
  rep(i,n) {
    int x = abs(a[i]);
    int d = t.get(x);
    // cerr<<i<<" "<<x<<" "<<d<<endl;
    int ans = a[i];
    if (d) ans = x*d;
    ans *= f;
    a[i] = ans;
  }
  cout<<a<<endl;
  return 0;
}