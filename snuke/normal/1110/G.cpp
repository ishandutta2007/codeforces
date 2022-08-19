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
#define dame { puts("White"); return;}
#define yn {puts("YES");}else{puts("NO");}
const int MX = 500005;

char ins[MX];

vi used;
vvi to;
vi col;

void dfs(int v, int c=0) {
  if (used[v]) return;
  used[v] = 2;
  col[v] = c;
  for (int u : to[v]) {
    dfs(u,c^1);
  }
}

void solve() {
  int n;
  scanf("%d",&n);
  to = vvi(n);
  rep(i,n-1) {
    int a,b;
    scanf("%d%d",&a,&b);
    --a; --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  scanf("%s",ins);
  int cnt = 0;
  rep(i,n) if (ins[i] == 'W') ++cnt;
  if (cnt >= 3) dame;
  if (n < 4) {
    if (n == 3) {
      if (cnt >= 2) dame;
    }
    puts("Draw");
    return;
  }
  rep(i,n) {
    if (ins[i] == 'W' && sz(to[i]) > 1) dame;
  }
  vi vs;
  rep(i,n) if (sz(to[i]) > 2) {
    if (sz(to[i]) > 3) dame;
    vs.pb(i);
  }
  if (sz(vs) > 2) dame;

  used = vi(n);
  for (int v : vs) {
    vi e;
    for (int u : to[v]) {
      if (ins[u] == 'W') dame;
      if (sz(to[u]) == 1) {
        used[u] = 1;
      } else {
        e.pb(u);
      }
    }
    if (sz(e) >= 2) dame;
    if (sz(e) == 0) {
      puts("Draw");
      return;
    }
    ins[e[0]] = 'W';
    used[v] = 1;
  }
  col = vi(n);
  rep(i,n) if (!used[i]) {
    dfs(i);
    vi c(2);
    rep(v,n) {
      if (used[v] == 2 && ins[v] == 'W') {
        c[col[v]]++;
      }
    }
    rep(j,2) if (c[j] >= 2) dame;
    break;
  }
  puts("Draw");
}

int main() {
  int ts;
  scanf("%d",&ts);
  rep(ti,ts) {
    solve();
  }
  return 0;
}