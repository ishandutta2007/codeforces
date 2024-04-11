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
typedef pair<int,P> Q;
typedef vector<Q> vq;

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
  int n,m,x,y;
  scanf("%d%d%d%d",&n,&m,&x,&y);
  uf t(n);
  // vvi dp(n,vi(n,INF));
  // rep(i,n) dp[i][i] = 0;
  vvi tx(n), ty(n);
  rep(i,m) {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    --a; --b;
    if (c == x) {
      t.unite(a,b);
      // dp[a][b] = dp[b][a] = c;
      tx[a].pb(b);
      tx[b].pb(a);
    } else {
      ty[a].pb(b);
      ty[b].pb(a);
    }
  }
  // rep(k,n)rep(i,n)rep(j,n) mins(dp[i][j],dp[i][k]+dp[k][j]);
  vp ps(n);
  rep(i,n) ps[i] = P(0,i);
  rep(i,n) ps[t.root(i)].fi++;
  sort(rrng(ps));
  vi pv(n);
  m = 0;
  rep(i,n) {
    pv[ps[i].se] = i;
    if (ps[i].fi >= 4) ++m;
  }
  vi dist(n<<m,INF);
  vi px(n);
  rep(i,n) px[i] = pv[t.root(i)];
  // vvi g(n);
  // rep(i,n) g[px[i]].pb(i);
  int s = 0;
  if (px[0] < m) s = 1<<px[0];
  dist[s] = 0;
  PQ(P) q;
  q.push(P(0,s));
  int m1 = bn(m);
  while (sz(q)) {
    P nq = q.top(); q.pop();
    int d = nq.fi, v = nq.se>>m; s = nq.se&m1;
    if (dist[nq.se] != d) continue;
    d += x;
    for (int u : tx[v]) {
      int e = u<<m|s;
      int& now = dist[e];
      if (now <= d) continue;
      now = d;
      q.push(P(d,e));
    }
    d += y-x;
    for (int u : ty[v]) {
      int ng = px[u], ns = s;
      if (ng == px[v]) continue;
      if (ng < m) {
        if (s>>ng&1) continue;
        ns |= 1<<ng;
      }
      int e = u<<m|ns;
      int& now = dist[e];
      if (now <= d) continue;
      now = d;
      q.push(P(d,e));
    }
  }
  vi ans(n,INF);
  rep(i,n)rep(j,1<<m) mins(ans[i], dist[i<<m|j]);
  cout<<ans<<endl;
  return 0;
}