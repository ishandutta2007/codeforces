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

int f(int a, int b) {
  ++a; ++b;
  cout<<'?'<<" "<<a<<" "<<b<<endl;
  int v;
  cin>>v;
  return v-1;
}
void answer(int v) {
  ++v;
  cout<<'!'<<" "<<v<<endl;
}


vvi to;
vi t, used;
int tfs(int v, int p=-1) {
  t[v] = 1;
  rep(i,sz(to[v])) {
    int u = to[v][i];
    if (u == p || used[u]) continue;
    t[v] += tfs(u,v);
  }
  return t[v];
}

P cfs(int v, int tot, int p=-1) {
  P res(INF,-1);
  int mx = tot-t[v];
  rep(i,sz(to[v])) {
    int u = to[v][i];
    if (u == p || used[u]) continue;
    mins(res, cfs(u,tot,v));
    maxs(mx,t[u]);
  }
  return min(res,P(mx,v));
}


vi vs;
void vfs(int v, int p=-1) {
  vs.pb(v);
  for (int u : to[v]) {
    if (u == p) continue;
    vfs(u,v);
  }
}

vi ok;
bool dfs(int v, int tv, int p=-1) {
  if (v == tv) return true;
  for (int u : to[v]) {
    if (u == p) continue;
    if (dfs(u,tv,v)) {
      ok[v] = 0;
      return true;
    }
  }
  return false;
}



int main() {
  int n;
  cin>>n;
  to = vvi(n);
  rep(i,n-1) {
    int a,b;
    scanf("%d%d",&a,&b);
    --a; --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  t = used = vi(n);
  int c = cfs(0,tfs(0)).se;
  vvi cs;
  for (int u : to[c]) {
    vfs(u,c);
    cs.pb(vs);
    vs = vi();
  }
  if (n%2 == 0) {
    cs.pb(vi(1,c));
  }
  ok = vi(n,1);
  rep(_,n/2) {
    sort(rng(cs), [&](vi& a, vi& b) { return sz(a) > sz(b);});
    vi& sa = cs[0];
    vi& sb = cs[1];
    int a = sa.back(); sa.pop_back();
    int b = sb.back(); sb.pop_back();
    int x = f(a,b);
    dfs(a,x);
    dfs(b,x);
  }
  rep(i,n) {
    if (ok[i]) answer(i);
  }
  return 0;
}