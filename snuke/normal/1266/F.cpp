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
const int MX = 500005;

vi to[MX];
int pd[MX];

int pfs(int v, int p=-1) {
  pd[v] = 0;
  for (int u : to[v]) {
    if (u == p) continue;
    maxs(pd[v], pfs(u,v));
  }
  pd[v]++;
  return pd[v];
}

vi ans;
vi d[MX];
int px[MX];
void dfs(int v, int x=-1, int p=-1) {
  px[v] = x;
  d[v].pb(0);
  if (p != -1) d[v].pb(x);
  for (int u : to[v]) {
    if (u == p) continue;
    d[v].pb(pd[u]);
  }
  sort(rrng(d[v]));
  for (int u : to[v]) {
    if (u == p) continue;
    x = d[v][0];
    if (pd[u] == x) x = d[v][1];
    dfs(u,x+1,v);
  }
  // cerr<<v<<": "<<d[v]<<endl;
}

void bfs(int v, int p=-1) {
  for (int u : to[v]) {
    if (u == p) continue;
    bfs(u,v);
  }
  
  vi ds = d[v];
  for (int u : to[v]) {
    if (u == p) continue;
    ds.insert(ds.end(),rng(d[u]));
  }
  sort(rrng(ds));
  int m = sz(ds);

  vi e(m+1);
  vi dx(m+1);
  rep(i,sz(d[v])) {
    int x = d[v][i];
    int j = upper_bound(rrng(ds),x).base()-ds.begin();
    maxs(dx[j],i);
  }
  rep(i,m) maxs(dx[i+1],dx[i]);
  for (int u : to[v]) {
    if (u == p) continue;
    rep(i,sz(d[u])-1) {
      int x = d[u][i];
      int j = upper_bound(rrng(ds),x).base()-ds.begin();
      // if (i) cerr<<x<<" "<<j<<endl;
      maxs(e[j],i);
    }
  }
  rep(i,m) maxs(e[i+1],e[i]);
  // if (v == 2) { cerr<<ds<<endl; cerr<<e<<endl; cerr<<dx<<endl;}
  drep(i,m) {
    int x = ds[i];
    int s = dx[i]+e[i];
    if (x*2 < sz(ans)) maxs(ans[x*2], s+1);
    // if (x*2 == 4 && s+1 == 4) cerr<<v<<endl;
  }

  if (p != -1) {
    d[v].erase(find(rng(d[v]),px[v]));
  }
}

int main() {
  int n;
  scanf("%d",&n);
  rep(i,n-1) {
    int a,b;
    scanf("%d%d",&a,&b);
    --a; --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  ans = vi(n+1,1);
  pfs(0);
  dfs(0);
  rep(i,n) {
    int m = sz(d[i]);
    rep(j,m) {
      {
        int x = d[i][j];
        maxs(ans[x],2);
      }
      if (j >= 1) {
        int x = d[i][j];
        if (d[i][j-1] == x) --x;
        maxs(ans[x*2+1], j+1);
      }
      if (j >= 1) {
        int x = d[i][j];
        maxs(ans[x*2], j+1);
      }
    }
    // cerr<<ans<<endl;
    // cerr<<d[i]<<endl;
  }
  drep(i,n) maxs(ans[i],ans[i+1]);
  bfs(0);
  drep(i,n-1) maxs(ans[i],ans[i+2]);
  ans.erase(ans.begin());
  cout<<ans<<endl;
  return 0;
}