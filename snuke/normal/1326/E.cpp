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
#define eb emplace_back
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
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
inline int getInt() { int x; scanf("%d",&x); return x;}
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
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

// Starry sky tree
struct seg {
  typedef ll TT;
  vector<TT> d, e; int n;
  seg(){}
  seg(int mx) {
    n = 1; while (n < mx) n <<= 1;
    d = e = vector<TT>(n<<1);
  }
  void prop(int i) {
    int l = i<<1, r = l|1;
    d[l] += d[i]; e[l] += d[i];
    d[r] += d[i]; e[r] += d[i];
    d[i] = 0;
  }
  void add(int a, int b, TT x) { add(a,b,x,1,0,n);}
  void add(int a, int b, TT x, int i, int l, int r){
    if (a <= l && r <= b) {
      d[i] += x;
      e[i] += x;
      return;
    }
    prop(i);
    int c = (l+r)>>1;
    if (a < c) add(a,b,x,i<<1,l,c);
    if (c < b) add(a,b,x,i<<1|1,c,r);
    e[i] = min(e[i<<1],e[i<<1|1]);
  }
  TT get(int a, int b) { return get(a,b,1,0,n);}
  TT get(int a, int b, int i, int l, int r){
    if (a <= l && r <= b) return e[i];
    prop(i);
    int c = (l+r)>>1;
    TT res = LINF;
    if (a < c) mins(res,get(a,b,i<<1,l,c));
    if (c < b) mins(res,get(a,b,i<<1|1,c,r));
    return res;
  }
  int get() {
    int i = 1;
    TT s = e[i];
    while (i < n) {
      s -= d[i];
      i <<= 1;
      if (e[i] != s) ++i;
    }
    return i-n;
  }
};
//


int main() {
  int n;
  scanf("%d",&n);
  vi a(n), b(n);
  vi p(n+1);
  cin>>a>>b;
  rep(i,n) p[a[i]] = i;
  int ans = n;
  vi as(n);
  seg t(n+5);
  rep(i,n) {
    as[i] = ans;
    int x = b[i]-1;
    t.add(0,x+1,1);
    while (ans > 1) {
      int j = p[ans];
      if (t.get(0,j+1) <= 0) break;
      t.add(0,j+1,-1);
      --ans;
    }
  }
  cout<<as<<endl;
  return 0;
}