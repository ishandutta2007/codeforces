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

// Union find
struct uf {
  vi d;
  uf(){}
  uf(int mx):d(mx,-1){}
  int root(int x) {
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y]; d[y] = x;
    return true;
  }
  int size(int x) { return -d[root(x)];}
};
//



int main() {
  int n;
  scanf("%d",&n);
  int m;
  scanf("%d",&m);
  vi a(m);
  rep(i,m) scanf("%d",&a[i]);
  uf t(m);
  int n2 = 1<<n, n1 = n2-1;
  vi d(n2,-1);
  rep(i,m) d[a[i]] = i;
  rep(i,n)rep(j,n2) if (!(j>>i&1)) maxs(d[j|1<<i],d[j]);

  vi dp(n2,-1);
  rep(i,m) {
    int x = a[i]^n1;
    if (d[x] != -1) t.unite(d[x],i);
    dp[x] = i;
  }
  rep(i,n)rep(j,n2) if (!(j>>i&1)) {
    int nj = j|1<<i;
    if (~d[j] && ~dp[j] && ~dp[nj]) t.unite(dp[j],dp[nj]);
    maxs(dp[j],dp[nj]);
  }
  
  int cnt = 0;
  rep(i,m) if (t.root(i) == i) ++cnt;
  cout<<cnt<<endl;
  return 0;
}