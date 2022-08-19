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
const int MX = 300005;

int n, m;
vi to[MX];
vi dist, pre;

void bfs() {
  dist = vi(n,INF);
  pre = vi(n,-1);
  queue<int> q;
  q.push(0);
  dist[0] = 0;
  while (sz(q)) {
    int v = q.front();
    q.pop();
    for (int u : to[v]) {
      if (dist[u] != INF) continue;
      dist[u] = dist[v]+1;
      pre[u] = v;
      q.push(u);
    }
  }
}

int main() {
  scanf("%d%d",&n,&m);
  rep(i,m) {
    int a,b;
    scanf("%d%d",&a,&b);
    --a; --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  bfs();
  vi ans(n+5);
  auto upd = [&](vi& now) {
    if (sz(ans) <= sz(now)) return;
    ans = now;
  };
  if (dist.back() != INF) {
    int v = n-1;
    vi now;
    now.pb(v);
    while (v) {
      v = pre[v];
      now.pb(v);
    }
    reverse(rng(now));
    upd(now);
  }
  bool ex = false;
  rep(i,n) {
    if (dist[i] == 2) {
      ex = true;
      vi now = {0,pre[i],i,0,n-1};
      upd(now);
      break;
    }
  }
  if (!ex) {
    vi used(n), d(n);
    rep(sv,n) {
      if (dist[sv] != 1) continue;
      if (used[sv]) continue;
      vi vs;
      bool end = false;
      {
        queue<int> q;
        q.push(sv);
        while (sz(q)) {
          int v = q.front(); q.pop();
          used[v] = 2;
          for (int u : to[v]) if (u) {
            if (used[u] == 1) continue;
            if (!used[u]) {
              used[u] = 1;
              pre[u] = v;
              q.push(u);
              continue;
            }
            d[u] = 1;
          }
          for (int u : vs) {
            if (d[u]) {
              d[u] = 0;
              continue;
            }
            vi now = {0,u,pre[v],v,u,n-1};
            upd(now);
            end = true;
            break;
          }
          if (end) break;
          vs.pb(v);
        }
      }
      if (end) break;
    }
  }
  if (sz(ans) == n+5) dame;
  for (int& as : ans) ++as;
  cout<<sz(ans)-1<<endl;
  cout<<ans<<endl;
  return 0;
}