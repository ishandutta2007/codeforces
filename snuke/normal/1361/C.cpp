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
typedef v(vp) vvp;

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
    d[x]--;
    if(x == y) return false;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y]+1; d[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y);}
  int size(int x) { return -d[root(x)];}
  int operator[](int x) { return root(x);}
  int operator()(int x) { return size(x);}
};
//

vvp to;
vi used;

vi es;
void dfs(int v) {
  int u = -1, ei = -1;
  while (sz(to[v])) {
    P e = to[v].back(); to[v].pop_back();
    u = e.fi; ei = e.se;
    if (!used[ei/2]) {
      used[ei/2] = 1;
      dfs(u);
      es.pb(ei);
    }
  }
}

int main() {
  int n;
  scanf("%d",&n);
  vp p(n);
  cin>>p;
  drep(k,21) {
    int n2 = 1<<k;
    int msk = bn(k);

    uf t(n2);
    vi deg(n2);
    rep(i,n) {
      int a = p[i].fi&msk;
      int b = p[i].se&msk;
      t.unite(a,b);
      deg[a] ^= 1;
      deg[b] ^= 1;
    }
    if (t.size(p[0].fi&msk) != n+1) continue;
    if (deg != vi(n2)) continue;

    to = vvp(n2);
    used = vi(n);
    vi vs;
    rep(i,n) {
      int a = p[i].fi&msk;
      int b = p[i].se&msk;
      to[a].eb(b,i*2);
      to[b].eb(a,i*2+1);
      vs.pb(a);
      vs.pb(b);
    }
    es = vi();
    dfs(p[0].fi&msk);
    if (sz(es) != n) continue;
    // if (vs[es[0]^1] != vs[es.back()]) continue;
    vi ans;
    rep(i,n) {
      ans.pb((es[i]^1)+1);
      ans.pb((es[i])+1);
    }
    cout<<k<<endl;
    cout<<ans<<endl;
    return 0;
  }
  assert(false);
  return 0;
}