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
#define dame { puts("NO"); return 0;}
const int MX = 2005;

const int N = 16;
const int N2 = 1<<N;
const int M = 120;
typedef bitset<MX> bs;
bs dp[N2];
vi a;

int n, d;
int f(int x) {
  while (x%d == 0) x /= d;
  return x;
}
int getPrev(int s, int x) {
  rep(i,n) if (s>>i&1) {
    int ns = s^1<<i;
    int nx = x-a[i];
    if (nx >= 0 && dp[ns][nx]) return i;
  }
  return -1;
}

int main() {
  scanf("%d%d",&n,&d);
  a = vi(n);
  cin>>a;
  int n2 = 1<<n;
  dp[0][0] = 1;
  rep(s,n2) {
    drep(x,(MX-1)/d+1) if (dp[s][x*d]) dp[s][x] = 1;
    rep(i,n) if (~s>>i&1) dp[s|1<<i] |= dp[s]<<a[i];
  }
  if (!dp[n2-1][1]) dame;
  puts("YES");

  vvi es;
  {
    int s = n2-1, x = 1;
    while (s != 0 || x != 0) {
      es.pb(vi());
      int i;
      while (i = getPrev(s,x), i != -1) {
        es.back().pb(a[i]);
        s ^= 1<<i;
        x -= a[i];
      }
      x *= d;
    }
  }
  cerr<<sz(es)<<endl;
  vp ans;
  vi x;
  while (sz(es)) {
    for (int e : es.back()) x.pb(e);
    es.pop_back();
    vi nx;
    int a = 0;
    while (sz(x)) {
      int b = x.back(); x.pop_back();
      if (b%d == 0) nx.pb(b/d);
      else {
        if (a) {
          x.pb(a+b);
          ans.eb(a,b);
          a = 0;
        } else a = b;
      }
    }
    x = nx;
  }
  for (auto p : ans) {
    printf("%d %d\n",p.fi,p.se);
  }
  return 0;
}