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
const int MX = 500005;
typedef pair<int,P> Q;
typedef vector<Q> vq;

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


vi to[MX], co[MX];

int nid;
vi id,jd;
ll dep[MX];
void ofs(int v, ll nw=0) {
  dep[v] = nw;
  id[v] = nid;
  ++nid;
  rep(i,sz(to[v])) {
    int u = to[v][i];
    ll w = co[v][i];
    ofs(u,nw+w);
  }
  jd[v] = nid;
}

vq qs[MX];
vl ans;

seg t;
void dfs(int v) {
  for (Q q : qs[v]) {
    int l = q.se.fi, r = q.se.se;
    mins(ans[q.fi], dep[v]+t.get(l,r));
  }
  rep(i,sz(to[v])) {
    int u = to[v][i];
    ll w = co[v][i];
    t.add(id[u],jd[u],-w*2);
    dfs(u);
    t.add(id[u],jd[u],w*2);
  }
}

int main() {
  int n,q;
  scanf("%d%d",&n,&q);
  id = jd = vi(n);
  rep(i,n-1) {
    int p,w;
    scanf("%d%d",&p,&w);
    --p;
    to[p].pb(i+1);
    co[p].pb(w);
  }
  ofs(0);
  rep(qi,q) {
    int v,l,r;
    scanf("%d%d%d",&v,&l,&r);
    --v;
    --l;
    qs[v].pb(Q(qi,P(l,r)));
  }
  ans = vl(q,LINF);
  {
    t = seg(n+2);
    rep(i,n) {
      if (sz(to[i]) == 0) t.add(id[i],id[i]+1,dep[i]);
      else t.add(id[i],id[i]+1,LINF);
    }
    dfs(0);
  }
  rep(i,q) {
    printf("%lld\n",ans[i]);
  }
  return 0;
}