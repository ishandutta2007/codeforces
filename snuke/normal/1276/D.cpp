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

// Mod int
const int mod = 998244353;
struct mint {
  ll x;
  mint():x(0){}
  mint(ll x):x((x%mod+mod)%mod){}
  // mint(ll x):x(x){}
  mint& fix() { x = (x%mod+mod)%mod; return *this;}
  mint operator-() const { return mint(0) - *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}
typedef vector<mint> vm;
//

struct Edge { int to, id;};
v(Edge) g[MX];

mint dp[MX];
mint ep[MX];
mint xp[MX][2];

mint dfs(int v, int pi=-1, int p=-1) {
  sort(rng(g[v]), [&](Edge& a, Edge& b) { return a.id < b.id;});
  for (Edge edge : g[v]) {
    int u = edge.to, ei = edge.id;
    if (u == p) continue;
    dfs(u,ei,v);
  }
  if (pi == -1) {
    vm d(2);
    d[0] = 1;
    for (Edge edge : g[v]) {
      int u = edge.to, ei = edge.id;
      if (u == p) continue;
      vm pd(2); swap(pd,d);
      d[0] += pd[0]*ep[u];
      d[0] += pd[0]*xp[u][1];
      d[1] += pd[1]*xp[u][0];
      d[1] += pd[1]*xp[u][1];
      d[1] += pd[0]*dp[u];
    }
    return d[0]+d[1];
  } else {
    {
      vm d(2);
      d[0] = 1;
      for (Edge edge : g[v]) {
        int u = edge.to, ei = edge.id;
        if (u == p) continue;
        vm pd(2); swap(pd,d);
        d[0] += pd[0]*ep[u];
        d[0] += pd[0]*xp[u][1];
        d[1] += pd[1]*xp[u][0];
        d[1] += pd[1]*xp[u][1];
        if (ei > pi) d[1] += pd[0]*dp[u];
      }
      dp[v] = d[0]+d[1];
    }
    {
      mint d = 1;
      for (Edge edge : g[v]) {
        int u = edge.to, ei = edge.id;
        if (u == p) continue;
        mint pd = d; d = 0;
        if (ei < pi) d += pd*ep[u];
        d += pd*xp[u][1];
        if (ei > pi) d += pd*xp[u][0];
      }
      ep[v] = d;
    }
    {
      vm d(2);
      d[0] = 1;
      for (Edge edge : g[v]) {
        int u = edge.to, ei = edge.id;
        if (u == p) continue;
        vm pd(2); swap(pd,d);
        d[0] += pd[0]*ep[u];
        d[0] += pd[0]*xp[u][1];
        d[1] += pd[1]*xp[u][0];
        d[1] += pd[1]*xp[u][1];
        d[1] += pd[0]*dp[u];
      }
      xp[v][0] = dp[v];
      xp[v][1] = d[0]+d[1]-dp[v];
    }
  }
  return 0;
}

int main() {
  int n;
  scanf("%d",&n);
  rep(i,n-1) {
    int a,b;
    scanf("%d%d",&a,&b);
    --a; --b;
    g[a].pb((Edge){b,i});
    g[b].pb((Edge){a,i});
  }
  cout<<dfs(0)<<endl;
  return 0;
}